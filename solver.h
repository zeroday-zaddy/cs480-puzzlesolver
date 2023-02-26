#ifndef SOLVER_H
#define SOLVER_H


#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include "puzzle.h"
#include "puzzle_tree.h"

class Solver{
protected:
    //past states seen
    std::unordered_set<Puzzle, PuzzleHash> visited;

     Puzzle start;
     Puzzle goal;

    //null pointer for unsolved
    PuzzleNode* goalNode = 0;
    //the solution tree
    PuzzleTree paths; 

    //for debugging
    int currentLevel = -1;

public:

    //start state to end state
    Solver(Puzzle start, Puzzle goal);
    virtual ~Solver() {
        std::queue<PuzzleNode*> nodes;
        nodes.push(paths.root);
        while(!nodes.empty()){
            PuzzleNode* n = nodes.front();
            nodes.pop();
            if(n == 0) continue;
            for(int i = 0; i < 4; i++){
                nodes.push(n->children[i]);
            }
            delete n->value;
            delete n;
        }
    };

    //for debugging
    std::pair<const Puzzle&, const Puzzle&> getStartAndGoal() const { return {start, goal}; }

    //observe possible  solution step by step
    void step();

    //based on given state and move genereate the nexr node
    PuzzleNode*  generateMove(PuzzleNode* pn, Puzzle::Move move);

    //if this node contains goal state then set goalNode to it
    void setIfGoal(PuzzleNode* pn);

    //checks if goalNode has been set
    bool goalFound(){
        return goalNode != 0;
    }

    //prints solution path from start state to given node
    std::list<Puzzle*> retrace(PuzzleNode* pn);
    
    virtual PuzzleNode*  popFringe() = 0;
    virtual void pushFringe(PuzzleNode* pn) = 0;
};

#endif