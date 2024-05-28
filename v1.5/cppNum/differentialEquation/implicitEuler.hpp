// info@stce.rwth-aachen.de
#pragma once
#include "integrator.hpp"

namespace de {
  /// implicit Euler method for solving the initial value problem x'=g(x,p); x(0)=x0
  template<typename T>
  class implicitEuler_integrator_t : public integrator_t<T> {
      using integrator_t<T>::_states; using integrator_t<T>::_times;
      using integrator_t<T>::_t_end; using integrator_t<T>::_number_of_steps;
      float _accuracy;
      bool _trace;
    public:
      /// constructor sets target time, number of time steps and tracing mode
      implicitEuler_integrator_t(const T& t_end, int number_of_steps, float accuracy=1e-7, bool trace=false); 
      /// implicit Euler integrator
      T run(T x, const T& p);
      /// algebraic equation solved in each time step requires additional data
      template <typename ae_T, typename DATA_T>
      static ae_T f(const ae_T&, const ae_T&, const DATA_T* const);
  };
}
#include "implicitEuler.cpp"
