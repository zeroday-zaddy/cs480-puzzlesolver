#ifndef PUZZLE_TREE_H
#define PUZZLE_TREE_H

#include "puzzle.h"
#include <vector>

struct PuzzleNode{
    PuzzleNode* parent;
    std::vector<PuzzleNode*> children;

    Puzzle* value;

    int level;
    PuzzleNode(Puzzle* value)
    : value(value){
        children.resize(4,0);
        parent = 0;
        value = 0;
        level = 0;
    }
};


class PuzzleTree{
public:
    PuzzleNode* root;

    PuzzleTree()
    :  root(0){}
};

#endif