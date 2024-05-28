/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "g_gap.hpp"

template <typename ATYPE> void f(int n, int stride, ATYPE& x) {
  // g(n,x); // for split reversal
  g_make_gap(n, stride, x);
}
