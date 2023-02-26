#include <string>
#include <vector>
#include "reader.h"
#include "puzzle.h"
#include "uniform_cost_search.h"
#include "informed_search.h"
#include <fstream>
int main(int argc, char** argv){
    
    std::ifstream ifs ("puzzle.in");
    Solver* solver = PuzzleReader::read<InformedSearch>(ifs);

    //solver.search = solver.DFS;
    auto startgoal = solver->getStartAndGoal(); 
    //std::cout << p;

    // p.moveUp();
    
    // std::cout << p;

    std::cout << "start\n" << startgoal.first; 
    std::cout << "\ngoal\n" << startgoal.second << "\n\nsteps\n"; 

    while(!solver->goalFound()){
        solver->step();
    };
    //PuzzleReader::deleteSolver(solver);
    delete solver;
    return 0;
}