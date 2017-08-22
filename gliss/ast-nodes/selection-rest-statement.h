#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "statement.h"

namespace gliss {

namespace ast {

class statement_t;

class selection_rest_statement_t: public ast_t {

public:

  static constexpr int num_types = 2;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = selection_rest_statement_statement_else_statement_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 1>::type> {
    using type = selection_rest_statement_statement_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~selection_rest_statement_t() = default;

};  // selection_rest_statement_t


class selection_rest_statement_statement_else_statement_t: public selection_rest_statement_t {

public:

  std::unique_ptr<statement_t> statement_0;

  std::unique_ptr<token_t> else_1;

  std::unique_ptr<statement_t> statement_2;

  selection_rest_statement_statement_else_statement_t(
    std::unique_ptr<statement_t> &&statement_0_,
    std::unique_ptr<token_t> &&else_1_,
    std::unique_ptr<statement_t> &&statement_2_
  ): statement_0(std::move(statement_0_)),
     else_1(std::move(else_1_)),
     statement_2(std::move(statement_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // selection_rest_statement_statement_else_statement_t
  

class selection_rest_statement_statement_t: public selection_rest_statement_t {

public:

  std::unique_ptr<statement_t> statement_0;

  selection_rest_statement_statement_t(
    std::unique_ptr<statement_t> &&statement_0_
  ): statement_0(std::move(statement_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // selection_rest_statement_statement_t
  

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> selection_rest_statement_t::pattern<0>::list = {
  pattern_item_t<statement_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("ELSE")),
  pattern_item_t<statement_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> selection_rest_statement_t::pattern<1>::list = {
  pattern_item_t<statement_t>::get()
};

}   // ast

}   // gliss
