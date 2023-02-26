#include "reader.h"
#include "uniform_cost_search.h"
#include "informed_search.h"
SolverFactory::SolverPair SolverFactory::_known_solvers[] = {
    {"Uniform", std::unique_ptr<Solver>(new UniformCostSearch())}, 
    {"Informed", std::unique_ptr<Solver>(new InformedSearch())} 
};

Solver* SolverFactory::createSolver(std::string name)
{
    for (const SolverPair& pair : _known_solvers) {
        if (pair.first == name) {
            return pair.second->clone();
        }
    }

    // A shape with the given name could not be found
    return nullptr;
}

bool SolverFactory::isKnown(std::string name)
{
    for (const SolverPair& pair : _known_solvers) {
        if (pair.first == name) {
            return true;
        }
    }

    // The shape with the given name is unknown
    return false;
}

void SolverFactory::listKnown(std::ostream &outs)
{
    for (const SolverPair& pair : _known_solvers) {
        outs << " " << pair.first << "\n";
    }
}

int SolverFactory::numberKnown()
{
    /*
    int count = 0;
    for (const ShapePair& pair : _known_shapes) {
        count++;
    }
    */
    return (end(_known_solvers) - begin(_known_solvers));
}

std::istream& operator>>(std::istream& ins, Solver*& rd)
{
    std::string     name;

    // Read name (key) and create the appropriate Shape
    getline(ins, name, ';');
    rd = SolverFactory::createSolver(name);

    if (rd != nullptr) {
        // Do other stuff
        rd->read(ins);
    }
    else {
        // throw away the rest of the line
        getline(ins, name,'_');
    }

    return ins;
}