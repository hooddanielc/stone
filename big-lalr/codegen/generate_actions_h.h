#pragma once

#include <sstream>
#include <memory>
#include <map>
#include "../symbol.h"
#include "../action.h"

namespace biglr {

using action_map_t = std::unordered_map<std::shared_ptr<symbol_t>, std::shared_ptr<action_t>>;

using action_table_t = std::unordered_map<std::shared_ptr<state_t>, action_map_t>;

int get_num_digits (int x) {
  if (x < 0) return get_num_digits(-x) + 1;

  if (x < 10) {
    return 1;
  } else if (x < 100) {
    return 2;
  } else if (x < 1000) {
    return 3;
  } else if (x < 10000) {
    return 4;
  } else if (x < 100000) {
    return 5;
  }

  return 6;
}

inline std::string generate_actions_h(
  std::vector<std::shared_ptr<state_t>> states,
  std::vector<std::shared_ptr<token_t>> tokens,
  std::vector<std::shared_ptr<reduction_t>> reductions,
  action_table_t actions
) {
  std::stringstream ss;

  int num_tokens = tokens.size();
  int num_reductions = reductions.size();
  int num_states = states.size();

  std::sort(states.begin(), states.end(), [](auto a, auto b) {
    return a->get_id() < b->get_id();
  });

  std::sort(tokens.begin(), tokens.end(), [](auto a, auto b) {
    return a->get_id() < b->get_id();
  });

  ss << R"(

enum action_kind_t {
  restart = )" << action_t::restart << R"(, // unused
  reduce = )" << action_t::reduce << R"(,
  shift = )" << action_t::shift << R"(,
  transition = )" << (action_t::shift + 1) << R"(
};

// state == actions[(state_id * num_tokens) + token_id];
// if (state == 0) accept
// if (state < 0) { reduce(state * -1); }
// if (state > 0 && state != INT16_MAX) { shift and go to (state-1) }
// if (state == INT16_MAX) { error }

// transition layout
// {
//   { reduction_id, state_id },
//   ...
// }

const int16_t num_tokens = )" << num_tokens << R"(;

const int16_t num_reductions = )" << num_reductions << R"(;

const int16_t num_symbols = )" << (num_reductions + num_tokens) << R"(;

const int16_t actions[)" << num_tokens + num_reductions << R"( * )" << num_states << R"(] = {

)";

  for (auto states_it = states.begin(); states_it != states.end(); ++states_it) {
    auto state = (*states_it);
    ss << "  /* s" << state->get_id() << " */ ";
    for (auto token_it = tokens.begin(); token_it != tokens.end(); ++token_it) {
      auto token = (*token_it);
      ss << actions[state][token]->get_param() << " /* " << token->get_name() << " */";

      if (std::next(token_it) != tokens.end()) {
        ss << ", ";
      } else {
        ss << ", /* END TOKENS */ ";
      }
    }

    for (auto reduction_it = reductions.begin(); reduction_it != reductions.end(); ++reduction_it) {
      auto reduction = (*reduction_it);
      ss << actions[state][reduction]->get_param() << " /* " << reduction->get_name() << " */";

      if (std::next(states_it) != states.end() || std::next(reduction_it) != reductions.end()) {
        ss << ",";
      }

      if (std::next(reduction_it) != reductions.end()) {
        ss << " ";
      } else {
        ss << std::endl;
      }
    }
  }

  ss << R"(
};   // actions
  )";

  return ss.str();
}

}   // biglr
