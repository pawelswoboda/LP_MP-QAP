#!/usr/bin/python

from collections import namedtuple
solver = namedtuple("solver_info", "preamble FMC LP parse_fun filename")

preamble_mp = """
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"
"""

preamble_BCFW = """
#include "graph_matching.h"
#include "visitors/standard_visitor.hxx"
#include "LP_BCFW-Bundle.hxx"
"""

solvers = [
    solver(preamble_mp, 'FMC_MCF<PairwiseConstruction::Left>', 'LP', 'ParseProblemMCF', "graph_matching_mcf_left.cpp"),
    solver(preamble_mp, 'FMC_MCF<PairwiseConstruction::Right>', 'LP', 'ParseProblemMCF',"graph_matching_mcf_right.cpp"),
    solver(preamble_mp, 'FMC_MCF<PairwiseConstruction::BothSides>', 'LP', 'ParseProblemMCF',"graph_matching_mcf_both_sides.cpp"),
    solver(preamble_mp, 'FMC_MP<PairwiseConstruction::Left>', 'LP', 'ParseProblemMP', "graph_matching_mp_left.cpp"),
    solver(preamble_mp, 'FMC_MP<PairwiseConstruction::Right>', 'LP', 'ParseProblemMP', "graph_matching_mp_right.cpp"),
    solver(preamble_mp, 'FMC_MP<PairwiseConstruction::Left>', 'LP', 'ParseProblemMP', "graph_matching_mp_both_sides.cpp"),
    solver(preamble_mp, 'FMC_GM<PairwiseConstruction::Left>', 'LP', 'ParseProblemGM', "graph_matching_gm_left.cpp"),
    solver(preamble_mp, 'FMC_GM<PairwiseConstruction::Right>', 'LP', 'ParseProblemGM', "graph_matching_gm_right.cpp"),
    solver(preamble_mp, 'FMC_HUNGARIAN_BP<PairwiseConstruction::Left>', 'LP', 'ParseProblemHungarian', "graph_matching_hungarian_bp_left.cpp"),
    solver(preamble_mp, 'FMC_HUNGARIAN_BP<PairwiseConstruction::Right>', 'LP', 'ParseProblemHungarian', "graph_matching_hungarian_bp_right.cpp"),
    solver(preamble_mp, 'FMC_HUNGARIAN_BP<PairwiseConstruction::BothSides>', 'LP', 'ParseProblemHungarian', "graph_matching_hungarian_bp_both_sides.cpp"),
    solver(preamble_mp, 'FMC_MCF_T<PairwiseConstruction::Left>', 'LP', 'ParseProblemMCF', "graph_matching_mcf_left_tightening.cpp.cpp"),
    solver(preamble_mp, 'FMC_MCF_T<PairwiseConstruction::Right>', 'LP', 'ParseProblemMCF', "graph_matching_mcf_right_tightening.cpp.cpp"),
    solver(preamble_mp, 'FMC_MCF_T<PairwiseConstruction::BothSides>', 'LP', 'ParseProblemMCF', "graph_matching_mcf_both_sides_tightening.cpp"),
    solver(preamble_mp, 'FMC_MP_T<PairwiseConstruction::Left>', 'LP', 'ParseProblemMP', "graph_matching_mp_left_tightening.cpp"),
    solver(preamble_mp, 'FMC_MP_T<PairwiseConstruction::Right>', 'LP', 'ParseProblemMP', "graph_matching_mp_right_tightening.cpp"),
    solver(preamble_mp, 'FMC_MP_T<PairwiseConstruction::Left>', 'LP', 'ParseProblemMP', "graph_matching_mp_both_sides_tightening.cpp"),
    solver(preamble_mp, 'FMC_GM_T<PairwiseConstruction::Left>', 'LP', 'ParseProblemGM', "graph_matching_gm_left_tightening.cpp"),
    solver(preamble_mp, 'FMC_GM_T<PairwiseConstruction::Right>', 'LP', 'ParseProblemGM', "graph_matching_gm_right_tightening.cpp"),
    solver(preamble_mp, 'FMC_HUNGARIAN_BP_T<PairwiseConstruction::Left>', 'LP', 'ParseProblemHungarian', "graph_matching_hungarian_bp_left_tightening.cpp"),
    solver(preamble_mp, 'FMC_HUNGARIAN_BP_T<PairwiseConstruction::Right>', 'LP', 'ParseProblemHungarian', "graph_matching_hungarian_bp_right_tightening.cpp"),
    solver(preamble_mp, 'FMC_HUNGARIAN_BP_T<PairwiseConstruction::BothSides>', 'LP', 'ParseProblemHungarian', "graph_matching_hungarian_bp_both_sides_tightening.cpp"),
    solver(preamble_BCFW, 'FMC_MCF<PairwiseConstruction::Left>', 'LP_BCFW_Bundle', 'ParseProblemMCF_trees', "graph_matching_mcf_proximal_bundle_left.cpp"),
    solver(preamble_BCFW, 'FMC_GM<PairwiseConstruction::Left>', 'LP_BCFW_Bundle', 'ParseProblemGM_trees', "graph_matching_gm_proximal_bundle_left.cpp"),
    solver(preamble_BCFW, 'FMC_LOCAL_SUBPROBLEM<PairwiseConstruction::Left>', 'LP_BCFW_Bundle', 'ParseProblemLocalSubproblems_trees', "graph_matching_local_subproblems_proximal_bundle_left.cpp")
    ]

for e in solvers:
   f = open(e.filename,'w')
   f.write(e.preamble)
   f.write("\nusing namespace LP_MP;\nusing namespace LP_MP::TorresaniEtAlInput;\nint main(int argc, char** argv) {\nMpRoundingSolver<Solver<")
   f.write(e.FMC + "," + e.LP + ",StandardTighteningVisitor>> solver(argc,argv);\n")
   f.write("solver.ReadProblem(" + e.parse_fun + "<Solver<" + e.FMC + "," + e.LP + ",StandardTighteningVisitor>>);\n")
   f.write("return solver.Solve();\n}")
   f.close()
