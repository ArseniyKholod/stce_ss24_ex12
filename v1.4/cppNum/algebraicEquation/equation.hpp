// info@stce.rwth-aachen.de
#pragma once

namespace ae {

  struct equation_t {
    template<typename T>
    static T f(const T& x, const T& p);
  };

}
