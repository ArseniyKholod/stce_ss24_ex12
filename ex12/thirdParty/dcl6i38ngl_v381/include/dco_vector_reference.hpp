/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#include "dco_declarations.hpp"
#include "dco_helper.hpp"

namespace dco {
namespace internal {

template <typename CONT> struct reference_required_type {
  typedef CONT type;
  typedef CONT& ref_type;
  typedef const CONT const_type;
};
template <typename T> struct reference_required_type<std::vector<T>> {
  typedef std::vector<T>& type;
  typedef std::vector<T>& ref_type;
  typedef std::vector<T> const& const_type;
};

template <value_or_derivative_t value_or_derivative, typename T, typename ADJ_VEC_T = void>
struct value_derivative_getter {};

template <typename T> struct value_derivative_getter<VALUE, T> {
  typedef typename dco::mode<T>::value_t value_t;
  typedef typename trait_value<T>::return_t return_t;
  typedef typename trait_value<T>::const_return_t const_return_t;
  return_t get(T& x) { return trait_value<T>::value(x); };
  const_return_t get(const T& x) const { return trait_value<T>::value(x); };
};

template <typename T> struct value_derivative_getter<PASSIVE_VALUE, T> {
  typedef typename dco::mode<T>::passive_t value_t;
  typedef typename trait_passive_value<T>::return_t return_t;
  typedef typename trait_passive_value<T>::const_return_t const_return_t;
  return_t get(T& x) { return trait_passive_value<T>::value(x); };
  const_return_t get(const T& x) const { return trait_passive_value<T>::value(x); };
};

template <typename T> struct value_derivative_getter<DERIVATIVE, T> {
  typedef typename dco::mode<T>::derivative_t value_t;
  typedef typename trait_derivative<T>::return_t return_t;
  typedef typename trait_derivative<T>::return_t const_return_t;
  return_t get(const T& x) const { return trait_derivative<T>::value(x); };
};

template <typename T> struct value_derivative_getter<TAPE_INDEX, T> {
  typedef typename trait_tape_index<T>::return_t return_t;
  typedef typename trait_tape_index<T>::return_t const_return_t;
  typedef typename remove_ref<return_t>::type value_t;
  return_t get(const T& x) const { return trait_tape_index<T>::value(x); };
};

template <typename T, typename ADJ_VEC_T> struct value_derivative_getter<DERIVATIVE_EXT_ADJ, T, ADJ_VEC_T> {
  typedef typename dco::mode<T>::derivative_t value_t;
  typedef typename trait_derivative<T, ADJ_VEC_T>::split_return_t return_t;
  typedef typename trait_derivative<T, ADJ_VEC_T>::split_return_t const_return_t;

  ADJ_VEC_T* _adjoints;

  value_derivative_getter(ADJ_VEC_T* adjoints) : _adjoints(adjoints) {}

  auto get(T& x) -> decltype(trait_derivative<T, ADJ_VEC_T>::value(x, _adjoints)) {
    return trait_derivative<T, ADJ_VEC_T>::value(x, _adjoints);
  };
  auto get(const T& x) const -> decltype(trait_derivative<T, ADJ_VEC_T>::value(x, _adjoints)) {
    return trait_derivative<T, ADJ_VEC_T>::value(x, _adjoints);
  };
};

template <value_or_derivative_t value_or_derivative, class T, typename CONT, typename ADJOINT_VEC_T = void>
struct vector_reference : value_derivative_getter<value_or_derivative, T, ADJOINT_VEC_T> {
  typedef typename reference_required_type<CONT>::type container_t;
  typedef typename reference_required_type<CONT>::ref_type container_t_ref;
  typedef typename reference_required_type<CONT>::const_type const_container_t;
  typedef value_derivative_getter<value_or_derivative, T, ADJOINT_VEC_T> get_t;
  typedef typename get_t::value_t value_t;

  container_t _vec;

  vector_reference(const_container_t vec) : _vec(const_cast<container_t_ref>(vec)) {}

  vector_reference(const_container_t vec, ADJOINT_VEC_T* adj_vec)
      : get_t(adj_vec), _vec(const_cast<container_t_ref>(vec)) {}

  vector_reference& operator=(const std::vector<value_t>& rhs) {
    for (size_t i = 0; i < _vec.size(); ++i) {
      get_t::get(_vec[i]) = rhs[i];
    }
    return *this;
  }

  vector_reference& operator+=(const std::vector<value_t>& rhs) {
    for (size_t i = 0; i < _vec.size(); ++i) {
      get_t::get(_vec[i]) += rhs[i];
    }
    return *this;
  }

  vector_reference& operator=(value_t const& rhs) {
    for (size_t i = 0; i < _vec.size(); ++i) {
      get_t::get(_vec[i]) = rhs;
    }
    return *this;
  }

  template <typename VALUE_T, typename = typename std::enable_if<std::is_assignable<VALUE_T&, value_t>::value>::type>
  operator std::vector<VALUE_T>() const {
    std::vector<VALUE_T> ret(_vec.size());
    for (size_t i = 0; i < _vec.size(); ++i) {
      ret[i] = get_t::get(_vec[i]);
    }
    return ret;
  }

  typename get_t::return_t operator[](size_t i) { return get_t::get(_vec[i]); }

  typename get_t::const_return_t operator[](size_t i) const { return get_t::get(_vec[i]); }

  size_t size() const { return _vec.size(); }
};

} // namespace internal
} // namespace dco
