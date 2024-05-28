// info@stce.rwth-aachen.de
#pragma once

#include "iteration.hpp"

/** abstract base for approximation algorithms augments iterative methods 
    with an accuracy to define convergence **/
template<typename T>
class approximation_t : public iteration_t<T> {
  protected:
    /// accuracy defines convergence of the iterative method
    T _accuracy;
  public:
    /// constructor sets desired accuracy of approximation and tracing mode
    approximation_t(const T& accuracy, bool trace);
};

#include "approximation.cpp" // implementations of member functions
