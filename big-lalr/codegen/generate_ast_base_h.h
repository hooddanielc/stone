#pragma once

#include <sstream>

namespace biglr {

inline std::string generate_ast_base_h(
  std::vector<std::shared_ptr<reduction_t>> reductions,
  std::unordered_map<std::shared_ptr<symbol_t>, std::vector<std::shared_ptr<rule_t>>> by_lhs
) {
  std::vector<std::string> branches;
  std::stringstream ss;

  auto omega = top_t::make();
  branches.push_back(by_lhs[omega].front()->get_cpp_branch_identifier());
  branches.push_back(by_lhs[omega].front()->get_cpp_identifier());

  for (const auto &reduction: reductions) {
    branches.push_back(by_lhs[reduction].front()->get_cpp_branch_identifier());
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

  /* famous out of the box visitor pattern functionality */
  virtual void accept(const visitor_t &visitor) const = 0;

  /* each ast node represents either a token or reduction */
  virtual int get_symbol_id() const = 0;

  /* if this node is a reduction, return number > 0, otherwise return -1 */
  virtual int get_rule_id() const {
    return -1;
  }

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

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  /* each ast node represents either a token or reduction */
  virtual int get_symbol_id() const override {
    return int(token->get_kind());
  }

  static std::shared_ptr<ast_token_t> make(std::shared_ptr<token_t> token) {
    return ast_token_t::make(token);
  }

protected:

  std::shared_ptr<token_t> token;

  ast_token_t(std::shared_ptr<token_t> token_): ast_t({}), token(token_) {
    assert(children.size() == 1);
  }

};  // ast_token_t

)";

  return ss.str();
}

}   // biglr