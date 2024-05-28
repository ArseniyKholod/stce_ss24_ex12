/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
#include <fstream>
#include <cassert>

#include "../config.h"
#include "../ad_data_view.hpp"
#include "pdesolver.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Please specify input scenario file, e.g. scenario_1.in\n";
    return EXIT_FAILURE;
  }
  std::cout.precision(5);
  std::ifstream vols(argv[1]);
  if (vols.fail()) {
    std::cerr << "Cannot open scenario file '" << argv[1] << "'\n";
    return EXIT_FAILURE;
  }
  ACTIVE_INPUTS<double> X(S0, r, K, T, vols);
  vols.close();
  PASSIVE_INPUTS XP(N, M);
  ACTIVE_OUTPUTS<double> Y;
  pde::price(X, XP, Y);
  std::cout << "Y=" << Y.V << "\n";
}
