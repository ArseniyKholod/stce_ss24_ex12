/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

template <class T> void g(T& x) {
  if (x > 0)
    x = 0;
  else
    x = 1;
}

#include "g_t1s.hpp"
