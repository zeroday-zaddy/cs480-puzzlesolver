
#include "informed_search.h"
#include <vector>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"
#include <algorithm>
#include "heuristic_function.h"
#include "informed_search.h"


// start state to end state
InformedSearch::InformedSearch(Puzzle start, Puzzle goal, HeuristicType heuristic)
    : Solver(start, goal), fringe(HeuristicFunction(this, heuristic)){
    fringe.push(paths.root);
}

PuzzleNode*  InformedSearch::popFringe() {
    PuzzleNode* pn = fringe.top();
    fringe.pop();
    return pn;
}

void InformedSearch::pushFringe(PuzzleNode* pn) {
    fringe.push(pn);    
}