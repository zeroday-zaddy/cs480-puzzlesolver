#ifndef READER_H
#define READER_H


#include <vector>
#include <list>
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

class SolverFactory{
    using SolverPair = std::pair<std::string, std::unique_ptr<Solver>>;
    static SolverPair _known_solvers[];
public:
    
    static Solver* createSolver(std::string name);

    static bool isKnown(std::string name);

    static void listKnown(std::ostream &outs);
    
    static int numberKnown();

    // static std::list<Solver*> solvers;
    // template <class S>
    // static Solver* read(std::istream& in){
    //     int w, h;
    //     in >> w;
    //     in >> h;
    //     std::string type;
    //     in >> type;

    //     std::vector<int> board (w*h, 0);
    //     for(int i = 0; i <  board.size(); i++){
    //         in >> board[i];
    //     }
    //     Puzzle start {board, w, h};

    //     for(int i = 0; i <  board.size(); i++){
    //         in >> board[i];
    //     }
    //     Puzzle goal {board, w, h};

    //     Solver* solver = new S{start,goal};
        
    //     return solver;//need to make better factory class
    // }
    // static bool deleteSolver(Solver* solver){
    //     auto pos = std::find(solvers.begin(), solvers.end(), solver);
    //     if(pos != solvers.end()){
    //         delete solver;
    //         solvers.erase(pos);
    //     }
    //     return pos != solvers.end();
    // }
};
std::istream& operator>>(std::istream& ins, Solver*& rd);
#endif