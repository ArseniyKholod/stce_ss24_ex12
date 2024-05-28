/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "g_gap.hpp"

template <typename AD_TYPE> void f(int n, AD_TYPE& x) {
  g(n / 3, x);
  g(n / 3, x);
  // g_make_gap(n/3,x);
  g(n - n / 3 * 2, x);
}
