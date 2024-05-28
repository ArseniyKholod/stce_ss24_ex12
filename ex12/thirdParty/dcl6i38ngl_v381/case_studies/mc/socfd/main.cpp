/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <assert.h>
#include <iostream>
#include <fstream>
#include <cfloat>

#include "../config.h"
#include "../ad_data_view.hpp"
#include "../primal/mc.hpp"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Please specify input scenario file, e.g. scenario_1.in\nIf 2nd parameter given, print output.\n";
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
  ACTIVE_OUTPUTS<double> Yp;
  PASSIVE_OUTPUTS YP;

  // XM[xmsz] is an array pointing to all active inputs
  unsigned int xmsz = 4 + X.sigmaSq.a.size() + X.sigmaSq.b.size();
  std::vector<double*> XM(xmsz);
  XM[0] = &X.S0;
  XM[1] = &X.r;
  XM[2] = &X.K;
  XM[3] = &X.T;
  for (unsigned int i = 0; i < X.sigmaSq.a.size(); i++)
    XM[i + 4] = &X.sigmaSq.a[i];
  for (unsigned int i = 0; i < X.sigmaSq.b.size(); i++)
    XM[i + 4 + X.sigmaSq.a.size()] = &X.sigmaSq.b[i];

  mc::price(X, XP, Y, YP);
  std::cout << "Y=" << Y.V << " in (" << Y.V - 3 * YP.ci << ", " << Y.V + 3 * YP.ci << ")\n";

  for (unsigned int i = 0; i < xmsz; i++) {
    double pi = (*XM[i] == 0) ? sqrt(sqrt(DBL_EPSILON)) : sqrt(sqrt(DBL_EPSILON)) * std::abs(*XM[i]);
    for (unsigned int j = 0; j <= i; j++) {
      double pj = (*XM[j] == 0) ? sqrt(sqrt(DBL_EPSILON)) : sqrt(sqrt(DBL_EPSILON)) * std::abs(*XM[j]);
      *XM[i] += pi;
      *XM[j] += pj;
      XP.reseed();
      mc::price(X, XP, Y, YP);
      *XM[i] -= 2 * pi;
      XP.reseed();
      mc::price(X, XP, Yp, YP);
      Y.V -= Yp.V;
      *XM[i] += 2 * pi;
      *XM[j] -= 2 * pj;
      XP.reseed();
      mc::price(X, XP, Yp, YP);
      Y.V -= Yp.V;
      *XM[i] -= 2 * pi;
      XP.reseed();
      mc::price(X, XP, Yp, YP);
      Y.V += Yp.V;
      if (argc == 3) {
        std::cout << "d^2Y/dX[" << i << "]dX[" << j << "]=" << Y.V / (4 * pi * pj) << "\n";
      }
      *XM[i] += pi;
      *XM[j] += pj;
    }
  }

  if (argc != 3) {
    std::cout << "2nd-order finite differences too unstable to give reproducible numbers on various platforms.\n"
              << "Run with second parameter to print derivative results.\n";
  }
}
