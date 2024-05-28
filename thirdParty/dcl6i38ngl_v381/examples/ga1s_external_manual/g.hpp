/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <vector>

template <typename DCO_TYPE> void g(std::vector<DCO_TYPE> x, DCO_TYPE& y) {
  y = 0;
  for (unsigned i = 0; i < x.size(); i++)
    y += x[i];
}
