
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"
#include "LP_BCFW-Bundle.hxx"

using namespace LP_MP;
using namespace LP_MP::TorresaniEtAlInput;
int main(int argc, char** argv) {
MpRoundingSolver<Solver<FMC_MCF<PairwiseConstruction::Left>,LP_BCFW_Bundle,StandardTighteningVisitor>> solver(argc,argv);
solver.ReadProblem(ParseProblemMCF_trees<Solver<FMC_MCF<PairwiseConstruction::Left>,LP_BCFW_Bundle,StandardTighteningVisitor>>);
return solver.Solve();
}