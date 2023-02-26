
#include "informed_search.h"
#include <vector>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"
#include <algorithm>
#include "heuristic_function.h"
#include "informed_search.h"


PuzzleNode*  InformedSearch::popFringe() {
    PuzzleNode* pn = fringe.top();
    fringe.pop();
    return pn;
}

void InformedSearch::pushFringe(PuzzleNode* pn) {
    fringe.push(pn);    
}


void InformedSearch::read(std::istream &in){
    int heuristicFunction;
    in >> heuristicFunction;

    this->heuristic = (HeuristicType)(heuristicFunction -1);
    Solver::read(in);
}

void InformedSearch::init(){
    Solver::init();
    fringe = Fringe(HeuristicFunction(this, heuristic));
    fringe.push(paths.root);
}