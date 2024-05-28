// info@stce.rwth-aachen.de
#pragma once

#include "cppNum/linearAlgebra.hpp"

namespace as {

  struct system_t {
    template<typename T, typename DATA_T=void>
    static la::vector_t<T> F(const la::vector_t<T>& x, const la::vector_t<T>& p, const DATA_T* const data=nullptr);
  };

}
