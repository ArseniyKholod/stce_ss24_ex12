// info@stce.rwth-aachen.de
#pragma once

namespace de {

  /// explicit nonlinear parameterized ordinary differential equation x'=g(x,p)
  struct equation_t {
    /// right-hand side to be provided by user
    template <typename T>
    static T g(const T& x, const T& p);
  };

}
