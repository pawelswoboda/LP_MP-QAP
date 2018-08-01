
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"

using namespace LP_MP;
using namespace LP_MP::TorresaniEtAlInput;
int main(int argc, char** argv) {
MpRoundingSolver<Solver<LP<FMC_MCF_T<PairwiseConstruction::BothSides>>,StandardTighteningVisitor>> solver(argc,argv);
solver.ReadProblem(parse_problem<Solver<LP<FMC_MCF_T<PairwiseConstruction::BothSides>>,StandardTighteningVisitor>>);
return solver.Solve();
}