/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

template <class T> void g(const T& p, T& x) {
  const T eps = 1e-12;
  T x_old = x + 1;
  while (fabs(x - x_old) > eps) {
    x_old = x;
    x = x_old - (x_old * x_old - p) / (2 * x_old);
  }
}

#include "g_t1s.hpp"
