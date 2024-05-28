// info@stce.rwth-aachen.de
#pragma once

#include "integrator.hpp"

namespace ds {

  template<typename T>
  class implicitEuler_integrator_t : public integrator_t<T> {
      using integrator_t<T>::_states;
      using integrator_t<T>::_times;
      using integrator_t<T>::_t_end;
      using integrator_t<T>::_number_of_steps;
      using integrator_t<T>::_trace;
      float _accuracy;
    public:
      implicitEuler_integrator_t(const T& t_end, int number_of_steps, const float& accuracy=1e-7, bool trace=false); 
      la::vector_t<T> run(la::vector_t<T> x, const la::vector_t<T>& p);
      template<typename AS_T, typename DATA_T>
      static la::vector_t<AS_T> F(const la::vector_t<AS_T> &x, const la::vector_t<AS_T>& p, const DATA_T* const data_p);
  };

}

#include "cppNum/algebraicSystem/newton.hpp"
#include "cppNum/algebraicSystem/system.hpp"

#include <iostream>
#include <cmath>
#include <limits>

namespace ds {

  template<typename T>
  implicitEuler_integrator_t<T>::implicitEuler_integrator_t(const T& t_end, int number_of_steps, const float& accuracy, bool trace) : integrator_t<T>(t_end,number_of_steps,trace), _accuracy(accuracy) {}

  template<typename T>
  template<typename AS_T, typename DATA_T>
  la::vector_t<AS_T> implicitEuler_integrator_t<T>::F(const la::vector_t<AS_T> &x, const la::vector_t<AS_T>& p, const DATA_T* const data_p) {
    la::vector_t<AS_T> r(x.size());
    for (int i=0;i<x.size();++i)
      r(i)=x(i)-data_p->x_prev(i)-(data_p->dt*system_t::G(x,p))(i);
    return r;
  }

  template<typename T>
  la::vector_t<T> implicitEuler_integrator_t<T>::run(la::vector_t<T> x, const la::vector_t<T> &p) {
    int n=x.size(), m=p.size(), as_m=n+m+2;
    la::vector_t<T> as_p(as_m), x_prev=x;
    T t=0, dt=_t_end/_number_of_steps;
    if (_trace) { _states.push_back(x); _times.push_back(t); }
    struct data_t { la::vector_t<T> x_prev; T dt; } data;
    as::newton_solver_t<T,implicitEuler_integrator_t<T>,data_t> as_solver(_accuracy,&data);
    data.dt=dt;
    do {
      t+=dt;
      data.x_prev=x;
      x=as_solver.run(x,p);
      if (_trace) { _states.push_back(x); _times.push_back(t); }
    } while (t<_t_end);
    return x;
  }

}
