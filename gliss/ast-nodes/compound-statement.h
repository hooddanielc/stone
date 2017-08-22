#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "statement-list.h"

namespace gliss {

namespace ast {

class statement_list_t;

class compound_statement_t: public ast_t {

public:

  static constexpr int num_types = 2;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = compound_statement_left_brace_right_brace_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 1>::type> {
    using type = compound_statement_left_brace_statement_list_right_brace_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~compound_statement_t() = default;

};  // compound_statement_t


class compound_statement_left_brace_right_brace_t: public compound_statement_t {

public:

  std::unique_ptr<token_t> left_brace_0;

  std::unique_ptr<token_t> right_brace_1;

  compound_statement_left_brace_right_brace_t(
    std::unique_ptr<token_t> &&left_brace_0_,
    std::unique_ptr<token_t> &&right_brace_1_
  ): left_brace_0(std::move(left_brace_0_)),
     right_brace_1(std::move(right_brace_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // compound_statement_left_brace_right_brace_t
  

class compound_statement_left_brace_statement_list_right_brace_t: public compound_statement_t {

public:

  std::unique_ptr<token_t> left_brace_0;

  std::unique_ptr<statement_list_t> statement_list_1;

  std::unique_ptr<token_t> right_brace_2;

  compound_statement_left_brace_statement_list_right_brace_t(
    std::unique_ptr<token_t> &&left_brace_0_,
    std::unique_ptr<statement_list_t> &&statement_list_1_,
    std::unique_ptr<token_t> &&right_brace_2_
  ): left_brace_0(std::move(left_brace_0_)),
     statement_list_1(std::move(statement_list_1_)),
     right_brace_2(std::move(right_brace_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // compound_statement_left_brace_statement_list_right_brace_t
  

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> compound_statement_t::pattern<0>::list = {
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_BRACE")),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RIGHT_BRACE"))
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> compound_statement_t::pattern<1>::list = {
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_BRACE")),
  pattern_item_t<statement_list_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RIGHT_BRACE"))
};

}   // ast

}   // gliss
