#pragma once

#include <sstream>
#include <memory>
#include <map>
#include "../symbol.h"
#include "../action.h"

namespace biglr {

inline std::string generate_driver_h(std::vector<std::shared_ptr<rule_t>> rules) {
  std::stringstream ss;

  std::sort(rules.begin(), rules.end(), [](auto a, auto b) {
    return a->get_id() < b->get_id();
  });

  ss << "/* rule ids start at one */" << std::endl;
  ss << "const int rule_lengths[" << rules.size() << "] = {" << std::endl;
  for (auto it = rules.begin(); it != rules.end(); ++it) {
    ss << "  " << (*it)->get_rhs().size();
    if (std::next(it) != rules.end()) {
      ss << ",";
    }
    ss << " // #" << (*it)->get_id() << " " << (*it)->get_cpp_identifier() << std::endl;
  }
  ss << "}; // rule_lengths " << std::endl;

  ss << R"(

using action_t = std::pair<action_kind_t, int>;

std::shared_ptr<ast_t> default_reduce_by_id(int id, std::vector<std::shared_ptr<ast_t>> &children) {
  switch (id) {
)";

  for (auto rule: rules) {
    auto id = rule->get_cpp_identifier();
    ss << "  case " << rule->get_id() << ":" << std::endl;
    ss << "    return " << id << "_t::make(children);" << std::endl;
  }

ss << R"(
  } // switch
  throw std::runtime_error("rule id unknown");
}
)";

  ss << get_file_contents(get_project_path("big-lalr/codegen/included_driver.cc"));

  return ss.str();
}

}   // biglr