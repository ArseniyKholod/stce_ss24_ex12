// info@stce.rwth-aachen.de
#pragma once

#include "cppNum/approximation.hpp"
#include <string>

namespace ae {
  /// abstract base for solvers of algebraic equations 
  template<typename T>
  class solver_t : public approximation_t<T> {
    protected:
      using approximation_t<T>::_states;   
      using approximation_t<T>::_parameter;   
    public:
      /// constructor sets desired accuracy of approximation and tracing mode
      solver_t(const T& accuracy, bool trace);
      /// pure virtual solution method allows internal overwrites of x 
      virtual T run(T x, const T& p)=0;
      /// record of states visited during iteration is written to file with given name
      void plot(const std::string& filename) const;
  };
}

#include "solver.cpp" // implementations of member functions
