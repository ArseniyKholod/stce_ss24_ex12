#include "cppNum/algebraicEquation/newton.hpp"
#include "cppNum/algebraicEquation/equation.hpp"

#include <iostream>
#include <cmath>
#include <limits>

namespace de {

  template<typename T>
  implicitEuler_integrator_t<T>::implicitEuler_integrator_t(const T& t_end, int number_of_steps, float accuracy, bool trace) : integrator_t<T>(t_end,number_of_steps), _accuracy(accuracy), _trace(trace) {}

  template<typename T>
  template<typename ae_T, typename DATA_T>
  ae_T implicitEuler_integrator_t<T>::f(const ae_T &x, const ae_T& p, const DATA_T* const data_p) {
    return x-data_p->x_prev-data_p->dt*equation_t::g(x,p);
  }

  template<typename T>
  T implicitEuler_integrator_t<T>::run(T x, const T &p) {
    T t=0, dt=_t_end/_number_of_steps;
    if (_trace) { _states.push_back(x); _times.push_back(t); }
    struct data_t { T x_prev,dt; } data;
    ae::newton_solver_t<T,data_t,implicitEuler_integrator_t<T>> ae_solver(_accuracy,&data);
    data.dt=dt;
    do {
      t+=dt;
      data.x_prev=x; 
      x=ae_solver.run(x,p);
      if (_trace) { _states.push_back(x); _times.push_back(t); }
    } while (t<_t_end);
    return x;
  }

}
