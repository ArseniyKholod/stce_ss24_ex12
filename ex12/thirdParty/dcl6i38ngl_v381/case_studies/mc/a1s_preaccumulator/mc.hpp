/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once
#include "../mrg32k3a.h"
#include "../ad_data_view.hpp"

namespace mc {

template <typename ATYPE> inline ATYPE mcpath(const ACTIVE_INPUTS<ATYPE>& X, const PASSIVE_INPUTS& XP) {
  typename dco::mode<ATYPE>::jacobian_preaccumulator_t P(dco::tape(X.S0));
  const ATYPE mcdt = X.T / (XP.M - 1);
  ATYPE logS = log(X.S0);
  ATYPE t = 0;

  static std::vector<double> Z(XP.M);
  randNormal(XP.M, XP.rngseed, Z);

  for (int i = 0; i < XP.M; i++) {
    t += mcdt;
    ATYPE volS = sqrt(X.sigmaSq(logS, t));
    logS += (X.r - 0.5 * volS * volS) * mcdt + volS * sqrt(mcdt) * Z[i];
  }
  ATYPE ST = exp(logS);
  ATYPE output = ST < X.K ? ATYPE(0) : exp(-X.r * X.T) * (ST - X.K);
  P.register_output(output);
  P.finish();
  return output;
}

template <typename ATYPE>
void price(const ACTIVE_INPUTS<ATYPE>& X, const PASSIVE_INPUTS& XP, ACTIVE_OUTPUTS<ATYPE>& Y, PASSIVE_OUTPUTS& YP) {
  typedef typename dco::mode<ATYPE>::type DCO_TYPE;
  Y.V = 0;
  ATYPE sumsq = 0;
  for (int p = 0; p < XP.N; p++) {
    ATYPE y = mcpath<DCO_TYPE>(X, XP);
    Y.V += y;
    sumsq += y * y;
  }
  Y.V = Y.V / XP.N;
  YP.ci = dco::passive_value(sqrt((sumsq / XP.N - Y.V * Y.V) / XP.N));
}

} // namespace mc
