
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"
#include "LP_FWMAP.hxx"

using namespace LP_MP;
using namespace LP_MP::TorresaniEtAlInput;
int main(int argc, char** argv) {
MpRoundingSolver<Solver<LP_tree_FWMAP<FMC_LOCAL_SUBPROBLEM<PairwiseConstruction::Left>>,StandardTighteningVisitor>> solver(argc,argv);
solver.ReadProblem(ParseProblemLocalSubproblems_trees<Solver<LP_tree_FWMAP<FMC_LOCAL_SUBPROBLEM<PairwiseConstruction::Left>>,StandardTighteningVisitor>>);
return solver.Solve();
}