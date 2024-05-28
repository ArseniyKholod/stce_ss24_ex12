// info@stce.rwth-aachen.de
#pragma once

#include "linearAlgebra.hpp"
#include <vector>
#include <string>

template<typename T>
class iteration_t {
  protected:
    std::vector<la::vector_t<T>> _states;
  public:
    virtual void plot(const std::string& filename, int i) const=0;
};
