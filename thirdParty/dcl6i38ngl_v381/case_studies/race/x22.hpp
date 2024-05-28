/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

template <class T> void f(const vector<T> x, T& y) {
  y = 0;
  for (size_t i = 0; i < x.size(); i++)
    y = y + x[i] * x[i];
  y = y * y;
}
