#pragma once

#include <sstream>

namespace biglr {

inline std::vector<std::string> get_ast_base_deps() {
  return { "vector", "memory" }; 
}

inline std::string generate_ast_base_h(
  std::vector<std::shared_ptr<reduction_t>> reductions,
  std::unordered_map<std::shared_ptr<symbol_t>, std::vector<std::shared_ptr<rule_t>>> by_lhs
) {
  std::sort(reductions.begin(), reductions.end(), [](auto a, auto b) {
    return a->get_id() < b->get_id();
  });

  std::vector<std::string> branches;
  std::stringstream ss;

  auto omega = top_t::make();
  branches.push_back(by_lhs[omega].front()->get_cpp_branch_identifier());
  branches.push_back(by_lhs[omega].front()->get_cpp_identifier());

  for (auto reduction: reductions) {
    branches.push_back(by_lhs[reduction].front()->get_cpp_branch_identifier());

    std::sort(by_lhs[reduction].begin(), by_lhs[reduction].end(), [](auto a, auto b) {
      return a->get_id() < b->get_id();
    });

    for (const auto &rule: by_lhs[reduction]) {
      branches.push_back(rule->get_cpp_identifier());
    }
  }

  branches.push_back("ast_token");

  for (const auto &id: branches) {
    ss << "class " << id << "_t;" << std::endl;
  }

  ss << std::endl;

  ss <<
  "/* default visitor */" << std::endl <<
  "struct default_visitor_t {" << std::endl <<
  "  virtual ~default_visitor_t() = default;" << std::endl;

  for (const auto &id: branches) {
    ss << "  virtual void operator()(const " << id << "_t *) const = 0;" << std::endl;
  }

  ss << "};  // default_visitor_t" << std::endl;

  ss << R"(

class ast_t;

/* base class for all ast nodes */
class ast_t {

public:

  using visitor_t = default_visitor_t;

  virtual ~ast_t() = default;

  virtual symbol_t::kind_t get_symbol_id() const = 0;

  std::string get_name() {
    return symbol_t::get_name(get_symbol_id());
  }

  /* famous out of the box visitor pattern functionality */
  virtual void accept(const visitor_t &visitor) const = 0;

  /* return all children */
  std::vector<std::shared_ptr<ast_t>> get_children() const {
    return children;
  }

protected:

  ast_t(std::vector<std::shared_ptr<ast_t>> children_): children(children_) {}

  std::vector<std::shared_ptr<ast_t>> children;

};  // ast_t

/* an ast node holding a single token */
class ast_token_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(token->get_kind());
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  std::shared_ptr<token_t> get_token() const {
    return token;
  }

  static std::shared_ptr<ast_token_t> make(std::shared_ptr<token_t> token) {
    auto ptr = new ast_token_t(token);
    std::shared_ptr<ast_token_t> result(ptr);
    return result;
  }

protected:

  std::shared_ptr<token_t> token;

  ast_token_t(std::shared_ptr<token_t> token_): ast_t({}), token(token_) {
    assert(children.size() == 0);
  }

};  // ast_token_t

)";

  return ss.str();
}

}   // biglr