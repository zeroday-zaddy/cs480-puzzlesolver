
#include "uniform_cost_search.h"
#include <vector>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"
#include <algorithm>


PuzzleNode*  UniformCostSearch::popFringe()  {
    PuzzleNode* pn = fringe.front();
    fringe.pop_front();
    return pn;
}

void UniformCostSearch::pushFringe(PuzzleNode* pn) {
    if(search == BFS){
        fringe.push_back(pn);                                   
    }else{
        fringe.push_front(pn);   
    }
}


void UniformCostSearch::read(std::istream &in){
    std::string searchstring;
    in >> searchstring;

    SearchType type = (SearchType)((searchstring == "DFS") ? 1 : 0);
    this->search = type;
    Solver::read(in);
}

void UniformCostSearch::init(){
    Solver::init();
    fringe.push_back(paths.root);
}