/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#include <cmath>
#include "../ad_data_view.hpp"
#include "../lapack.hpp"

namespace pde {

template <typename ATYPE> class CrankNicholson {
public:
  static const ACTIVE_INPUTS<ATYPE>* X_p;
  static const PASSIVE_INPUTS* XP_p;
  static ATYPE xmin, xmax, tmax;
  static double tmin;
  std::vector<ATYPE> LHSj_dl, LHSj_d, LHSj_du, Vprev, Vcurr;
  ATYPE* RHSj;
  CrankNicholson()
      : LHSj_dl(XP_p->N - 1), LHSj_d(XP_p->N), LHSj_du(XP_p->N - 1), Vprev(XP_p->N + 2), Vcurr(XP_p->N + 2) {}
  void swapVs() { std::swap(Vcurr, Vprev); }

private:
  CrankNicholson(const CrankNicholson& copy);
  CrankNicholson operator=(const CrankNicholson& rhs);

public:
  void setBoundaryConditions(int, std::vector<ATYPE>&);
  void prepareLHS(int);
  void prepareRHS(int);
  void solveTridiagonalSystem();
};

template <typename ATYPE> const ACTIVE_INPUTS<ATYPE>* CrankNicholson<ATYPE>::X_p = 0;
template <typename ATYPE> const PASSIVE_INPUTS* CrankNicholson<ATYPE>::XP_p = 0;
template <typename ATYPE> ATYPE CrankNicholson<ATYPE>::xmin = 0;
template <typename ATYPE> ATYPE CrankNicholson<ATYPE>::xmax = 0;
template <typename ATYPE> double CrankNicholson<ATYPE>::tmin = 0;
template <typename ATYPE> ATYPE CrankNicholson<ATYPE>::tmax = 0;

template <typename ATYPE> void CrankNicholson<ATYPE>::setBoundaryConditions(int ts, std::vector<ATYPE>& V) {
  const ATYPE dx = (xmax - xmin) / (XP_p->N + 1);
  const ATYPE dt = X_p->T / (XP_p->M + 1);

  if (ts == XP_p->M + 1) {
    for (int i = 1; i < XP_p->N + 1; i++) {
      const ATYPE xi = xmin + i * dx;
      const ATYPE Si = exp(xi);
      if (Si - X_p->K > 0.0)
        V[i] = Si - X_p->K;
      else
        V[i] = 0.0;
    }
  }
  V[0] = 0.0;
  const ATYPE Smax = exp(xmax);
  const ATYPE t_j = ts * dt;
  V[XP_p->N + 1] = Smax - exp(-X_p->r * (X_p->T - t_j)) * X_p->K;
}

template <typename ATYPE> void CrankNicholson<ATYPE>::prepareLHS(const int j_time) {
  const int j = j_time;
  const ATYPE dt = (tmax - tmin) / (XP_p->M + 1);
  const ATYPE t = tmin + j * dt;
  const ATYPE dx = (xmax - xmin) / (XP_p->N + 1);
  const ATYPE alpha = dt / (dx * dx);
  const ATYPE z = 1.0 + X_p->r * dt;

  int row = 0;
  ATYPE x = xmin + (row + 1) * dx;
  ATYPE u_ij, l_ij, c_ij;
  ATYPE vhat = X_p->sigmaSq(x, t);
  u_ij = 0.5 * alpha * (vhat + dx * (X_p->r - 0.5 * vhat));
  c_ij = -alpha * vhat;
  LHSj_du[row] = -0.5 * u_ij;
  LHSj_d[row] = z - 0.5 * c_ij;
  for (row = 1; row < XP_p->N - 1; row++) {
    x = xmin + (row + 1) * dx;
    vhat = X_p->sigmaSq(x, t);
    u_ij = 0.5 * alpha * (vhat + dx * (X_p->r - 0.5 * vhat));
    l_ij = 0.5 * alpha * (vhat - dx * (X_p->r - 0.5 * vhat));
    c_ij = -alpha * vhat;
    LHSj_dl[row - 1] = -0.5 * l_ij;
    LHSj_d[row] = z - 0.5 * c_ij;
    LHSj_du[row] = -0.5 * u_ij;
  }
  row = XP_p->N - 1;
  x = xmin + (row + 1) * dx;
  vhat = X_p->sigmaSq(x, t);
  l_ij = 0.5 * alpha * (vhat - dx * (X_p->r - 0.5 * vhat));
  c_ij = -alpha * vhat;
  LHSj_dl[row - 1] = -0.5 * l_ij;
  LHSj_d[row] = z - 0.5 * c_ij;
}

template <typename ATYPE> void CrankNicholson<ATYPE>::prepareRHS(const int j_time) {
  const int j = j_time;
  const ATYPE dt = (tmax - tmin) / (XP_p->M + 1);
  const ATYPE t = tmin + j * dt;
  const ATYPE dx = (xmax - xmin) / (XP_p->N + 1);
  const ATYPE alpha = dt / (dx * dx);

  std::vector<ATYPE> RHSj_d(XP_p->N), RHSj_du(XP_p->N - 1), RHSj_dl(XP_p->N - 1);

  int row = 0;
  ATYPE c_ij, u_ij, l_ij;
  ATYPE x = xmin + (row + 1) * dx;
  ATYPE vhat = X_p->sigmaSq(x, t);
  u_ij = 0.5 * alpha * (vhat + dx * (X_p->r - 0.5 * vhat));
  c_ij = -alpha * vhat;
  RHSj_du[row] = 0.5 * u_ij;
  RHSj_d[row] = 0.5 * c_ij + 1.0;
  for (row = 1; row < XP_p->N - 1; row++) {
    x = xmin + (row + 1) * dx;
    vhat = X_p->sigmaSq(x, t);
    u_ij = 0.5 * alpha * (vhat + dx * (X_p->r - 0.5 * vhat));
    l_ij = 0.5 * alpha * (vhat - dx * (X_p->r - 0.5 * vhat));
    c_ij = -alpha * vhat;
    RHSj_dl[row - 1] = 0.5 * l_ij;
    RHSj_d[row] = 0.5 * c_ij + 1.0;
    RHSj_du[row] = 0.5 * u_ij;
  }
  row = XP_p->N - 1;
  x = xmin + (row + 1) * dx;
  vhat = X_p->sigmaSq(x, t);
  l_ij = 0.5 * alpha * (vhat - dx * (X_p->r - 0.5 * vhat));
  c_ij = -alpha * vhat;
  RHSj_dl[row - 1] = 0.5 * l_ij;
  RHSj_d[row] = 0.5 * c_ij + 1.0;

  row = 0;
  RHSj[row] = RHSj_d[row] * Vprev[1] + RHSj_du[row] * Vprev[2];
  x = xmin + (row + 1) * dx;
  vhat = X_p->sigmaSq(x, t);
  l_ij = 0.5 * alpha * (vhat - dx * (X_p->r - 0.5 * vhat));
  RHSj[row] += l_ij * 0.5 * (Vcurr[0] + Vprev[0]);
  for (row = 1; row < XP_p->N - 1; row++)
    RHSj[row] = RHSj_dl[row - 1] * Vprev[row] + RHSj_d[row] * Vprev[row + 1] + RHSj_du[row] * Vprev[row + 2];

  row = XP_p->N - 1;
  x = xmin + (row + 1) * dx;
  RHSj[row] = RHSj_dl[row - 1] * Vprev[row] + RHSj_d[row] * Vprev[row + 1];
  vhat = X_p->sigmaSq(x, t);
  u_ij = 0.5 * alpha * (vhat + dx * (X_p->r - 0.5 * vhat));
  RHSj[row] += u_ij * 0.5 * (Vcurr[XP_p->N + 1] + Vprev[XP_p->N + 1]);
}

template <typename ATYPE> void CrankNicholson<ATYPE>::solveTridiagonalSystem() {
  std::vector<int> LHSj_ipiv(XP_p->N);
  std::vector<ATYPE> LHSj_du2(XP_p->N - 2);

  int info = 0;
  dgttrf(XP_p->N, LHSj_dl.data(), LHSj_d.data(), LHSj_du.data(), LHSj_du2.data(), LHSj_ipiv.data(), &info);
  dgttrs("N", XP_p->N, 1, LHSj_dl.data(), LHSj_d.data(), LHSj_du.data(), LHSj_du2.data(), LHSj_ipiv.data(), RHSj,
         XP_p->N, &info);
}

template <typename ATYPE> void several_time_steps(int from, int to, CrankNicholson<ATYPE>& CN) {
  for (int j = from; j >= to; j--) {
    CN.setBoundaryConditions(j, CN.Vcurr);
    CN.prepareLHS(j);
    CN.RHSj = &CN.Vcurr[1];
    CN.prepareRHS(j);
    CN.solveTridiagonalSystem();
    CN.swapVs();
  }
}

template <typename DCO_TYPE> void several_time_steps_make_gap(int from, int to, CrankNicholson<DCO_TYPE>& CN) {

  auto tape = dco::tape(CN.xmin);
  std::vector<DCO_TYPE> VPrev_in(CN.Vprev);

  tape->switch_to_passive();
  for (int j = from; j >= to; j--) {
    CN.setBoundaryConditions(j, CN.Vcurr);
    CN.prepareLHS(j);
    CN.RHSj = &CN.Vcurr[1];
    CN.prepareRHS(j);
    CN.solveTridiagonalSystem();
    CN.swapVs();
  }
  tape->switch_to_active();

  for (int i = 0; i < CN.XP_p->N + 2; i++)
    tape->register_variable(CN.Vprev[i]);
  std::vector<DCO_TYPE> VPrev_out(CN.Vprev);

  auto fill_gap = [=]() {
    auto gap_begin = tape->get_position();
    CrankNicholson<DCO_TYPE> CN;
    std::vector<DCO_TYPE> indep(CN.XP_p->N + 2);
    for (int i = 0; i < CN.XP_p->N + 2; i++) {
      tape->register_variable(CN.Vprev[i]);
      indep[i] = CN.Vprev[i];
      dco::value(CN.Vprev[i]) = dco::value(VPrev_in[i]);
    }
    auto local_computation_begin = tape->get_position();
    several_time_steps(from, to, CN);
    for (int i = 0; i < CN.XP_p->N + 2; i++)
      tape->register_output_variable(CN.Vprev[i]);

#ifndef TIMING
    std::cerr << "Tape size (after taping " << from - to + 1 << " time steps: " << dco::size_of(tape) << "B\n\n";
#endif

    for (int i = 0; i < CN.XP_p->N + 2; i++)
      dco::derivative(CN.Vprev[i]) = dco::derivative(VPrev_out[i]);

    tape->interpret_adjoint_and_reset_to(local_computation_begin);

#ifndef TIMING
    std::cerr << "Tape size (after interpreting " << from - to + 1 << " time steps: " << dco::size_of(tape) << "B\n\n";
#endif

    for (int i = 0; i < CN.XP_p->N + 2; i++)
      dco::derivative(VPrev_in[i]) += dco::derivative(indep[i]);
    tape->reset_to(gap_begin);
  };

  tape->insert_callback(std::move(fill_gap));
}

template <typename ATYPE>
void price(const ACTIVE_INPUTS<ATYPE>& X, const PASSIVE_INPUTS& XP, ACTIVE_OUTPUTS<ATYPE>& Y) {
  // typedef typename dco::mode<ATYPE> DCO_MODE;
  CrankNicholson<ATYPE>::X_p = &X;
  CrankNicholson<ATYPE>::XP_p = &XP;
  CrankNicholson<ATYPE>::tmin = 0.0;
  CrankNicholson<ATYPE>::tmax = X.T;
  CrankNicholson<ATYPE> CN;
  const ATYPE logS0 = log(X.S0);
  const ATYPE atmvol = sqrt(X.T * X.sigmaSq(logS0, X.T));
  const int C = 10;
  const ATYPE dx = 2 * C * atmvol / (XP.N + 1);
  const ATYPE xmin = logS0 - XP.N / 2 * dx;
  CrankNicholson<ATYPE>::xmin = xmin;
  const ATYPE xmax = xmin + (XP.N + 1) * dx;
  CN.xmax = xmax;
  CrankNicholson<ATYPE>::xmax = xmax;

  CN.setBoundaryConditions(XP.M + 1, CN.Vprev);
  for (int j = XP.M; j >= 0; j -= checkpoint_distance) {
    int to = std::max(j - checkpoint_distance + 1, 0);
    several_time_steps_make_gap<ATYPE>(j, to, CN);
  }
  Y.V = CN.Vprev[XP.N / 2];
}

} // namespace pde
