#pragma once

#include <sstream>
#include <cassert>

namespace biglr {

inline std::vector<std::string> get_reduction_deps() {
  return { "vector", "memory" };
}

inline std::string generate_reduction_h(std::vector<std::shared_ptr<rule_t>> rules) {
  std::stringstream ss;

  size_t count = std::count_if(rules.begin(), rules.end(), [&](auto item) {
    return item->get_lhs() == rules.front()->get_lhs();
  });

  assert(rules.size() == count);
  std::sort(rules.begin(), rules.end());
  auto base_name = rules.front()->get_cpp_branch_identifier();
  auto reduction_id = rules.front()->get_lhs()->get_id();

  ss << R"(
/* base class for )" << base_name << R"( */
class )" << base_name << R"(_t: public ast_t {

public:

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
      ss_pattern << sid;
      if (it + 1 != rhs.end()) {
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

  static const std::vector<symbol_t> pattern;

protected:

  )" << identifier << R"(_t(std::vector<std::shared_ptr<ast_t>> children): )" << base_name << R"(_t(children) {}

};  // )" << identifier << R"(_t

const std::vector<symbol_t> )" << identifier << R"(_t::pattern = )" << ss_pattern.str() << R"(;

template <> struct reduction_lookup_t<)" << rule_id << R"(> {
  using type = )" << identifier << R"(_t;
};

)";
  }

  return ss.str();
}

}   // biglr