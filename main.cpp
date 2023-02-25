#include <string>
#include <vector>
#include "reader.h"
#include "puzzle.h"
#include "solver.h"
#include <fstream>
int main(int argc, char** argv){
    
    std::ifstream ifs ("puzzle.in");
    Solver solver = PuzzleReader::read(ifs);
    solver.search = solver.DFS;
    auto startgoal = solver.getStartAndGoal(); 
    //std::cout << p;

    // p.moveUp();
    
    // std::cout << p;

    std::cout << "start\n" << startgoal.first; 
    std::cout << "\ngoal\n" << startgoal.second << "\n\nsteps\n"; 

    while(!solver.goalFound()){
        solver.step();
    }
    return 0;
}