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

    UniformCostSearch():Solver(){};
    UniformCostSearch(const UniformCostSearch& u)
    :Solver(u.start,u.goal), search(u.search){};
    //start stae to end state
    UniformCostSearch(Puzzle start, Puzzle goal, SearchType search = BFS)
    :Solver(start,goal), search(search){ }

    //logic to switch between BFS or DFS
    PuzzleNode*  popFringe() override;
    void pushFringe(PuzzleNode* pn) override;

    void read(std::istream &in);

    Solver* clone() const{
        return new UniformCostSearch(*this);
    }

    void init() override;
};

#endif