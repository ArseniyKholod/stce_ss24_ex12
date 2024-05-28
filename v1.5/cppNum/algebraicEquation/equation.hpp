// info@stce.rwth-aachen.de
#pragma once

namespace ae {

  struct equation_t {
    template<typename T, typename DATA_T=void>
    static T f(const T& x, const T& p, const DATA_T* const data_p=nullptr);
  };

}
