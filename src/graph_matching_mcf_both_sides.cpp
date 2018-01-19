
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"

using namespace LP_MP;
using namespace LP_MP::TorresaniEtAlInput;
int main(int argc, char** argv) {
MpRoundingSolver<Solver<FMC_MCF<PairwiseConstruction::BothSides>,LP,StandardTighteningVisitor>> solver(argc,argv);
solver.ReadProblem(ParseProblemMCF<Solver<FMC_MCF<PairwiseConstruction::BothSides>,LP,StandardTighteningVisitor>>);
return solver.Solve();
}