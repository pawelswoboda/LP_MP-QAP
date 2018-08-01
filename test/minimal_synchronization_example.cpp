#include "multigraph_matching.hxx"
#include "visitors/standard_visitor.hxx"
#include "solver.hxx"
#include <string>
#include <vector>
#include "test.h"

using namespace LP_MP;

const std::string minimal_synchronization_example = 
R"(gm 0 1
p 2 2 0 0
a 0 0 0 -1
a 1 0 1 -10
a 2 1 0 -10
a 3 1 1 -1

gm 0 2
p 2 2 0 0
a 0 0 0 -1
a 1 0 1 -10
a 2 1 0 -10
a 3 1 1 -1

gm 1 2
p 2 2 0 0
a 0 0 0 -1
a 1 0 1 -10
a 2 1 0 -10
a 3 1 1 -1
)";

const std::vector<std::string> options = 
{
"",
"--standardReparametrization", "anisotropic",
"--tightenIteration", "10",
"--tightenInterval", "5",
"--tightenReparametrization", "damped_uniform",
"--tightenConstraintsMax", "5",
"--maxIter", "100",
"--tighten"
};

int main(int argc, char** argv)
{
    Solver<LP<FMC_MGM>,StandardTighteningVisitor> solver(options);
    auto input = multigraph_matching_input::parse_string(minimal_synchronization_example);
    solver.template GetProblemConstructor<0>().construct(input);
    solver.Solve();
    test( std::abs(solver.lower_bound() - 42.0) ); 
}
