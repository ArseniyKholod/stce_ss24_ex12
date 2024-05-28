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
  return (ST < X.K ? ATYPE(0) : exp(-X.r * X.T) * (ST - X.K));
}

template <typename DCO_TYPE> DCO_TYPE mcpath_make_gap(const ACTIVE_INPUTS<DCO_TYPE>& X, const PASSIVE_INPUTS& XP) {
  typedef dco::mode<DCO_TYPE> MODE_T;
  typedef typename MODE_T::value_t DCO_VALUE_TYPE;

  // need values of active inputs exactly once
  // as they remain same for all paths
  static ACTIVE_INPUTS<DCO_VALUE_TYPE> X_v(X.get_value());
  // seed for rng is overwritten repeatedly, i.e. needs to be checkpointed
  std::vector<double> rngseed(XP.rngseed, XP.rngseed + 6);

  // passive Monte Carlo simulation
  DCO_TYPE V = mcpath(X_v, XP);
  dco::tape(X.S0)->register_variable(V);

  // checkpointing active inputs ensures
  // correct propagation of adjoints
  // when filling the gap by tape interpretation
  //
  // neither active nor passive inputs are overwritten
  // by remainder program (except XP.rngseed)
  auto fill_gap = [=, &X, &XP]() {
    auto mc_path_begin = dco::tape(X.S0)->get_position();
    for (size_t i = 0; i < rngseed.size(); ++i)
      XP.rngseed[i] = rngseed[i];
    DCO_TYPE Vl = mcpath(X, XP);

    dco::tape(X.S0)->register_output_variable(Vl);
    static int c = 0;
    if (!c++)
      std::cerr << "Tape size (gap filled): " << dco::size_of(dco::tape(X.S0)) / 1.e6 << "MB\n\n";
    dco::derivative(Vl) = dco::derivative(V);
    dco::tape(X.S0)->interpret_adjoint_and_reset_to(mc_path_begin);
  };

  dco::tape(X.S0)->insert_callback(std::move(fill_gap));
  return V;
}

template <typename ATYPE>
void price(const ACTIVE_INPUTS<ATYPE>& X, const PASSIVE_INPUTS& XP, ACTIVE_OUTPUTS<ATYPE>& Y, PASSIVE_OUTPUTS& YP) {
  typedef typename dco::mode<ATYPE>::type DCO_TYPE;
  Y.V = 0;
  ATYPE sumsq = 0;
  for (int p = 0; p < XP.N; p++) {
    ATYPE y = mcpath_make_gap<DCO_TYPE>(X, XP);
    Y.V += y;
    sumsq += y * y;
  }
  Y.V = Y.V / XP.N;
  YP.ci = dco::passive_value(sqrt((sumsq / XP.N - Y.V * Y.V) / XP.N));
}

} // namespace mc
