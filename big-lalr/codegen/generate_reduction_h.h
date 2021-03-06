#pragma once

#include <sstream>
#include <cassert>

namespace biglr {

inline std::vector<std::string> get_reduction_deps() {
  return { "vector", "memory" };
}

inline std::string generate_reduction_h(std::vector<std::shared_ptr<rule_t>> rules) {
  std::sort(rules.begin(), rules.end(), [](auto a, auto b) {
    return a->get_id() < b->get_id();
  });

  std::stringstream ss;
  auto base_name = rules.front()->get_cpp_branch_identifier();
  auto reduction_id = rules.front()->get_lhs()->get_id();

  ss << R"(
/* base class for )" << base_name << R"( */
class )" << base_name << R"(_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = )" << reduction_id << R"(;

protected:

  )" << base_name << R"(_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // )" << base_name << R"(_t
)";

  for (const auto &rule: rules) {
    auto rule_id = rule->get_id();
    auto identifier = rule->get_cpp_identifier();
    auto rhs = rule->get_rhs();
    auto num_children = rule->get_rhs().size();
    std::stringstream ss_pattern;
    ss_pattern << "{ ";
    for (auto it = rhs.begin(); it != rhs.end(); ++it) {
      auto sid = (*it)->get_cpp_identifier();
      ss_pattern << "symbol_t::" << sid;
      if (std::next(it) != rhs.end()) {
        ss_pattern << ",";
      }
      ss_pattern << " ";
    }
    ss_pattern << "}";


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

  static constexpr int rule_id = )" << rule_id << R"(;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  )" << identifier << R"(_t(std::vector<std::shared_ptr<ast_t>> children): )" << base_name << R"(_t(children) {}

};  // )" << identifier << R"(_t

const std::vector<symbol_t::kind_t> )" << identifier << R"(_t::pattern = )" << ss_pattern.str() << R"(;

)";
  }

  return ss.str();
}

}   // biglr