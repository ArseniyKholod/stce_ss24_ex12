/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <stack>
#include "g.hpp"
using namespace std;

enum RUN_MODE { CHECKPOINT_ARGUMENTS_AND_RUN_PASSIVELY, GENERATE_TAPE };

stack<pair<int, DCO_MODE::value_t>> state;

void g_make_gap(int from, int to, int stride, DCO_MODE::type& xg, RUN_MODE m = GENERATE_TAPE) {

  if (m == CHECKPOINT_ARGUMENTS_AND_RUN_PASSIVELY) {
    cout << "STORE CHECKPOINT FOR SECTION " << from << " ... " << to - 1 << endl;

    // write argument checkpoint (FIFO)
    if (state.empty() || from != state.top().first) {
      cout << "PUSHING (" << from << ", " << dco::value(xg) << ")" << endl;
      state.push(make_pair(from, dco::value(xg)));
    }

    // call passive version of f
    cout << "RUN SECTION " << from << " ... " << to - 1 << " PASSIVELY" << endl;
    g(from, to, stride, dco::value(xg));

    // register output x with tape and store its
    // position for retrieval of incoming adjoint required
    // during interpretation
    DCO_MODE::type xg_in(xg);
    dco::tape(xg)->register_variable(xg);

    auto fill_gap = [=]() {
      cout << "top=" << state.top().second << endl;
      cout << "RESTORE CHECKPOINT FOR SECTION " << from << " ... " << to - 1 << endl;
      DCO_TYPE x = state.top().second;
      dco::tape(xg)->register_variable(x);
      DCO_TYPE x_in = x;
      auto p = dco::tape(xg)->get_position();
      g_make_gap(from, to, stride, x, GENERATE_TAPE);
      dco::derivative(x) = dco::derivative(xg);
      cout << "INTERPRET SECTION " << from << " ... " << to - 1 << endl;
      dco::tape(xg)->interpret_adjoint_and_reset_to(p);
      dco::derivative(xg_in) += dco::derivative(x_in);
      if (to - from <= stride) {
        cout << "poping " << state.top().first << ", " << state.top().second << endl;
        state.pop();
      }
    };

    dco::tape(xg)->insert_callback(std::move(fill_gap));

  } else if (m == GENERATE_TAPE) {
    cout << "GENERATE TAPE FOR SECTION " << from << " ... " << to - 1 << endl;
    stringstream s;
    s << from << "GENERATE_TAPE_" << to - 1 << ".dot";
    dco::tape(xg)->write_to_dot(s.str());
    // in taping mode, the interval is subdivided further if
    // its length exceeds the desired stride ...
    if (to - from > stride) {
      g_make_gap(from, from + (to - from) / 2, stride, xg, CHECKPOINT_ARGUMENTS_AND_RUN_PASSIVELY);
      g_make_gap(from + (to - from) / 2, to, stride, xg, CHECKPOINT_ARGUMENTS_AND_RUN_PASSIVELY);
    } else
      // ... or the given number of iterations is performed
      // actively and the corresponding tape is written
      for (int i = from; i < to; i++)
        xg = sin(xg);
  }
  if (dco::size_of(dco::tape(xg)) > max_tape_size)
    max_tape_size = dco::size_of(dco::tape(xg));
}
