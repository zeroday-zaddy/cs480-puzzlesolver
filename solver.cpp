
#include "solver.h"
#include <vector>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"
#include <algorithm>

void Solver::step(){
    PuzzleNode* pn = popFringe();

    if(pn->level > currentLevel) {
        currentLevel = pn->level;
        //std::cout << "Current Level: " << currentLevel << std::endl;
    }
    visited.insert(*(pn->value));

    if(!goalFound()) setIfGoal(generateMove(pn, Puzzle::up));
    if(!goalFound()) setIfGoal(generateMove(pn, Puzzle::right));
    if(!goalFound()) setIfGoal(generateMove(pn, Puzzle::down));
    if(!goalFound()) setIfGoal(generateMove(pn, Puzzle::left));

    if(goalFound()){
        std::list<Puzzle*> path = retrace(goalNode);
        for(auto pn : path){
            std::cout << *pn << std::endl;
        }
    }
}



PuzzleNode* Solver::generateMove(PuzzleNode* pn, Puzzle::Move move){
    Puzzle* valuepointer = pn->value;
    if(valuepointer->canMove(move)){
        Puzzle* newp = new Puzzle(*valuepointer);
        newp->move(move);

        if(visited.find(*newp) == visited.end()){
            pn->children[move] = new PuzzleNode(newp);
            pn->children[move]->parent = pn;
            pn->children[move]->level = pn->level+1;
            
            visited.insert(*(pn->children[move]->value));
            pushFringe(pn->children[move]);
            //fringe.push_back(pn->children[move]);
        }else{
            delete newp;
        }

        return pn->children[move];
    }
    return 0;
}

void Solver::setIfGoal(PuzzleNode* pn){
    if(pn == 0) return;

    if(goal == *(pn->value)){
        goalNode = pn;
    }
}

bool Solver::goalFound(){
    return goalNode != 0;
}

std::list<Puzzle*> Solver::retrace(PuzzleNode* pn){
    std::list<Puzzle*> path;

    PuzzleNode* curr = pn;
    while(curr != 0){
        path.push_front(curr->value);
        curr = curr->parent;
        //std::cout << *pn->value;
    }
    return path;
}


PuzzleNode*  Solver::popFringe(){
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

void Solver::pushFringe(PuzzleNode* pn){
    if(search == BFS){
        fringe.push_back(pn);                                   
    }else{
        fringe.push_front(pn);   
    }
}