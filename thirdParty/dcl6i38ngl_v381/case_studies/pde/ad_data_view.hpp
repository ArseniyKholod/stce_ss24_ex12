/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#include "dco.hpp"
#include "local_vols.hpp"

//** required to be compatible with C -- only use two-digit exponent
//** in output of scientific numbers.
#if defined(WIN32) && _MSC_VER < 1900
struct outputformatter {
  outputformatter() { _set_output_format(_TWO_DIGIT_EXPONENT); }
};
static outputformatter of;
#endif

// collection of independent variables
template <typename ATYPE> struct ACTIVE_INPUTS {
  ATYPE S0, r, K, T;
  LocalVolSurface<ATYPE> sigmaSq;
  ACTIVE_INPUTS(const double& S0, const double& r, const double& K, const double& T, std::istream& in)
      : S0(S0), r(r), K(K), T(T), sigmaSq(in) {}
  ACTIVE_INPUTS(const ATYPE& S0, const ATYPE& r, const ATYPE& K, const ATYPE& T, const LocalVolSurface<ATYPE>& sigmaSq)
      : S0(S0), r(r), K(K), T(T), sigmaSq(sigmaSq) {}
  ~ACTIVE_INPUTS() {}
  typedef typename dco::mode<ATYPE>::value_t DCO_VALUE_TYPE;
  ACTIVE_INPUTS<DCO_VALUE_TYPE> get_value() const {
    ACTIVE_INPUTS<DCO_VALUE_TYPE> R(dco::value(S0), dco::value(r), dco::value(K), dco::value(T), sigmaSq.get_value());
    return R;
  }
};

// collection of passive parameters
struct PASSIVE_INPUTS {
  int N;
  int M;
  mutable double rngseed[6];
  PASSIVE_INPUTS(const int& N, const int& M) : N(N), M(M) {
    for (int i = 0; i < 6; i++)
      rngseed[i] = i + 1;
  }
  ~PASSIVE_INPUTS() {}
  void reseed() {
    for (int i = 0; i < 6; i++)
      rngseed[i] = i + 1;
  }
};

// collection of dependent variables
template <typename ATYPE> struct ACTIVE_OUTPUTS {
  ATYPE V;
};

// collection of dependent variables
struct PASSIVE_OUTPUTS {
  double ci;
};
