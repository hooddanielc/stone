#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "exclusive-or-expression.h"

namespace gliss {

namespace ast {

class exclusive_or_expression_t;

class inclusive_or_expression_t: public ast_t {

public:

  static constexpr int num_types = 2;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = inclusive_or_expression_exclusive_or_expression_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 1>::type> {
    using type = inclusive_or_expression_inclusive_or_expression_vertical_bar_exclusive_or_expression_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~inclusive_or_expression_t() = default;

};  // inclusive_or_expression_t

class inclusive_or_expression_exclusive_or_expression_t: public inclusive_or_expression_t {

public:

  std::unique_ptr<exclusive_or_expression_t> exclusive_or_expression_0;

  inclusive_or_expression_exclusive_or_expression_t(
    std::unique_ptr<exclusive_or_expression_t> &&exclusive_or_expression_0_
  ): exclusive_or_expression_0(std::move(exclusive_or_expression_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // inclusive_or_expression_exclusive_or_expression_t

class inclusive_or_expression_inclusive_or_expression_vertical_bar_exclusive_or_expression_t: public inclusive_or_expression_t {

public:

  std::unique_ptr<inclusive_or_expression_t> inclusive_or_expression_0;

  std::unique_ptr<token_t> vertical_bar_1;

  std::unique_ptr<exclusive_or_expression_t> exclusive_or_expression_2;

  inclusive_or_expression_inclusive_or_expression_vertical_bar_exclusive_or_expression_t(
    std::unique_ptr<inclusive_or_expression_t> &&inclusive_or_expression_0_,
    std::unique_ptr<token_t> &&vertical_bar_1_,
    std::unique_ptr<exclusive_or_expression_t> &&exclusive_or_expression_2_
  ): inclusive_or_expression_0(std::move(inclusive_or_expression_0_)),
     vertical_bar_1(std::move(vertical_bar_1_)),
     exclusive_or_expression_2(std::move(exclusive_or_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // inclusive_or_expression_inclusive_or_expression_vertical_bar_exclusive_or_expression_t

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> inclusive_or_expression_t::pattern<0>::list = {
  pattern_item_t<exclusive_or_expression_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> inclusive_or_expression_t::pattern<1>::list = {
  pattern_item_t<inclusive_or_expression_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("VERTICAL_BAR")),
  pattern_item_t<exclusive_or_expression_t>::get()
};

}   // ast

}   // gliss
