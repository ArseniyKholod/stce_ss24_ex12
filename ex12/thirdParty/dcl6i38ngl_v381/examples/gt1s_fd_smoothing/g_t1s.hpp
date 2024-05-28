/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

template <> void g<dco::gt1s<double>::type>(dco::gt1s<double>::type& x) {

  double xv = dco::value(x);
  double xt = dco::derivative(x);
  const double h = 0.1;
  if (x < -h)
    x = 1;
  else if (x > h)
    x = 0;
  else {
    double xm = xv - h;
    double xp = xv + h;
    g(xv);
    dco::value(x) = xv;
    g(xp);
    g(xm);
    dco::derivative(x) = xt * (xp - xm) / (2 * h);
  }
}
