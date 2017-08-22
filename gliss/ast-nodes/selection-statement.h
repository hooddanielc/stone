#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "expression.h"
#include "selection-rest-statement.h"

namespace gliss {

namespace ast {

class expression_t;
class selection_rest_statement_t;

class selection_statement_t: public ast_t {

public:

  static constexpr int num_types = 1;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = selection_statement_if_left_paren_expression_right_paren_selection_rest_statement_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~selection_statement_t() = default;

};  // selection_statement_t

class selection_statement_if_left_paren_expression_right_paren_selection_rest_statement_t: public selection_statement_t {

public:

  std::unique_ptr<token_t> if_0;

  std::unique_ptr<token_t> left_paren_1;

  std::unique_ptr<expression_t> expression_2;

  std::unique_ptr<token_t> right_paren_3;

  std::unique_ptr<selection_rest_statement_t> selection_rest_statement_4;

  selection_statement_if_left_paren_expression_right_paren_selection_rest_statement_t(
    std::unique_ptr<token_t> &&if_0_,
    std::unique_ptr<token_t> &&left_paren_1_,
    std::unique_ptr<expression_t> &&expression_2_,
    std::unique_ptr<token_t> &&right_paren_3_,
    std::unique_ptr<selection_rest_statement_t> &&selection_rest_statement_4_
  ): if_0(std::move(if_0_)),
     left_paren_1(std::move(left_paren_1_)),
     expression_2(std::move(expression_2_)),
     right_paren_3(std::move(right_paren_3_)),
     selection_rest_statement_4(std::move(selection_rest_statement_4_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // selection_statement_if_left_paren_expression_right_paren_selection_rest_statement_t

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> selection_statement_t::pattern<0>::list = {
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IF")),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_PAREN")),
  pattern_item_t<expression_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RIGHT_PAREN")),
  pattern_item_t<selection_rest_statement_t>::get()
};

}   // ast

}   // gliss
