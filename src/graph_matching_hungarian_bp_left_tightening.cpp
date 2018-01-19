
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"

using namespace LP_MP;
using namespace LP_MP::TorresaniEtAlInput;
int main(int argc, char** argv) {
MpRoundingSolver<Solver<FMC_HUNGARIAN_BP_T<PairwiseConstruction::Left>,LP,StandardTighteningVisitor>> solver(argc,argv);
solver.ReadProblem(ParseProblemHungarian<Solver<FMC_HUNGARIAN_BP_T<PairwiseConstruction::Left>,LP,StandardTighteningVisitor>>);
return solver.Solve();
}