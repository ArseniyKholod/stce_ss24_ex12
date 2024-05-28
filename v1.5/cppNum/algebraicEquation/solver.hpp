// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/approximation.hpp"
#include <string>

namespace ae {
  /// abstract base for solvers of algebraic equations
  template<typename T, typename DATA_T, typename EQUATION_T>
  class solver_t : public approximation_t<T> {
    protected:
      using approximation_t<T>::_parameter; using approximation_t<T>::_states;  
      /// tracing on/off
      bool _trace;
      /// pointer to auxiliary data
      const DATA_T* const _data_p;
    public:
      /// accuracy, tracing mode and pointer to auxiliary data set at time of construction
      solver_t(const T& accuracy, bool trace, const DATA_T* const data_p);
      /// solution method allowing side-effect-free overwrites of x required by all specializations
      virtual T run(T x, const T& p)=0;
      /// read-only access to traced states
      const std::vector<T>& get_states() const;
      /// writes trace to file
      void plot(const std::string&) const;
  };
}
#include "solver.cpp"
