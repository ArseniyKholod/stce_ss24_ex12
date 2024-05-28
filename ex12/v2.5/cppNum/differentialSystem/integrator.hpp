// info@stce.rwth-aachen.de
#pragma once

#include "cppNum/evolution.hpp"

namespace ds {

  template<typename T>
  class integrator_t : public evolution_t<T> {
    protected:
      T _t_end;
      int _number_of_steps=1;
    public:
      integrator_t(const T& t_end, int number_of_steps, bool trace);
      virtual la::vector_t<T> run(la::vector_t<T> x, const la::vector_t<T>& p)=0;
  };

}

namespace ds {

  template<typename T>
  integrator_t<T>::integrator_t(const T& t_end, int number_of_steps, bool trace) : evolution_t<T>(trace), _t_end(t_end), _number_of_steps(number_of_steps) {}

}
