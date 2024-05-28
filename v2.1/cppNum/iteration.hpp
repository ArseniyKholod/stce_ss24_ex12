// info@stce.rwth-aachen.de
#pragma once

#include "linearAlgebra.hpp"
#include <vector>
#include <string>

template<typename T>
class iteration_t {
  protected:
    la::vector_t<T> _parameters;
    std::vector<la::vector_t<T>> _states;
    bool _trace;
  public:
    iteration_t(bool trace);
    virtual void plot(const std::string& filename, int i, int j) const=0;
};

template<typename T>
iteration_t<T>::iteration_t(bool trace) : _trace(trace) {}
