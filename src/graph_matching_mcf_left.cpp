
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"

using namespace LP_MP;
using namespace LP_MP::TorresaniEtAlInput;
int main(int argc, char** argv) {
MpRoundingSolver<Solver<LP<FMC_MCF<PairwiseConstruction::Left>>,StandardTighteningVisitor>> solver(argc,argv);
solver.ReadProblem(ParseProblemMCF<Solver<LP<FMC_MCF<PairwiseConstruction::Left>>,StandardTighteningVisitor>>);
return solver.Solve();
}