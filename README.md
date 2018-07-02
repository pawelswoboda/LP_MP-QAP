# LP_MP-QAP
========

[![Build Status](https://travis-ci.org/pawelswoboda/LP_MP-QAP.svg?branch=master)](https://travis-ci.org/pawelswoboda/LP_MP-QAP)

Dual decomposition solvers for the quadratic assignment problem (QAP), also called graph matching in computer vision, based on the [LP_MP](https://github.com/pawelswoboda/LP_MP) library.

## Solvers
* Minimum cost flow based solver [1].
* Pure message passing based solver [1].
* SRMP with the QAP reformulated as a graphical model [2].
* Hungarian belief propagation [3].

## Input formats
We use the input format of the solver [4], see [here](http://pub.ist.ac.at/~vnk/software.html) for the definition of this format.

## Installation
Type `git clone https://github.com/pawelswoboda/LP_MP-QAP.git` to download the main repository and `git submodule update --init --remote --recursive` the dependencies. Then type `cmake .` to configure and `make` to build.

## References
* [1]: `Swoboda, P., Rother, C., Abu Alhaija, H., Kainmuller, D. and Savchynskyy, B.  A Study of Lagrangean Decompositions and Dual Ascent Solvers for Graph Matching.  CVPR, July 2017.`
* [2]: `V. Kolmogorov. A New Look at Reweighted Message Passing. IEEE Trans. Pattern Anal. Mach. Intell., 37(5):919–930, 2015.`
* [3]: `Zhang, Z. ,  Shi, Q. ,  McAuley, J. ,  Wei, W. ,  Zhang, Y. and van den Hengel, A.  Pairwise Matching Through Max-Weight Bipartite Belief Propagation.  CVPR, June 2016.`
* [4]: `Torresani, L., Kolmogorov, V. and Rother, C. A Dual Decomposition Approach to Feature Correspondence. IEEE Trans. Pattern Anal. Mach. Intell.,  35(2):259–271, 2013.`
