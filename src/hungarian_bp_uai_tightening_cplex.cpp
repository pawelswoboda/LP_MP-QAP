#include "graph_matching.h"
#include "lp_interface/lp_cplex.hxx"
#include "visitors/standard_visitor.hxx"
using FMC_INST = FMC_HUNGARIAN_BP_T<PairwiseConstruction::Left>;
LP_MP_CONSTRUCT_SOLVER_WITH_INPUT_AND_VISITOR_LP(FMC_INST, UaiGraphMatchingInput::ParseProblemHungarian<FMC_INST>, StandardTighteningVisitor, LpInterfaceCplex);
