#ifndef INFORMED_SEARCH_H
#define INFORMED_SEARCH_H

#include "heuristic_function.h"
#include <unordered_set>
#include "puzzle.h"
#include "puzzle_tree.h"
class InformedSearch : public Solver
{

    // current states observing
    typedef std::priority_queue<PuzzleNode *, std::vector<PuzzleNode *>, HeuristicFunction> Fringe;
    Fringe fringe;
    HeuristicType heuristic;

public:
    InformedSearch() : Solver(){};
    InformedSearch(const InformedSearch &i)
        : InformedSearch(i.start, i.goal, i.heuristic){};
    // start state to end state
    InformedSearch(Puzzle start, Puzzle goal, HeuristicType heuristic = h1)
        : Solver(start, goal),
          heuristic(heuristic), fringe(HeuristicFunction(this, heuristic))
    { }
    // logic to switch between BFS or DFS
    PuzzleNode *popFringe() override;
    void pushFringe(PuzzleNode *pn) override;

    void read(std::istream &in);

    Solver *clone() const override
    {
        return new InformedSearch(*this);
    }

    void init() override;
};

#endif