#include "heuristic_function.h"
#include <algorithm>
#include <iterator>
#include "point.h"
bool HeuristicFunction::operator()(const PuzzleNode *left, const PuzzleNode *right) const
{
    const Puzzle& goal = solver->getStartAndGoal().second;
    return  compare(left->value, right->value, &goal); 
}


bool HeuristicFunction::compare(const Puzzle *left, const Puzzle *right,  const Puzzle *goal) const
{
    switch(heuristic){
        case HeuristicType::h1:
            return h1f(left, goal) < h1f(right, goal);
        break;
        case HeuristicType::h2:
            return h2f(left, goal) < h2f(right, goal);
        break;
        case HeuristicType::h3:
        break;
        case HeuristicType::h4:
        break;
    }
    return false;
}


int HeuristicFunction::h1f(const Puzzle *puzzle, const Puzzle *goal) const{
    int x = 0;
    for (size_t i = 0; i < puzzle->slots.size(); i++)
    {
        if ((*puzzle)[i] != (*goal)[i])
            x++;
    }
    return x;
}

int HeuristicFunction::h2f(const Puzzle *puzzle, const Puzzle *goal) const{
    int x = 0;
    for (size_t i = 0; i < puzzle->slots.size(); i++)
    {
        int puzzleValue = (*puzzle)[i];

        auto gItr = std::find(goal->slots.begin(), goal->slots.end(), puzzleValue);
        int gIndex = std::distance(goal->slots.begin(), gItr);

        Point puzzlePoint (i, puzzle->width);
        Point goalPoint (gIndex, goal->width);

        x += abs(puzzlePoint.x - goalPoint.x) + abs(puzzlePoint.y - goalPoint.y);
    }
    return x;
}


