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
typedef ga1s<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

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
  vector<double> dvdc(n);

  vector<DCO_TYPE> ca(n);
  vector<DCO_TYPE> Ta(n);
  DCO_TYPE va;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  for (size_t i = 0; i < n; i++) {
    ca[i] = c[i];
    Ta[i] = T[i];
    tape->register_variable(ca[i]);
    tape->register_variable(Ta[i]);
  }
  f(ca, m, Ta, O, va);
  cerr << "record (0," << m << ")=" << dco::size_of(tape) << "B" << endl;
  derivative(va) = 1.0;
  tape->register_output_variable(va);
  tape->interpret_adjoint();
  for (size_t i = 0; i < n; i++)
    dvdc[i] = derivative(ca[i]);
  cout.precision(5);
  for (size_t i = 0; i < n; i++)
    cout << "dvdc[" << i << "]=" << dvdc[i] << endl;
}
