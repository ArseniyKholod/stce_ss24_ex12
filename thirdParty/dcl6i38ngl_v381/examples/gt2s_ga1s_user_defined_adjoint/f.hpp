/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "g_gap.hpp"

template <typename DCO_TYPE> void f(DCO_TYPE p, DCO_TYPE& x) {
  p = exp(p);
  // g(p,x);
  g_make_gap(p, x);
  x = x * p;
}
