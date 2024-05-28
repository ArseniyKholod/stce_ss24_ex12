/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <vector>

#include "g.hpp"
#include "g_a1s.hpp"

void g_make_gap(std::vector<DCO_TYPE>& x, DCO_TYPE& y) {
  typedef DCO_MODE::value_t DCO_VALUE_TYPE;

  //** Extract passive value and run primal function.
  vector<DCO_VALUE_TYPE> xv(x.size());
  xv = dco::value(x);
  g(xv, dco::value(y));

  //** Register output variable to continue tape recording after
  //** this function returns.
  dco::tape(x)->register_variable(y);

  //** Filling the gap with the tape callback. Use automatically
  //** captured (checkpointed) x and y to access adjoints.
  auto fill_gap = [=]() {
    vector<DCO_VALUE_TYPE> xa(x.size());
    g_a1s(xa, dco::derivative(y));
    dco::derivative(x) += xa;
  };

  dco::tape(x)->insert_callback(std::move(fill_gap));
}
