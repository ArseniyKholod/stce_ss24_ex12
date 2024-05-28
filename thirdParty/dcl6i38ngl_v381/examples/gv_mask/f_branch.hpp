/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

//** ONLY USED FOR DOCUMENTATION.
template <typename T> void f(const T& x, T& y) {
  T v = sin(x * x);
  T w = -cos(v);
  y = v * w;
  if (y < -0.5)
    y += sin(exp(x));
}
