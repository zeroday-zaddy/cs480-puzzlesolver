#include "heuristic_function.h"
#include <algorithm>
#include <iterator>
#include "point.h"
bool HeuristicFunction::operator()(const PuzzleNode *left, const PuzzleNode *right) const
{
    const Puzzle &goal = solver->getStartAndGoal().second;
    return compare(left->value, right->value, &goal);
}

bool HeuristicFunction::compare(const Puzzle *left, const Puzzle *right, const Puzzle *goal) const
{

    bool leftBetterHeuristic = false;
    switch (heuristic)
    {
    case HeuristicType::h1:
        leftBetterHeuristic = h1f(left, goal) <= h1f(right, goal);
        break;
    case HeuristicType::h2:
        leftBetterHeuristic =  h2f(left, goal) <= h2f(right, goal);
        break;
    case HeuristicType::h3:
        leftBetterHeuristic =  h3f(left, goal) >= h3f(right, goal);
        break;
    case HeuristicType::h4:
        int l = h1f(left, goal) + h2f(left, goal);
        int r = h1f(right, goal) + h2f(right, goal);
        leftBetterHeuristic =  l <= r;
        break;
    }
    //priorty queues puts higher elements first so have to flip this
    return !leftBetterHeuristic;
}

//tiles misplaced
int HeuristicFunction::h1f(const Puzzle *puzzle, const Puzzle *goal) const
{
    int x = 0;
    for (size_t i = 0; i < puzzle->slots.size(); i++)
    {
        if ((*puzzle)[i] != (*goal)[i])
            x++;
    }
    return x;
}

//sum of distances to correct tile
int HeuristicFunction::h2f(const Puzzle *puzzle, const Puzzle *goal) const
{
    int x = 0;
    for (size_t i = 0; i < puzzle->slots.size(); i++)
    {
        int puzzleValue = (*puzzle)[i];

        auto gItr = std::find(goal->slots.begin(), goal->slots.end(), puzzleValue);
        int gIndex = std::distance(goal->slots.begin(), gItr);

        Point puzzlePoint(i, puzzle->width);
        Point goalPoint(gIndex, goal->width);

        x += abs(puzzlePoint.x - goalPoint.x) + abs(puzzlePoint.y - goalPoint.y);
    }
    return x;
}

//number of direct swaps
int HeuristicFunction::h3f(const Puzzle *puzzle, const Puzzle *goal) const
{

    std::vector<int> goalTileToPos(goal->slots.size());
    for(int i = 0; i < goalTileToPos.size(); i++){
        goalTileToPos[(*goal)[i]] = i;
    }
    int x = 0;
    for (size_t i = 0; i < puzzle->slots.size(); i++)
    {
        int puzzleValue = (*puzzle)[i];

        // auto gItr = std::find(goal->slots.begin(), goal->slots.end(), puzzleValue);
        // int gIndex = std::distance(goal->slots.begin(), gItr);

        int gIndex = goalTileToPos[puzzleValue];

        Point puzzlePoint(i, puzzle->width);
        Point pzUp = puzzlePoint;
        pzUp.y -= 1;
        Point pzDown = puzzlePoint;
        pzDown.y += 1;
        Point pzLeft = puzzlePoint;
        pzLeft.x -= 1;
        Point pzRight = puzzlePoint;
        pzRight.x += 1;

        Point goalPoint(gIndex, goal->width);

        Point adjPoint {-1,-1};

        if (puzzlePoint == goalPoint)
            adjPoint = puzzlePoint;
        if (pzUp == goalPoint)
            adjPoint = pzUp;
        else if (pzDown == goalPoint)
            adjPoint = pzDown;
        else if (pzLeft == goalPoint)
            adjPoint = pzLeft;
        else if (pzRight == goalPoint)
            adjPoint = pzRight;

        int w = goal->width;
        if (adjPoint.x > -1 && adjPoint.x < w)
        {
            int j = puzzlePoint.flatten(w);
            int j2 = adjPoint.flatten(w);
            int goalWithCurrentPos = goal->slots[j];
            int puzzleWithAdjPos = puzzle->slots[j2];
            if (goalWithCurrentPos == puzzleWithAdjPos)
            {
                x += 1;
            }
        }
    }
    return x;
}
