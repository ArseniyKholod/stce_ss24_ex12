/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>

template <> void g<dco::gt1s<double>::type>(dco::gt1s<double>::type& x) {
  const double h = 0.1;
  if (x < -h)
    x = 1;
  else if (x > h)
    x = 0;
  else {
    double xv = dco::value(x);
    double xt = dco::derivative(x);
    if (xv > 0)
      xv = 0;
    else
      xv = 1;
    xt = -1 / (2 * h) * xt;
    dco::value(x) = xv;
    dco::derivative(x) = xt;
  }
}
