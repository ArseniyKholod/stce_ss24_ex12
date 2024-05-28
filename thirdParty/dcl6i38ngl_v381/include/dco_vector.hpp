/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once
#ifdef DCO_CPP11

#include "dco_vector_math.hpp"
#include "dco_vector_traits.hpp"

namespace dco {
namespace vector_ns {

template <typename FLOAT_T, size_t VECTOR_SIZE> struct alignas(alignof(FLOAT_T[VECTOR_SIZE])) vector_t {
  static const size_t _vector_size = VECTOR_SIZE;
  static const size_t _vector_level = traits::type_info<FLOAT_T>::vector_level + 1;

  typedef FLOAT_T float_t;

  float_t _values[_vector_size];

  DCO_VECTOR_INLINE float_t const& operator[](size_t const i) const noexcept { return _values[i]; }
  DCO_VECTOR_INLINE float_t& operator[](size_t const i) noexcept { return _values[i]; }

  DCO_VECTOR_INLINE float_t const& _scalarvalue() const { return _values[0]; }
  DCO_VECTOR_INLINE float_t& _scalarvalue() { return _values[0]; }

  DCO_VECTOR_INLINE vector_t() noexcept {
    auto const& initval = float_t();
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = initval;
    }
  }

  DCO_VECTOR_INLINE vector_t(vector_t const& other) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = other._values[i];
    }
  }

  template <class OTHERFLOAT_T> DCO_VECTOR_INLINE vector_t(vector_t<OTHERFLOAT_T, _vector_size> const& other) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = static_cast<float_t>(other._values[i]);
    }
  }

  template <class OTHERFLOAT_T, typename TI = traits::type_info<vector_t>,
            typename check_vs = typename std::enable_if<(TI::vector_size > 1)>::type>
  DCO_VECTOR_INLINE vector_t(vector_t<OTHERFLOAT_T, 1> const& other) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = static_cast<float_t>(other._values[0]);
    }
  }

  DCO_VECTOR_INLINE vector_t& operator=(vector_t const& other) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = other._values[i];
    }
    return *this;
  }

  template <class OTHERFLOAT_T>
  DCO_VECTOR_INLINE vector_t& operator=(vector_t<OTHERFLOAT_T, _vector_size> const& other) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = static_cast<float_t>(other._values[i]);
    }
    return *this;
  }

  DCO_VECTOR_INLINE vector_t(float_t const& scalar) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = scalar;
    }
  }

  template <typename TSCALAR, typename TI = traits::type_info<TSCALAR>,
            typename check_vl = typename std::enable_if<!(TI::vector_level >= _vector_level)>::type>
  DCO_VECTOR_INLINE vector_t(TSCALAR const& s) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = static_cast<float_t>(s);
    }
  }

#ifndef DCO_VECTOR_EXCLUDE_ASSIGNMENT_DEFINITION
  DCO_VECTOR_INLINE vector_t& operator=(float_t const& scalar) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = scalar;
    }
    return *this;
  }
#endif

  template <class OTHERFLOAT_T, typename TI = traits::type_info<OTHERFLOAT_T>,
            typename check_arithmetic = typename std::enable_if<TI::is_arithmetic>::type>
  DCO_VECTOR_INLINE vector_t& operator=(OTHERFLOAT_T const& scalar) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = static_cast<float_t>(scalar);
    }
    return *this;
  }

  template <class LAMBDA_T>
  DCO_VECTOR_INLINE vector_t(::dco::vector_ns::ctor_lambda_t const&, LAMBDA_T const& lambda) noexcept {
    for (size_t i = 0; i < _vector_size; ++i) {
      _values[i] = lambda(i);
    }
  }

  template <class OTHERFLOAT_T, class TI = traits::type_info<OTHERFLOAT_T>,
            typename check_arithmetic = typename std::enable_if<TI::is_arithmetic>::type>
  DCO_VECTOR_INLINE vector_t& operator+=(OTHERFLOAT_T const& rhs) {
    *this = *this + rhs;
    return *this;
  }

  template <class OTHERFLOAT_T, class TI = traits::type_info<OTHERFLOAT_T>,
            typename check_arithmetic = typename std::enable_if<TI::is_arithmetic>::type>
  DCO_VECTOR_INLINE vector_t& operator*=(OTHERFLOAT_T const& rhs) {
    *this = *this * rhs;
    return *this;
  }
};
} // namespace vector_ns
} // namespace dco

#include "dco_vector_operations.hpp"

#if defined __AVX2__ || defined __AVX__

#include "dco_vector_avx_operations.hpp"

#else
#ifndef DCO_DISABLE_AVX2_WARNING
#ifdef _MSC_VER
#pragma message(                                                                                                       \
    "WARNING: Your compiler has C++11 capabilities, i.e. vector type is enabled; but no AVX2 seems to be available; if AVX2 is supported by your CPU, you might have to use '/arch:AVX2' as compilation flag. Otherwise, if you cannot or don't want to use AVX2, you can disable this warning by defining 'DCO_DISABLE_AVX2_WARNING'.")
#else
#warning                                                                                                               \
    "Your compiler has C++11 capabilities, i.e. vector type is enabled; but no AVX2 seems to be available; if AVX2 is supported by your CPU, you might have to use '-march=native' as compilation flag. Otherwise, if you cannot or don't want to use AVX2, you can disable this warning by defining 'DCO_DISABLE_AVX2_WARNING'."
#endif
#endif
#endif

namespace dco {
template <typename FLOAT_T, size_t VECTOR_SIZE> struct gv {

  static_assert(std::is_fundamental<FLOAT_T>::value, "dco::gv<...> can only be used with fundamental types");

  typedef vector_ns::vector_t<FLOAT_T, VECTOR_SIZE> type;
  typedef type active_t;

  typedef type active_value_t;
  typedef type value_t;
  typedef FLOAT_T scalar_value_t;
  typedef type passive_t;
  typedef scalar_value_t scalar_passive_t;
  typedef internal::data_g<gv> data_t;
  typedef void derivative_t;
  typedef void tape_t;
  typedef void local_gradient_t;
  typedef void local_gradient_with_activity_t;
  typedef void external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = false;
  static const bool is_vector_type = true;
  static const int order = dco::mode<scalar_value_t>::order;
  static const int vector_size = VECTOR_SIZE;

  static const size_t p1f_size = 0;
};

template <typename FLOAT_T, size_t VECTOR_SIZE>
struct mode<vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>> : public gv<FLOAT_T, VECTOR_SIZE> {};

template <typename FLOAT_T, size_t VECTOR_SIZE> FLOAT_T vsum(vector_ns::vector_t<FLOAT_T, VECTOR_SIZE> const& x) {
  FLOAT_T ret = 0;
  for (size_t i = 0; i < VECTOR_SIZE; ++i) {
    ret += x[i];
  }
  return ret;
}

namespace folding {

template <typename T>
struct is_zero_trait<T, typename dco::enable_if<(vector_ns::traits::type_info<T>::vector_level > 0)>::type> {
  static bool get(const T& x) {
    for (size_t i = 0; i < T::_vector_size; ++i) {
      if (!is_zero_trait<typename vector_ns::traits::type_info<T>::vector_scalar_t>::get(x[i])) {
        return false;
      }
    }
    return true;
  }
};

} // namespace folding

namespace internal {
template <class FLOAT_T, size_t VECTOR_SIZE> struct passive_value_type_of<vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>> {
  typedef typename passive_value_type_of<FLOAT_T>::TYPE TYPE;
};
} // namespace internal

template <typename T, typename enable_if = void> struct has_vector_type {
  static const bool value = false;
  static const size_t size = 0;
  using type = void;
};

template <typename T> struct has_vector_type<T, typename enable_if<(mode<T>::vector_size > 0)>::type> {
  static const bool value = true;
  static const size_t size = mode<T>::vector_size;
  using type = T;
};

template <typename T>
struct has_vector_type<T, typename enable_if<mode<T>::is_tangent_type || mode<T>::is_adjoint_type>::type> {
  static const bool value = has_vector_type<typename mode<T>::value_t>::value;
  static const size_t size = has_vector_type<typename mode<T>::value_t>::size;
  using type = typename has_vector_type<typename mode<T>::value_t>::type;
};

template <typename TYPE, typename = typename enable_if<has_vector_type<TYPE>::value>::type>
DCO_ALWAYS_INLINE typename mode<TYPE>::type vmask(std::bitset<has_vector_type<TYPE>::size> const& mask, TYPE const& v) {
  typename has_vector_type<TYPE>::type mask_vector;
  for (size_t i = 0; i < has_vector_type<TYPE>::size; ++i) {
    mask_vector[i] = mask[i];
  }
  return mask_vector * v;
}

template <typename TYPE> DCO_ALWAYS_INLINE typename mode<TYPE>::type vmask(bool const& mask, TYPE const& v) {
  if (mask == false)
    return typename mode<TYPE>::type();
  return v;
}

template <typename TYPE, typename = typename enable_if<has_vector_type<TYPE>::value>::type>
DCO_ALWAYS_INLINE typename mode<TYPE>::type vmask(range_t<has_vector_type<TYPE>::size> const& range, TYPE const& v) {
  if (range.is_last()) {
    typename has_vector_type<TYPE>::type mask_vector;
    for (auto i : range) {
      mask_vector[i.sub_index] = 1.0;
    }
    return mask_vector * v;
  }
  return v;
}

template <typename FLOAT_T, size_t VECTOR_SIZE>
void vpack(range_t<VECTOR_SIZE> const& range, FLOAT_T const* x, vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>& xv) {
  for (auto i : range)
    xv[i.sub_index] = x[i.global_index];
}

template <typename FLOAT_T, size_t VECTOR_SIZE>
void vunpack(range_t<VECTOR_SIZE> const& range, vector_ns::vector_t<FLOAT_T, VECTOR_SIZE> const& xv, FLOAT_T* x) {
  for (auto i : range)
    x[i.global_index] = xv[i.sub_index];
}

template <typename FLOAT_T, size_t VECTOR_SIZE, typename DATA_T, typename VDATA_T>
void vpack(range_t<VECTOR_SIZE> const& range, internal::active_type<FLOAT_T, DATA_T> const* x,
           internal::active_type<vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>, VDATA_T>& xv) {
  for (auto i : range)
    dco::value(xv)[i.sub_index] = dco::value(x[i.global_index]);
}

template <typename FLOAT_T, size_t VECTOR_SIZE, typename DATA_T, typename VDATA_T>
void vunpack(range_t<VECTOR_SIZE> const& range,
             internal::active_type<vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>, VDATA_T> const& xv,
             internal::active_type<FLOAT_T, DATA_T>* x) {
  for (auto i : range)
    dco::value(x[i.global_index]) = dco::value(xv)[i.sub_index];
}

} // namespace dco

#endif
