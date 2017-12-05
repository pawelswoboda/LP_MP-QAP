#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"
#include "LP_conic_bundle.hxx"

using namespace LP_MP;
using SolverType = Solver<FMC_MCF<PairwiseConstruction::Left>,LP_conic_bundle,StandardVisitor>;

int main(int argc, char* argv[])
{
SolverType solver(argc,argv);
solver.ReadProblem(TorresaniEtAlInput::ParseProblemMCF_trees<SolverType>);
return solver.Solve();
}

