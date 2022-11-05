# What
This is a **minimal (!toy!) example** of **library-based** usage of [SCIP](https://www.scipopt.org/) and [SoPlex](https://soplex.zib.de/), focused on **MILP-solving**, using **C++** and based on the [Bazel](https://bazel.build/)-buildsystem using **static-linking**.

It's basically:

- Config
  - Acquisition of software needed
  - Build
- One example each from the original sources

### Examples tested with:

#### Linux
- GCC 9

#### Windows
- Visual Studio Community 2019 

# How to use

## Prep
- Install Java
- Install C/C++ Toolchain
- Install Bazel or better: grab [bazelisk](https://github.com/bazelbuild/bazelisk/releases)

## Build and run `SoPlex` example

> bazelisk run //example/soplex:example_soplex

    Testing SoPlex as floating-point LP solver:

    Equilibrium scaling LP (persistent)
    Simplifier removed 0 rows, 0 columns, 0 nonzeros, 0 col bounds, 0 row bounds
    Reduced LP has 1 rows 2 columns 2 nonzeros
    Equilibrium scaling LP
    type |   time |   iters | facts |    shift | viol sum | viol num | obj value 
      L  |    0.0 |       0 |     3 | 0.00e+00 | 8.00e-01 |        1 | 5.00000000e+00
      L  |    0.0 |       1 |     4 | 0.00e+00 | 0.00e+00 |        0 | 6.60000000e+00
    --- unscaling internal solution
    --- unsimplifying solution and basis
    --- unscaling external solution
    --- verifying computed solution
      L  |    0.0 |       0 |     1 | 0.00e+00 | 0.00e+00 |        0 | 6.60000000e+00
      L  |    0.0 |       0 |     1 | 0.00e+00 | 0.00e+00 |        0 | 6.60000000e+00
    --- unscaling external solution
    --- verifying computed solution

    SoPlex status       : problem is solved [optimal]
    Solving time (sec)  : 0.00
    Iterations          : 1
    Objective value     : 6.60000000e+00

    LP solved to optimality.
    Objective value is 6.60000000e+00.
    Primal solution is [1.00000000e+00, 1.80000000e+00].
    Dual solution is [2.00000000e+00].

## Build and run `SCIP` example

> bazelisk run //example/scip:example_scip -- 9

    ********************************************
    * n-queens solver based on SCIP            *
    *                                          *
    * (c) Cornelius Schwarz (2007)             *
    ********************************************

    solution for 9-queens:

    --- --- --- --- --- --- --- --- ---
    |   |   |   |   | D |   |   |   |   |
    --- --- --- --- --- --- --- --- ---
    |   |   |   |   |   |   | D |   |   |
    --- --- --- --- --- --- --- --- ---
    |   | D |   |   |   |   |   |   |   |
    --- --- --- --- --- --- --- --- ---
    |   |   |   |   |   | D |   |   |   |
    --- --- --- --- --- --- --- --- ---
    |   |   | D |   |   |   |   |   |   |
    --- --- --- --- --- --- --- --- ---
    | D |   |   |   |   |   |   |   |   |
    --- --- --- --- --- --- --- --- ---
    |   |   |   |   |   |   |   | D |   |
    --- --- --- --- --- --- --- --- ---
    |   |   |   | D |   |   |   |   |   |
    --- --- --- --- --- --- --- --- ---
    |   |   |   |   |   |   |   |   | D |
    --- --- --- --- --- --- --- --- ---

# Why
- SCIP/SoPlex moved to *Apache 2.0 license* on 04.11.2022 ([Twitter](https://nitter.it/timoberthold/status/1588451599906918400#m))
  - New possibilities for non-academic users!
- Bazel is the go-to buildtool for my personal projects for some time now
  - Especially for easy-to-reproduce proof-of-concepts

# Background
- All the heavy lifting is done by [rules_foreign_cc](https://github.com/bazelbuild/rules_foreign_cc)
  - We *consume* the original maintained *cmake-based buildsystem*
- **A lot of optional deps are deactivated!** -> see `BUILD`
  - Notable core stuff: zlib, boost
    - No *readers*?
  - Notable performance-related: bliss, papilo (**NOT sharing the same license!**)
    - No symmetry-breaking
    - Not using newer presolver
  - Notable feature-related: GMP, Ipopt
    - No rational simplex
    - No nonlinear tooling

(Effects are guesses of mine)

# Disclaimer
- As i said: this is a minimal example -> don't expect too much!
