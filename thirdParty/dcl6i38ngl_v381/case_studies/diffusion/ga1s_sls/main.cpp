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
#include <cassert>
#include "dco.hpp"
using namespace std;
using namespace dco;
typedef ga1s<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

#include "../include/f.hpp"

template <typename DCO_MODE, typename TYPE> void LUDecomp_make_gap(vector<TYPE>& A) {
  size_t n = static_cast<size_t>(sqrt(double(A.size())));
  vector<double> Ap(n * n);
  for (size_t i = 0; i < n * n; i++)
    Ap[i] = value(A[i]);
  LUDecomp(Ap);
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      value(A[i * n + j]) = Ap[i * n + j];
}

// U^T*y=b
template <class TYPE> inline void FSubstT(const vector<TYPE>& LU, vector<TYPE>& y) {
  size_t n = y.size();
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < i; j++)
      y[i] = y[i] - LU[j * n + i] * y[j];
    y[i] = y[i] / LU[i * n + i];
  }
}

// L^T*x=y
template <class TYPE> inline void BSubstT(const vector<TYPE>& LU, vector<TYPE>& b) {
  size_t n = b.size();
  for (size_t k = n, i = n - 1; k > 0; k--, i--)
    for (size_t j = n - 1; j > i; j--)
      b[i] = b[i] - LU[j * n + i] * b[j];
}

// LU^T*x=y
template <class TYPE> inline void SolveT(const vector<TYPE>& LU, vector<TYPE>& b) {
  FSubstT(LU, b);
  BSubstT(LU, b);
}

template <typename DCO_MODE, typename TYPE> void Solve_make_gap(const vector<TYPE>& LU, vector<TYPE>& b) {
  const size_t n = b.size();
  auto rhs(b);
  dco::tape(LU)->switch_to_passive();
  Solve(LU, b);
  dco::tape(LU)->switch_to_active();
  dco::tape(LU)->register_variable(b);

  auto fill_gap = [=, &LU]() {
    vector<DCO_TYPE> a1b(n);
    for (size_t i = 0; i < n; ++i)
      a1b[i] = dco::derivative(b[i]);
    dco::tape(LU)->switch_to_passive();
    SolveT(LU, a1b);

    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < n; j++)
        dco::derivative(LU[i * n + j]) += dco::value(-a1b[i] * b[j]);
    dco::derivative(rhs) += dco::value(a1b);
    dco::tape(LU)->switch_to_active();
  };

  dco::tape(LU)->insert_callback(std::move(fill_gap));
}

template <> inline void sim(const vector<DCO_TYPE>& c, const size_t m, vector<DCO_TYPE>& T) {
  const size_t n = c.size();
  static vector<DCO_TYPE> A(n * n);
  residual_jacobian(c, T, A);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j)
      A[i * n + j] = A[i * n + j] / static_cast<double>(m);
    A[i + i * n] = A[i + i * n] - 1;
  }
  LUDecomp_make_gap<DCO_MODE>(A);
  for (size_t j = 0; j < m; ++j) {
    for (size_t i = 0; i < n; ++i)
      T[i] = -T[i];
    Solve_make_gap<DCO_MODE>(A, T);
  }
}

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
  }
  f(ca, m, Ta, O, va);
  cerr << "record (0," << m << ")=" << dco::size_of(tape) << "B" << endl;
  derivative(va) = 1.0;
  tape->register_output_variable(va);
  tape->interpret_adjoint();
  tape->write_to_dot();

  for (size_t i = 0; i < n; i++)
    dvdc[i] = derivative(ca[i]);
  cout.precision(5);
  for (size_t i = 0; i < n; i++)
    cout << "dvdc[" << i << "]=" << dvdc[i] << endl;
}
