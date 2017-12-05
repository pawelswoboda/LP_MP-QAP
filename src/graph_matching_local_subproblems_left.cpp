#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"
#include "LP_BCFW-Bundle.hxx"

// do zrobienia: indicate that BCFW-Bundle is LP-solver

using namespace LP_MP;
using SolverType = Solver<FMC_LOCAL_SUBPROBLEM<PairwiseConstruction::Left>,LP_BCFW_Bundle,StandardVisitor>;

int main(int argc, char* argv[])
{
SolverType solver(argc,argv);
solver.ReadProblem(TorresaniEtAlInput::ParseProblemLocalSubproblems_trees<SolverType>);
return solver.Solve();
}

