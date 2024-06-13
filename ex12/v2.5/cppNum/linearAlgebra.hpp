// info@stce.rwth-aachen.de
#pragma once

#include "Eigen/Dense"
#include "exceptions/math_error.hpp"
#include <iostream>

namespace la {

  template<typename T, int N=Eigen::Dynamic>
  using vector_t=Eigen::Matrix<T,N,1>;

  template<typename T, int M=Eigen::Dynamic, int N=M>
  using matrix_t=Eigen::Matrix<T,M,N>;

  template<typename T>
  struct lu_solver_t {
    static la::vector_t<T> run(const la::matrix_t<T>& A, const la::vector_t<T>& b) {
      try{
        //matrix have to be square
        if(A.cols() != A.rows())
          throw(ex::math_error("Matrix is not square, LU decomposition is not applicable"));
        //matrix and vector must have equal number of rows
        if(A.rows() != b.rows())
          throw(ex::math_error("Matrix and rhs-vector have diffirent number of rows, linear system is not uniquely solvable"));
        //matrix have to be invertible 
        if(A.determinant() == 0)
          throw(ex::math_error("Matrix is singular, applying LU algorithm for solving a linear system is not possible."));
        return A.lu().solve(b);
      }
      catch(...){
        std::cerr<<"Exception was caught in la::lu_solver_t::run, throw it further."<<std::endl;
        throw;
      }
    }
  };

  template<typename T>
  struct llt_solver_t {
    static la::vector_t<T> run(const la::matrix_t<T>& A, const la::vector_t<T>& b) {
      try{
        //matrix have to be squared
        if(A.cols() != A.rows())
          throw(ex::math_error("Matrix is not square, LLT decomposition is not applicable"));
        //matrix and vector must have equak number of rows
        if(A.rows() != b.rows())
          throw(ex::math_error("Matrix and rhs-vector have diffirent number of rows, linear system is not uniquely solvable"));
        //matrix have to be invertible
        if(A.determinant() == 0)
          throw(ex::math_error("Matrix is singular, applying LLT algorithm for solving a linear system is not possible."));
        //matrix have to be symmetric positive definite
        if(A.llt().info())
          throw(ex::math_error("Matrix is not symmetric positiv definite, LLT decomposition is not applicable."));
        return A.llt().solve(b);
      }
      catch(...){
        std::cerr<<"Exception was caught in la::llt_solver_t::run, throw it further."<<std::endl;
        throw;
      }
    }
  };

}
