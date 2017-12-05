#include "graph_matching.h"
#include "lp_interface/lp_gurobi.hxx"
#include "visitors/standard_visitor.hxx"
using FMC_INST = FMC_HUNGARIAN_BP_T<PairwiseConstruction::Right>;
LP_MP_CONSTRUCT_SOLVER_WITH_INPUT_AND_VISITOR_LP(FMC_INST, TorresaniEtAlInput::ParseProblemHungarian<FMC_INST>, StandardTighteningVisitor, LpInterfaceGurobi);

