// info@stce.rwth-aachen.de
#pragma once

#include "iteration.hpp"

template<typename T>
class approximation_t : public iteration_t<T> {
  protected:
    T _accuracy;
  public:
    approximation_t(const T&);
};

template<typename T>
approximation_t<T>::approximation_t(const T& accuracy) : _accuracy(accuracy) {}

