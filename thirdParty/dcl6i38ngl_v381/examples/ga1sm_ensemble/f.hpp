/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "g_gap.hpp"

inline unsigned int prng() {
  static unsigned int seed = 5323;
  seed = 8253729 * seed + 2396403;
  return seed % 32768;
}

template <typename DCO_TYPE> void f(int n, int m, const DCO_TYPE& x, DCO_TYPE& y) {
  double r;
  DCO_TYPE sum;
  for (int i = 0; i < n; i++) {
    r = prng();
    g_make_gap(m, x, r, y);
    sum += y;
  }
  y = sum / n;
}
