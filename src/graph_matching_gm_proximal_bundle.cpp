#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"
#include "tree_decomposition.hxx"

using namespace LP_MP;
using SolverType = Solver<FMC_GM<PairwiseConstruction::Left>,LP_FW_TR,StandardVisitor>;

int main(int argc, char* argv[])
{
SolverType solver(argc,argv);
solver.ReadProblem(TorresaniEtAlInput::ParseProblemGM_trees<SolverType>);
return solver.Solve();
}

