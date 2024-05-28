/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <stack>

#include "g.hpp"
using namespace std;

void g_make_gap(int n, int stride, DCO_MODE::type& xg) {
  typedef DCO_MODE::value_t DCO_VALUE_TYPE;

  if (n > stride) {
    g_make_gap(n / 2, stride, xg);
    g_make_gap(n - n / 2, stride, xg);
  } else {
    DCO_MODE::type xg_in(xg);

    g(n, dco::value(xg));
    dco::tape(xg_in)->register_variable(xg);

    auto fill_gap = [=]() {
      DCO_VALUE_TYPE xa = 0;
      for (int i = 0; i < n; i++) {
        DCO_VALUE_TYPE xv = dco::value(xg_in);
        g(n - i - 1, xv);
        DCO_TYPE x = xv;
        auto p0 = dco::tape(xg_in)->get_position();
        dco::tape(xg_in)->register_variable(x);
        DCO_TYPE x_in = x;
        DCO_TAPE_POSITION_TYPE p1 = dco::tape(xg_in)->get_position();
        g(1, x);
        dco::tape(xg_in)->register_output_variable(x);
        if (i == 0)
          xa = dco::derivative(xg);
        dco::derivative(x) = xa;
        dco::tape(xg_in)->interpret_adjoint_to(p1);
        xa = dco::derivative(x_in);
        dco::tape(xg_in)->reset_to(p0);
        if (i == n - 1)
          dco::derivative(xg_in) += xa;
      }
    };

    dco::tape(xg_in)->insert_callback(std::move(fill_gap));
  }
}
