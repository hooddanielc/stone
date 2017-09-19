#pragma once

#include <sstream>
#include <cassert>

namespace biglr {

inline std::string generate_reduction_h(std::vector<std::shared_ptr<rule_t>> rules) {
  std::stringstream ss;

  size_t count = std::count_if(rules.begin(), rules.end(), [&](auto item) {
    return item->get_lhs() == rules.front()->get_lhs();
  });

  assert(rules.size() == count);

  auto base_name = rules.front()->get_cpp_branch_identifier();
  auto reduction_id = rules.front()->get_lhs()->get_id();

  ss << R"(
/* base class for )" << base_name << R"( */
class )" << base_name << R"(_t: public ast_t {

public:

  virtual int get_symbol_id() const override {
    return )" << reduction_id << R"(;
  }

protected:

  )" << base_name << R"(_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // )" << base_name << R"(_t
)";

  for (const auto rule: rules) {
    auto rule_id = rule->get_id();
    auto identifier = rule->get_cpp_identifier();
    auto num_children = rule->get_rhs().size();
    ss << R"(
class )" << identifier << R"(_t: public )" << base_name << R"(_t {

public:

  static std::shared_ptr<)" << identifier << R"(_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == )" << num_children << R"();
    auto ptr = new )" << identifier << R"(_t(children);
    std::shared_ptr<)" << identifier << R"(_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_rule_id() const override {
    return )" << rule_id << R"(;
  }

protected:

  )" << identifier << R"(_t(std::vector<std::shared_ptr<ast_t>> children): )" << base_name << R"(_t(children) {}

};  // )" << identifier << R"(_t
)";
  }

  return ss.str();
}

}   // biglr