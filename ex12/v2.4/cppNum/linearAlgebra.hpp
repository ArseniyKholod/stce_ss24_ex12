// info@stce.rwth-aachen.de
#pragma once

#include "Eigen/Dense"
#include "exceptions/is_approx.hpp"
#include "exceptions/math_error.hpp"
#include <string>

namespace la {

  template<typename T, int N=Eigen::Dynamic>
  using vector_t=Eigen::Matrix<T,N,1>;

  template<typename T, int M=Eigen::Dynamic, int N=M>
  using matrix_t=Eigen::Matrix<T,M,N>;

  template<typename T>
  struct lu_solver_t {
    static la::vector_t<T> run(const la::matrix_t<T>& A, const la::vector_t<T>& b) {
      //matrix have to be square
      if(A.cols() != A.rows())
        throw(math_error(std::string(std::string("Matrix is not square, LU decomposition is not \
                                                  applicable"))));
      //matrix and vector must have equal number of rows
      if(A.rows() != b.rows())
        throw(math_error(std::string(std::string("Matrix and rhs-vector have diffirent number of \
						  rows, linear system is not uniquely solvable"))));
      //matrix have to be invertible 
      if(A.determinant() == 0)
	throw(math_error(std::string("Matrix is singular, applying LU algorithm for solving a \
				      linear system is not possible.")));

      return A.lu().solve(b);
    }
  };

  template<typename T>
  struct llt_solver_t {
    static la::vector_t<T> run(const la::matrix_t<T>& A, const la::vector_t<T>& b) {
      //matrix have to be squared
      if(A.cols() != A.rows())
        throw(math_error(std::string(std::string("Matrix is not square, LLT decomposition is not \
                                                  applicable"))));
      //matrix and vector must have equak number of rows
      if(A.rows() != b.rows())
        throw(math_error(std::string(std::string("Matrix and rhs-vector have diffirent number of \
						  rows, linear system is not uniquely solvable"))));
      //matrix have to be invertible
      if(A.determinant() == 0)
        throw(math_error(std::string("Matrix is singular, applying LLT algorithm for solving a \
                                      linear system is not possible.")));
      //matrix have to be positive definite
      Eigen::LDLT<la::matrix_t<T>> ldlt(A);
      if(!ldlt.isPositive())
	throw(math_error(std::string("Matrix is not positiv definite, LLT decomposition is not \
				      applicable.")));
      //matrix have to be symmetric
      if(A.transpose() != A)
        throw(math_error(std::string("Matrix is not symmetric, LLT decomposition is not \
                                      applicable.")));

      return A.llt().solve(b);
    }
  };

}
