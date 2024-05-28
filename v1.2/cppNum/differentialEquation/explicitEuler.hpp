// info@stce.rwth-aachen.de
#pragma once
#include "integrator.hpp"
#include "equation.hpp"

namespace de {

  /// Explicit Euler solver for initial value problems
  template<typename T>
  class explicitEuler_integrator_t : public integrator_t<T> { 
      using integrator_t<T>::_states; using integrator_t<T>::_times;
      using integrator_t<T>::_t_end; using integrator_t<T>::_number_of_steps;
      using integrator_t<T>::_trace;
    public:
      /// constructor sets target time, number of time steps, and tracing mode 
      explicitEuler_integrator_t(const T& t_end, int number_of_steps, bool trace=false);
      /// integrator allows internal overwrites of x 
      T run(T x, const T& p);
  };

}

#include "explicitEuler.cpp" 
