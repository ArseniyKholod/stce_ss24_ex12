// info@stce.rwth-aachen.de
#pragma once

#include "solver.hpp"

namespace ae {

  /// Newton solver for algebraic equation 
  template<typename T>
  class newton_solver_t : public solver_t<T> {
      using solver_t<T>::_states;
      using solver_t<T>::_parameter;
      using solver_t<T>::_accuracy;
      using solver_t<T>::_trace;
    public:
      /// constructon of instance with given accuracy; tracing disabled by default
      newton_solver_t(const T& accuracy, bool trace=false);
      /// solution method allows internal overwrites of x 
      T run(T x, const T& p);
  };

}

#include "newton.cpp" // implementations of member functions
