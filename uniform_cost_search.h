#ifndef UNIFORM_COST_SEARCH_H
#define UNIFORM_COST_SEARCH_H


#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"
#include "solver.h"

class UniformCostSearch: public Solver{

    //current states observing
    std::list<PuzzleNode*> fringe;

public:
    //type of search to use
    enum SearchType {BFS, DFS};
    SearchType search;

    //start stae to end state
    UniformCostSearch(Puzzle start, Puzzle goal)
    :Solver(start,goal){
        fringe.push_back(paths.root);
    }

    //logic to switch between BFS or DFS
    PuzzleNode*  popFringe() override;
    void pushFringe(PuzzleNode* pn) override;
};

#endif