/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#ifdef DCO_EXT_EIGEN

template <class DCO_TAPE_REAL, class DATA_HANDLER>
struct Eigen::NumTraits<dco::internal::active_type<DCO_TAPE_REAL, DATA_HANDLER>>
    : Eigen::GenericNumTraits<typename dco::internal::active_type<DCO_TAPE_REAL, DATA_HANDLER>::VALUE_TYPE> {
  typedef dco::internal::active_type<DCO_TAPE_REAL, DATA_HANDLER> Real;
  typedef Real NonInteger;
  typedef Real Literal;
  typedef Real Nested;

  typedef typename dco::internal::active_type<DCO_TAPE_REAL, DATA_HANDLER>::VALUE_TYPE value_type;

  EIGEN_DEVICE_FUNC static inline Real epsilon() { return NumTraits<value_type>::epsilon(); }
  EIGEN_DEVICE_FUNC static inline Real dummy_precision() { return NumTraits<value_type>::dummy_precision(); }

  enum {
    IsComplex = NumTraits<value_type>::IsComplex,
    IsInteger = NumTraits<value_type>::IsInteger,
    ReadCost = NumTraits<value_type>::ReadCost,
    AddCost = NumTraits<value_type>::AddCost,
    MulCost = NumTraits<value_type>::MulCost,
    IsSigned = NumTraits<value_type>::IsSigned,
    RequireInitialization = NumTraits<value_type>::RequireInitialization
  };

  EIGEN_DEVICE_FUNC static inline Real lowest() {
    if (IsInteger) {
      return (numext::numeric_limits<value_type>::min)();
    } else {
      return -(numext::numeric_limits<value_type>::max)();
    }
  }
};

template <typename BinaryOp, typename REAL, typename DATA>
struct Eigen::ScalarBinaryOpTraits<dco::internal::active_type<REAL, DATA>, REAL, BinaryOp> {
  typedef dco::internal::active_type<REAL, DATA> ReturnType;
};

template <typename BinaryOp, typename REAL, typename DATA>
struct Eigen::ScalarBinaryOpTraits<REAL, dco::internal::active_type<REAL, DATA>, BinaryOp> {
  typedef dco::internal::active_type<REAL, DATA> ReturnType;
};
#endif
