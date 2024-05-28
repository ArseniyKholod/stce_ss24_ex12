/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "g.hpp"

template <typename DCO_BASE_TYPE> void gt(int n, DCO_BASE_TYPE& x, DCO_BASE_TYPE& xt1) {
  for (int i = 0; i < n; i++) {
    xt1 = cos(x) * xt1;
    x = sin(x);
  }
}

void g_make_gap(int n, DCO_TYPE& x) {
  typedef DCO_MODE::value_t DCO_VALUE_TYPE;

  DCO_VALUE_TYPE xt = 1.;
  gt(n, dco::value(x), xt);

  DCO_TYPE x_in(x);
  dco::tape(x_in)->register_variable(x);

  auto fill_gap = [=]() { dco::derivative(x_in) += xt * dco::derivative(x); };

  dco::tape(x_in)->insert_callback(std::move(fill_gap));
}
