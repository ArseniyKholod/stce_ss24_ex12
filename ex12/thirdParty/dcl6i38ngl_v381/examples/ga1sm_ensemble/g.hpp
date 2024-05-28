/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

template <typename ATYPE> void g(int m, const ATYPE& x, const double& r, ATYPE& y) {
  y = 0;
  for (int i = 0; i < m; i++)
    y += sin(x + r);
}
