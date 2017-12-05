# LP_MP-QAP
Dual decomposition solvers for the quadratic assignment problem (QAP), also called graph matching in computer vision based on the [LP_MP](https://github.com/pawelswoboda/LP_MP) library.

## Solvers
* Minimum cost flow based solver [1].
* Pure message passing based solver [1].
* SRMP with the QAP reformulated as a graphical model [2].
* Hungarian belief propagation [3].

## References
* [1]: `Swoboda, P., Rother, C., Abu Alhaija, H., Kainmuller, D. and Savchynskyy, B.  A Study of Lagrangean Decompositions and Dual Ascent Solvers for Graph Matching.  CVPR, July 2017.`
* [2]: `V. Kolmogorov. A New Look at Reweighted Message Passing. IEEE Trans. Pattern Anal. Mach. Intell., 37(5):919–930, 2015.`
* [3]: `Zhang, Z. ,  Shi, Q. ,  McAuley, J. ,  Wei, W. ,  Zhang, Y. and  van den Hengel, A.  Pairwise Matching Through Max-Weight Bipartite Belief Propagation.  CVPR, June 2016.`
