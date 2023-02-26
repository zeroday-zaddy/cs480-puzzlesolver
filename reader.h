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
};
std::istream& operator>>(std::istream& ins, Solver*& rd);
#endif