// info@stce.rwth-aachen.de
#pragma once

namespace co {

  /// convex objective f(x,p)
  struct objective_t {
    /// user-defined implementation of f is required
    template <typename T>
    static T f(const T& x, const T& p);
  };

}
