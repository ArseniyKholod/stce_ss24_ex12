/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <cstdlib>
#include <iostream>
#include "dco.hpp"
using namespace std;
using namespace dco;
typedef ga1s<gt1s<double>::type> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;
typedef DCO_TAPE_TYPE::iterator_t DCO_TAPE_POSITION_TYPE;

#include "../include/f.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "2 parameters expected:" << endl
         << "  1. number of spatial finite difference grid points" << endl
         << "  2. number of implicit Euler steps" << endl;
    return EXIT_FAILURE;
  }
  size_t n = atoi(argv[1]), m = atoi(argv[2]);
  vector<double> c(n);
  for (size_t i = 0; i < n; i++)
    c[i] = 0.01;
  vector<double> T(n);
  for (size_t i = 0; i < n - 1; i++)
    T[i] = 300.;
  T[n - 1] = 1700.;
  ifstream ifs("O.txt");
  vector<double> O(n);
  for (size_t i = 0; i < n; i++)
    ifs >> O[i];
  vector<vector<double>> d2vdc2(n, vector<double>(n, 0));

  vector<DCO_TYPE> ca(n);
  vector<DCO_TYPE> Ta(n);
  DCO_TYPE va;
  dco::smart_tape_ptr_t<DCO_MODE> tape;

  for (size_t i = 0; i < n; i++) {
    ca[i] = c[i];
    Ta[i] = T[i];
    tape->register_variable(ca[i]);
  }
  DCO_TAPE_POSITION_TYPE p = tape->get_position();
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++)
      Ta[j] = T[j];
    if (i > 0)
      tape->zero_adjoints();
    derivative(value(ca[i])) = 1;
    f(ca, m, Ta, O, va);
    value(derivative(va)) = 1;
    tape->interpret_adjoint();
    for (size_t j = 0; j < n; j++)
      derivative(value(ca[j])) = 0;
    for (size_t j = 0; j < n; j++)
      d2vdc2[j][i] = derivative(derivative(ca[j]));
    tape->reset_to(p);
  }
  cout.precision(5);
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      cout << "d2vdc2[" << i << "][" << j << "]=" << d2vdc2[i][j] << endl;
}
