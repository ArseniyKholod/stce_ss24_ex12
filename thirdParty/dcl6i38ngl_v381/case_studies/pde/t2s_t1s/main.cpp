/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <cassert>
#include <iostream>
#include "dco.hpp"

typedef dco::gt1s<double> DCO_BASE_MODE;
typedef DCO_BASE_MODE::type DCO_BASE_TYPE;
typedef dco::gt1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

#include "../config.h"
#include "../ad_data_view.hpp"
#include "../primal/pdesolver.hpp"

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
  ACTIVE_INPUTS<DCO_TYPE> X(S0, r, K, T, vols);
  vols.close();
  PASSIVE_INPUTS XP(N, M);
  ACTIVE_OUTPUTS<DCO_TYPE> Y;

  // XM[xmsz] is an array pointing to all active inputs
  unsigned int xmsz = 4 + X.sigmaSq.a.size() + X.sigmaSq.b.size();
  std::vector<DCO_TYPE*> XM(xmsz);
  XM[0] = &X.S0;
  XM[1] = &X.r;
  XM[2] = &X.K;
  XM[3] = &X.T;
  for (unsigned int i = 0; i < X.sigmaSq.a.size(); i++)
    XM[i + 4] = &X.sigmaSq.a[i];
  for (unsigned int i = 0; i < X.sigmaSq.b.size(); i++)
    XM[i + 4 + X.sigmaSq.a.size()] = &X.sigmaSq.b[i];

  for (unsigned int i = 0; i < xmsz; i++) {
    for (unsigned int j = 0; j <= i; j++) {
      dco::derivative(dco::value(*XM[i])) = 1;
      dco::value(dco::derivative(*XM[j])) = 1;
      pde::price(X, XP, Y);
      if (!i)
        std::cout << "Y=" << dco::value(Y.V) << "\n";
      std::cout << "d^2Y/dX[" << i << "]dX[" << j << "]=" << dco::derivative(dco::derivative(Y.V)) << "\n";
      dco::derivative(dco::value(*XM[i])) = 0;
      dco::value(dco::derivative(*XM[j])) = 0;
    }
  }
}
