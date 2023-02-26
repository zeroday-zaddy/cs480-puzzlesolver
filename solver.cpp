#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"
#include "solver.h"

Solver::Solver(Puzzle start, Puzzle goal)
    : start(start), goal(goal)
{

}
void Solver::init(){
    visited.reserve(9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1);
    paths.root = new PuzzleNode(new Puzzle{start});
    // shouldnt reach load balance of over .5 often

    visited.insert(*(paths.root->value));
}

// observe possible  solution step by step
void Solver::step()
{
    PuzzleNode *pn = popFringe();

    if (pn->level > currentLevel)
    {
        currentLevel = pn->level;
        // std::cout << "Current Level: " << currentLevel << std::endl;
    }
    visited.insert(*(pn->value));

    if (!goalFound())
        setIfGoal(generateMove(pn, Puzzle::up));
    if (!goalFound())
        setIfGoal(generateMove(pn, Puzzle::right));
    if (!goalFound())
        setIfGoal(generateMove(pn, Puzzle::down));
    if (!goalFound())
        setIfGoal(generateMove(pn, Puzzle::left));

    if (goalFound())
    {
        std::list<Puzzle *> path = retrace(goalNode);
        for (auto pn : path)
        {
            std::cout << *pn << std::endl;
        }
    }
}

// based on given state and move genereate the nexr node
PuzzleNode* Solver::generateMove(PuzzleNode *pn, Puzzle::Move move)
{
    Puzzle *valuepointer = pn->value;
    if (valuepointer->canMove(move))
    {
        Puzzle *newp = new Puzzle(*valuepointer);
        newp->move(move);

        if (visited.find(*newp) == visited.end())
        {
            pn->children[move] = new PuzzleNode(newp);
            pn->children[move]->parent = pn;
            pn->children[move]->level = pn->level + 1;

            visited.insert(*(pn->children[move]->value));
            pushFringe(pn->children[move]);
            // fringe.push_back(pn->children[move]);
        }
        else
        {
            delete newp;
        }

        return pn->children[move];
    }
    return 0;
}

// if this node contains goal state then set goalNode to it
void Solver::setIfGoal(PuzzleNode *pn)
{
    if (pn == 0)
        return;

    if (goal == *(pn->value))
    {
        goalNode = pn;
    }
}

// prints solution path from start state to given node
std::list<Puzzle*> Solver::retrace(PuzzleNode *pn)
{
    std::list<Puzzle*> path;

    PuzzleNode *curr = pn;
    while (curr != 0)
    {
        path.push_front(curr->value);
        curr = curr->parent;
        // std::cout << *pn->value;
    }
    return path;
}



void Solver::read(std::istream &in){
    int w, h;
    in >> w;
    in >> h;
    std::vector<int> board (w*h, 0);
    for(int i = 0; i <  board.size(); i++){
        in >> board[i];
    }
    Puzzle start {board, w, h};

    for(int i = 0; i <  board.size(); i++){
        in >> board[i];
    }
    Puzzle goal {board, w, h};
    this->start =start;
    this->goal = goal;
}