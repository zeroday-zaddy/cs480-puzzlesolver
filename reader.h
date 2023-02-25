#ifndef READER_H
#define READER_H


#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "solver.h"
#include "puzzle.h"


/**
 * read 1st two number are wXh dimensions
 * next number is the type 1 = BFS, 2 = DFS
 * The next numbers are the tiles from left to right top to bottom 
 * with -1 as the blank
*/
class PuzzleReader{

public:
    static Solver read(std::istream& in){
        
        int w, h;
        in >> w;
        in >> h;
        int type;
        in >> type;

        std::vector<int> board (w*h, 0);
        for(int i = 0; i <  board.size(); i++){
            in >> board[i];
        }
        Puzzle start {board, w, h};

        for(int i = 0; i <  board.size(); i++){
            in >> board[i];
        }
        Puzzle goal {board, w, h};

        Solver solver {start,goal};
        if(type == 2) solver.search = solver.DFS;
        return solver;
    }
};

#endif