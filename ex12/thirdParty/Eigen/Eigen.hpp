// info@stce.rwth-aachen.de

#pragma once

#include "Eigen/Dense"

namespace Eigen {

  template<typename T, int N=Dynamic>
  using vector_t=Matrix<T,N,1>;

  template<typename T, int M=Dynamic, int N=M>
  using matrix_t=Matrix<T,M,N>;

}
