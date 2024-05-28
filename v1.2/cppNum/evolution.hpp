// info@stce.rwth-aachen.de
#pragma once

#include "iteration.hpp"
#include <vector>

/// abstract base class for integration methods for differential equations
template<typename T>
class evolution_t : public iteration_t<T> {
  protected:
    using iteration_t<T>::_states;
    /// values of times due to time steps performed 
    std::vector<T> _times;
    /// tracing mode
    bool _trace;
  public:
    /// tracing mode set at construction
    evolution_t(bool trace);
    /// writes record of states visited at recorded times to file with given name
    void plot(const std::string& filename) const;
};

#include "evolution.cpp" 
