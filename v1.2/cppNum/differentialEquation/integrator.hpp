// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/evolution.hpp"

namespace de {

  /// abstract base class for solvers of initial value problems
  template<typename T>
  class integrator_t : public evolution_t<T> { 
    protected:
      using evolution_t<T>::_trace;
      /// target time
      T _t_end; 
      /// number of time steps performed during integration
      int _number_of_steps=1;
    public:
      /// constructor sets target time, number of times steps and tracing mode
      integrator_t(const T& t_end, int number_of_steps, bool trace);
      /// integrator allowing internal overwrites of x required by all specializations
      virtual T run(T x, const T& p)=0;
  };

}

#include "integrator.cpp" 
