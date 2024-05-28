// info@stce.rwth-aachen.de

#pragma once

#include "cppNum/evolution.hpp"
#include <vector>

namespace de {

  template<typename T>
  class integrator_t : public evolution_t<T> {
    protected:
      T _t_end;
      int _number_of_steps=1;
    public:
      integrator_t(const T&, int);
      virtual T run(T, const T&)=0;
  };

}

namespace de {

  template<typename T>
  integrator_t<T>::integrator_t(const T& t_end, int number_of_steps) : _t_end(t_end), _number_of_steps(number_of_steps) {}

}
