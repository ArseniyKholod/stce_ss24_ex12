// info@stce.rwth-aachen.de

#pragma once

namespace de {

  // explicit nonlinear parameterized ordinary differential equation
  struct equation_t {
    template <typename T>
    static T g(const T& x, const T& p);
  };

}
