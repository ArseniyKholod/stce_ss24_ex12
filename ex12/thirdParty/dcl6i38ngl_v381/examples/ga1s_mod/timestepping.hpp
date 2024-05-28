/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <cmath>

template <typename T> void f(const int n, T& x, const T& p) {
  double dt = 1. / n, t = 0;
  for (int i = 0; i < n; i++, t += dt)
    x += dt * p * sin(x * t);
}
