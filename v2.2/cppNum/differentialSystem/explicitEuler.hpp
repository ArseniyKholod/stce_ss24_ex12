// info@stce.rwth-aachen.de
#pragma once

#include "integrator.hpp"
#include "system.hpp"

namespace ds {

  template<typename T>
  class explicitEuler_integrator_t : public integrator_t<T> {
      using integrator_t<T>::_states;
      using integrator_t<T>::_times;
      using integrator_t<T>::_t_end;
      using integrator_t<T>::_number_of_steps;
      using integrator_t<T>::_trace;
    public:
      explicitEuler_integrator_t(const T& t_end, int number_of_steps, bool trace=false);
      la::vector_t<T> run(la::vector_t<T> x, const la::vector_t<T>& p);
  };

}

namespace ds {

  template<typename T>
  explicitEuler_integrator_t<T>::explicitEuler_integrator_t(const T& t_end, int number_of_steps, bool trace) : integrator_t<T>(t_end,number_of_steps,trace) {}

  template<typename T>
  la::vector_t<T> explicitEuler_integrator_t<T>::run(la::vector_t<T> x, const la::vector_t<T>& p) {
    T t=0, dt=_t_end/_number_of_steps;
    if (_trace) { _states.push_back(x); _times.push_back(t); }
    for (int i=0;i<_number_of_steps;++i) {
      t+=dt;
      x+=dt*system_t::G(x,p); 
      if (_trace) { _states.push_back(x); _times.push_back(t); }
    } 
    return x;
  }

}
