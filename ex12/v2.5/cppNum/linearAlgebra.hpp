// info@stce.rwth-aachen.de
#pragma once

#include "Eigen/Dense"

namespace la {

  template<typename T, int N=Eigen::Dynamic>
  using vector_t=Eigen::Matrix<T,N,1>;

  template<typename T, int M=Eigen::Dynamic, int N=M>
  using matrix_t=Eigen::Matrix<T,M,N>;

  template<typename T>
  struct lu_solver_t {
    static la::vector_t<T> run(const la::matrix_t<T>& A, const la::vector_t<T>& b) { 
      return A.lu().solve(b);
    }
  };

  template<typename T>
  struct llt_solver_t {
    static la::vector_t<T> run(const la::matrix_t<T>& A, const la::vector_t<T>& b) { 
      return A.llt().solve(b);
    }
  };

}
