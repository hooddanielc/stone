#pragma once

#include <sstream>
#include <memory>
#include <map>
#include "../symbol.h"
#include "../action.h"

namespace biglr {

using action_map_t = std::unordered_map<std::shared_ptr<symbol_t>, std::shared_ptr<action_t>>;

using action_table_t = std::unordered_map<std::shared_ptr<state_t>, action_map_t>;

// actions std::unordered_map<token_t, std::unordered_map<state_t, action_t> >
// {
//   { token_1, { {s1, action}, {s2, action}, {s3, action} } },
//   ...
// }

// transitions std::unordered_map<reduction_id, action_t>
// {
//   { reduction, state_id },
//   ...
// }

inline std::string generate_actions_h(
  std::vector<std::shared_ptr<state_t>> states,
  std::vector<std::shared_ptr<token_t>> tokens,
  std::vector<std::shared_ptr<reduction_t>> reductions,
  action_table_t actions
) {
  std::stringstream ss;

  ss << R"(

enum action_kind_t {
  restart = )" << action_t::restart << R"(,
  reduce = )" << action_t::reduce << R"(,
  shift = )" << action_t::shift << R"(,
};

// actions layout
// {
//   { token_id, { {state_id, {action_type, action_param}}, ... } ... },
//   ...
// }

// transition layout
// {
//   { reduction_id, state_id },
//   ...
// }

static const std::unordered_map<int, std::unordered_map<int, std::pair<action_kind_t, int>>> actions = {
)";

  std::unordered_map<int, std::unordered_map<int, std::pair<int, int>>> actions_tmp;

  for (auto state: states) {
    auto state_id = state->get_id();
    for (auto token: tokens) {
      if (actions[state][token]->is_blank()) continue;
      auto type = int(actions[state][token]->get_kind());
      auto param = actions[state][token]->get_param();
      auto token_id = token->get_id();
      actions_tmp[token_id][state_id] = {type, param};
    }
  }

  for (auto it_row = actions_tmp.begin(); it_row != actions_tmp.end(); ++it_row) {
    auto token_id = it_row->first;
    ss << "  { " << token_id << ", " << "{" << std::endl;

    for (auto it_col = it_row->second.begin(); it_col != it_row->second.end(); ++it_col) {
      auto state_id = it_col->first;
      auto type = it_col->second.first;
      auto param = it_col->second.second;
      std::string type_name;

      switch (type) {
        case static_cast<int>(action_t::restart): type_name = "restart"; break;
        case static_cast<int>(action_t::reduce): type_name = "reduce"; break;
        case static_cast<int>(action_t::shift): type_name = "shift"; break;
      }

      ss << "    { " << state_id << ", { " << type_name << ", " << param << " } }";

      if (std::next(it_col) != it_row->second.end()) {
        ss << ",";
      }

      ss << std::endl;
    }

    ss << "  }}";

    if (std::next(it_row) != actions_tmp.end()) {
      ss << ",";
    }

    ss << std::endl;
  }

  ss << R"(
};   // actions
  )";

  ss << R"(

static std::unordered_map<int, int> transitions = {
)";

  std::unordered_map<int, int> goto_tmp;

  for (auto reduction: reductions) {
    for (auto state: states) {
      if (actions[state][reduction]->is_blank()) continue;
      goto_tmp[reduction->get_id()] = state->get_id();
    }
  }

  for (auto it = goto_tmp.begin(); it != goto_tmp.end(); ++it) {
    ss << "  { " << it->first << ", " << it->second << " }";
    if (std::next(it) != goto_tmp.end()) {
      ss << ",";
    }
    ss << std::endl;
  }

  ss << R"(
};  // transition
)";

  return ss.str();
}

}   // biglr