// info@stce.rwth-aachen.de

#pragma once

#include "cppNum/differentialEquation/equation.hpp"

template<typename T>
T de::equation_t::g(const T &x, const T &p) {
  return -p*x;
}
