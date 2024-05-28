/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "g.hpp"

template <typename DCO_TYPE> void a1s_g(DCO_TYPE& pa, const DCO_TYPE& xv, DCO_TYPE& xa) { pa = xa / (2 * xv); }

void g_make_gap(const AD_TYPE& p, AD_TYPE& x) {

  g(dco::value(p), dco::value(x));
  dco::tape(p)->register_variable(x);

  auto fill_gap = [=]() {
    AD_MODE::value_t pa = 0;
    a1s_g(pa, dco::value(x), dco::derivative(x));
    dco::derivative(p) += pa;
  };

  dco::tape(p)->insert_callback(std::move(fill_gap));
}
