
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"

using namespace LP_MP;
using namespace LP_MP::TorresaniEtAlInput;
int main(int argc, char** argv) {
MpRoundingSolver<Solver<LP<FMC_MP_T<PairwiseConstruction::Right>>,StandardTighteningVisitor>> solver(argc,argv);
solver.ReadProblem(ParseProblemMP<Solver<LP<FMC_MP_T<PairwiseConstruction::Right>>,StandardTighteningVisitor>>);
return solver.Solve();
}