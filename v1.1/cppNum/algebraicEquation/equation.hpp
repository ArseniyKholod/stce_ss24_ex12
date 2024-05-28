// info@stce.rwth-aachen.de
#pragma once

namespace ae {

  /// host for static residual of the algebraic equation 
  struct equation_t {
    /// residual 
    template<typename T>
    static T f(const T& x, const T& p);
  };

}
