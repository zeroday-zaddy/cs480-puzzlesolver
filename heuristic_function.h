#ifndef HEURISTIC_FUNCTION_H
#define HEURISTIC_FUNCTION_H

#include "heuristic_function.h"
#include <unordered_set>
#include <stack>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"
#include "solver.h"


enum HeuristicType
{
    h1,
    h2,
    h3,
    h4
};

class HeuristicFunction
{
    const Solver *solver;

public:
    // type of heurestic to use
    HeuristicType heuristic;

    HeuristicFunction()
        : HeuristicFunction(0) {}
    HeuristicFunction(Solver *solver, HeuristicType heuristic = h1 )
        : solver(solver), heuristic(heuristic){}

    bool operator()(const PuzzleNode *left, const PuzzleNode *right) const;

    bool compare(const Puzzle *left, const Puzzle *right, const Puzzle *goal) const;

    int h1f(const Puzzle *puzzle, const Puzzle *goal) const;
    int h2f(const Puzzle *puzzle, const Puzzle *goal) const;
    int h3f(const Puzzle *puzzle, const Puzzle *goal) const;
    int h4f(const Puzzle *puzzle, const Puzzle *goal) const;
};

#endif