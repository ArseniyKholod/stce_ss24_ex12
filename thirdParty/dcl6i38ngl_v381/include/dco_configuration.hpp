/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#if (defined(min) || defined(max)) && !defined(DCO_DISABLE_MINMAX_ERROR)
#ifdef WIN32
#error                                                                                                                 \
    "dco/c++ error: 'min' or 'max' macro definitions detected. If you include 'windows.h', make sure to define NOMINMAX before."
#else
#error "dco/c++ error: 'min' or 'max' macro definitions detected. Please avoid."
#endif
#endif

//** This sets the maximal log level that can be switched on at run
//** time. Caution: A high log level has negative performance impact,
//** even though dco::logger::level() is set to -1.
#ifndef DCO_LOG_MAX_LEVEL
#define DCO_LOG_MAX_LEVEL -1
#endif

//** If set, tangents are propagated only when the tangent components are nonzero
#ifdef DCO_GT1S_ACTIVITY
static const bool HAS_GT1S_ACTIVITY_CHECK = true;
#else
static const bool HAS_GT1S_ACTIVITY_CHECK = false;
#endif

//** This defines whether to use chunk tape or not. When using chunk
//** tape, the file tape can be used as well.
#ifdef DCO_CHUNK_TAPE
#define DCO_TAPE_MEMORY_MODEL memory_model::CHUNK_TAPE
#else
#define DCO_TAPE_MEMORY_MODEL memory_model::BLOB_TAPE_SPLINT
#endif

//** define basic integer type for tape index
#define DCO_INT32 int
#ifdef _MSC_VER
#define DCO_INT64 __int64
#else
#define DCO_INT64 int64_t
#endif

#ifdef DCO_TAPE_USE_LONG_INT
#define index_t_DEFINE long int
#else
#ifdef DCO_TAPE_USE_INT64
#ifdef _MSC_VER
#define index_t_DEFINE __int64
#else
#define index_t_DEFINE int64_t
#endif
#else
#define index_t_DEFINE int
#endif
#endif

//** undocumented feature:
//** this macro enables a constructor taking the type passed as argument
#define DCO_ENABLE_TYPE_CONSTRUCTION_FROM(T)                                                                           \
  namespace dco {                                                                                                      \
  template <typename T2> struct dco_type_constructable_from<T, T2> {                                                   \
    typedef T2 type;                                                                                                   \
  };                                                                                                                   \
  }

//** this macro enables an explicit cast operation to the type passed as argument
//** see https://en.cppreference.com/w/cpp/language/cast_operator
#define DCO_ENABLE_EXPLICIT_TYPE_CAST_TO(T)                                                                            \
  namespace dco {                                                                                                      \
  template <> struct dco_explicit_type_cast_to<T> {                                                                    \
    static const bool value = true;                                                                                    \
  };                                                                                                                   \
  }

//** if using compiler with C++11 support, additional features are
//** enabled automatically; DCO_CPP11 can also be defined manually, if
//** compiler doesn't set __cpluscplus correctly.
#ifndef DCO_CPP11
#if (__cplusplus > 199711L) || (_MSC_VER >= 1900)
#define DCO_CPP11
#else
#error "dco/c++: By default, only C++11 is supported. Please contact NAG if you need support for C++98."
#endif
#endif

//** if using compiler with C++17 support
#ifndef DCO_CPP17
//** 2019 the first one to support all the features used in dco_traits.hpp.
//** Microsoft Compiler Version 19.22.27905 returns compiler errors:
//** \src\dco_data_tape_base.hpp(9): error C3646: 'derivative_t': unknown override specifier
#if (__cplusplus >= 201703L) || (_MSC_VER > 1922)
#if (!defined DCO_NOCPP11) && (!defined DCO_NOCPP17)
#define DCO_CPP17
#endif
#endif
#endif

//** important if using compiler with C++11 support;
//**   when using auto and a template expression library, local references dangle
//**   if using auto, make sure to define DCO_AUTO_SUPPORT
//***   performance implications: might slow down recording when working with long right-hand-sides
#if defined DCO_CPP11 && !defined DCO_AUTO_SUPPORT && !defined DCO_DISABLE_AUTO_WARNING
#ifdef _MSC_VER
#pragma message(                                                                                                       \
    "WARNING: Your compiler has C++11 capabilities. If you are using 'auto', make sure 'DCO_AUTO_SUPPORT' is defined. You can disable this warning by defining 'DCO_DISABLE_AUTO_WARNING'.")
#else
#  warning Your compiler has C++11 capabilities. If you are using 'auto', make sure 'DCO_AUTO_SUPPORT' is defined. You can disable this warning by defining 'DCO_DISABLE_AUTO_WARNING'.
#endif
#endif

#ifdef DCO_AUTO_SUPPORT
#define DCO_TEMPORARY_REFORCOPY
#else
#define DCO_TEMPORARY_REFORCOPY &
#endif

#ifndef DCO_NO_THREADLOCAL
#if defined(DCO_FORCE_THREADLOCAL_KEYWORD)
#define DCOi_THREAD_LOCAL thread_local
#else
#if defined(_MSC_VER)
#define DCOi_THREAD_LOCAL __declspec(thread)
#else
#ifdef DCO_CPP11
#define DCOi_THREAD_LOCAL thread_local
#else
#define DCOi_THREAD_LOCAL __thread
#endif
#endif
#endif
#else
#define DCOi_THREAD_LOCAL
#endif

//** use DEPRECATED to generate compiler-warnings, if a marked
//** function is instantiated (only implemented for gnu compiler and
//** VisualC++)
#if __GNUC__
#define DCO_DEPRECATED __attribute__((deprecated))
#elif defined(_WIN32)
#define DCO_DEPRECATED __declspec(deprecated)
#else
#define DCO_DEPRECATED
#endif

//** can be used to force inlining by the compiler
#if defined(_MSC_VER)
#define DCO_STRONG_INLINE inline
#define DCO_ALWAYS_INLINE __forceinline
//** not supported by MSVC
#define DCO_ALWAYS_INLINE_LAMBDA
#else
#define DCO_STRONG_INLINE inline
#define DCO_ALWAYS_INLINE __attribute__((always_inline)) inline
#define DCO_ALWAYS_INLINE_LAMBDA __attribute__((always_inline))
#define DCO_AGRESSIVE_INLINE
#endif

#if defined DCO_NO_AGRESSIVE_INLINE && defined DCO_AGRESSIVE_INLINE
#undef DCO_AGRESSIVE_INLINE
#endif

#ifdef DCO_AGRESSIVE_INLINE
#define DCO_ALWAYS_INLINE_IF_AGRESSIVE DCO_ALWAYS_INLINE
#else
#define DCO_ALWAYS_INLINE_IF_AGRESSIVE DCO_STRONG_INLINE
#endif

//** when computing sqrt(type(0)), the values are well-defined, but
//** the derivatives are not (DIVZERO). If you know what you do, you
//** can avoid this by setting this define. dco/c++ then computes the
//** partial as 1 / 2*sqrt(DCO_SQRT_EPS).
#ifndef DCO_SQRT_EPS
#define DCO_SQRT_EPS 1e-22
#endif
namespace dco {
#ifdef DCO_SQRT_AVOID_DIVZERO
static const bool HAS_SQRT_AVOID_DIVZERO = true;
#else
static const bool HAS_SQRT_AVOID_DIVZERO = false;
#endif
} // namespace dco

//** in this case, modulo adjoint propagation uses the bit-wise binary
//** & instead of modulo operation (%). For doing this, the adjoint
//** vector size needs to be a power of 2 => rounded up.
namespace dco {
#ifdef DCO_BITWISE_MODULO
static const bool HAS_BITWISE_MODULO = true;
#else
static const bool HAS_BITWISE_MODULO = false;
#endif
#ifdef DCO_DEBUG
static const bool IS_DEBUG = true;
#else
static const bool IS_DEBUG = false;
#endif
} // namespace dco

//** use this define to have intrinsic computations when using
//** complex types. This will enforce that the primals are equal
//** to the ones computed using the std complex kernels.
namespace dco {
#ifdef DCO_USE_INTRINSIC_COMPLEX_PRIMALS
static const bool HAS_INTRINSIC_COMPLEX_PRIMALS = true;
#else
static const bool HAS_INTRINSIC_COMPLEX_PRIMALS = false;
#endif
} // namespace dco

//** use this define to have interoperability with boost::interval
//**   remark: this requires DCO_STD_COMPATIBILITY as well.
#ifdef DCO_INTEROPERABILITY_BOOST_INTERVAL
#ifndef DCO_STD_COMPATIBILITY
#define DCO_STD_COMPATIBILITY
#endif
#endif
