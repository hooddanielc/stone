#pragma once

#include <sstream>
#include <memory>
#include <map>
#include "../symbol.h"
#include "../action.h"

namespace biglr {

inline std::string generate_driver_h(std::vector<std::shared_ptr<rule_t>> rules) {
  std::stringstream ss;

  ss << R"(

using action_t = std::pair<action_kind_t, int>;

std::vector<std::shared_ptr<ast_t>> pop_children(int, std::vector<std::shared_ptr<ast_t>> &, std::vector<int> &);

std::shared_ptr<ast_t> reduce_by_id(int id, std::vector<std::shared_ptr<ast_t>> &stack, std::vector<int> &states) {
  std::vector<symbol_t> symbol_pattern;
  switch (id) {
)";

  for (auto rule: rules) {
    size_t size = rule->get_rhs().size();
    auto id = rule->get_cpp_identifier();
    ss << "  case " << rule->get_id() << ":" << std::endl;
    ss << "    return " << id << "_t::make(pop_children(" << size << ", stack, states));" << std::endl;
  }

ss << R"(
  } // switch
  throw std::runtime_error("no id unknown");
}
)";

  ss << get_file_contents(get_project_path("big-lalr/codegen/included_driver.cc"));

  return ss.str();
}

}   // biglr