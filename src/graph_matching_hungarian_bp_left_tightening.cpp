
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"

using namespace LP_MP;
using namespace LP_MP::TorresaniEtAlInput;
int main(int argc, char** argv) {
MpRoundingSolver<Solver<LP<FMC_HUNGARIAN_BP_T<PairwiseConstruction::Left>>,StandardTighteningVisitor>> solver(argc,argv);
solver.ReadProblem(parse_problem<Solver<LP<FMC_HUNGARIAN_BP_T<PairwiseConstruction::Left>>,StandardTighteningVisitor>>);
return solver.Solve();
}