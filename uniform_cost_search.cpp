
#include "uniform_cost_search.h"
#include <vector>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"
#include <algorithm>


PuzzleNode*  UniformCostSearch::popFringe()  {
    // PuzzleNode* pn;
    // if(search == BFS){
    //     pn = fringe.front();
    //     fringe.pop_front();                                    
    // }else{
    //     pn = fringe.back();
    //     fringe.pop_back();    
    // }
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