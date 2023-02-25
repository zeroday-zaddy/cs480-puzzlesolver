#ifndef SOLVER_H
#define SOLVER_H


#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"

class Solver{

    //past states seen
    std::unordered_set<Puzzle, PuzzleHash> visited;
    
    //curren states observing
    std::list<PuzzleNode*> fringe;

    Puzzle start;
    Puzzle goal;

    //null pointer for unsolved
    PuzzleNode* goalNode = 0;
    //the solution tree
    PuzzleTree paths; 

    //for debugging
    int currentLevel = -1;

public:
    //type of search to use
    enum SearchType {BFS, DFS};
    SearchType search;

    //start stae to end state
    Solver(Puzzle start, Puzzle goal)
    : start(start), goal(goal), search(BFS){
        visited.reserve(9*8*7*6*5*4*3*2*1);
        paths.root = new PuzzleNode(new Puzzle{start});
        //shouldnt reach load balance of over .5 often
        
        visited.insert(*(paths.root->value));
        fringe.push_back(paths.root);
    }

    //for debugging
    std::pair<Puzzle,Puzzle> getStartAndGoal(){ return {start, goal}; }

    //observe possible  solution step by step
    void step();

    //based on given state and move genereate the nexr node
    PuzzleNode*  generateMove(PuzzleNode* pn, Puzzle::Move move);

    //if this node contains goal state then set goalNode to it
    void setIfGoal(PuzzleNode* pn);

    //checks if goalNode has been set
    bool goalFound();

    //prints solution path from start state to given node
    std::list<Puzzle*> retrace(PuzzleNode* pn);
    
    //logic to switch between BFS or DFS
    PuzzleNode*  popFringe();
    void pushFringe(PuzzleNode* pn);
};

#endif