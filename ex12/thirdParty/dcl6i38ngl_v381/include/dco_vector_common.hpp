/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#define DCO_VECTOR_INLINE DCO_ALWAYS_INLINE
#define DCO_VECTOR_INLINE_LAMBDA DCO_ALWAYS_INLINE_LAMBDA

namespace dco {
namespace vector_ns {

template <typename T> int sign(T val) { return (T(0) < val) - (val < T(0)); }

template <typename FLOAT_T, size_t VECTOR_SIZE> struct vector_t;

struct ctor_lambda_t {};
enum ctor_lambda_e { ctor_lambda_default = 0 };
struct ctor_vsum_t {};
enum ctor_vsum_e { ctor_vsum_default = 0 };

enum ctor_vector_vv_e { ctor_vector_vv_default = 0 };
enum ctor_vector_vs_e { ctor_vector_vs_default = 0 };
enum ctor_vector_sv_e { ctor_vector_sv_default = 0 };
enum ctor_vector_1v_e { ctor_vector_1v_default = 0 };
enum ctor_vector_v1_e { ctor_vector_v1_default = 0 };

} // namespace vector_ns
} // namespace dco
