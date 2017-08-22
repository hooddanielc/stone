#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "shift-expression.h"

namespace gliss {

namespace ast {

class shift_expression_t;

class relational_expression_t: public ast_t {

public:

  static constexpr int num_types = 5;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = relational_expression_shift_expression_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 1>::type> {
    using type = relational_expression_relational_expression_left_angle_shift_expression_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 2>::type> {
    using type = relational_expression_relational_expression_right_angle_shift_expression_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 3>::type> {
    using type = relational_expression_relational_expression_le_op_shift_expression_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 4>::type> {
    using type = relational_expression_relational_expression_ge_op_shift_expression_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~relational_expression_t() = default;

};  // relational_expression_t

class relational_expression_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<shift_expression_t> shift_expression_0;

  relational_expression_shift_expression_t(
    std::unique_ptr<shift_expression_t> &&shift_expression_0_
  ): shift_expression_0(std::move(shift_expression_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // relational_expression_shift_expression_t

class relational_expression_relational_expression_left_angle_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<relational_expression_t> relational_expression_0;

  std::unique_ptr<token_t> left_angle_1;

  std::unique_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_left_angle_shift_expression_t(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    std::unique_ptr<token_t> &&left_angle_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ): relational_expression_0(std::move(relational_expression_0_)),
     left_angle_1(std::move(left_angle_1_)),
     shift_expression_2(std::move(shift_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // relational_expression_relational_expression_left_angle_shift_expression_t

class relational_expression_relational_expression_right_angle_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<relational_expression_t> relational_expression_0;

  std::unique_ptr<token_t> right_angle_1;

  std::unique_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_right_angle_shift_expression_t(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    std::unique_ptr<token_t> &&right_angle_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ): relational_expression_0(std::move(relational_expression_0_)),
     right_angle_1(std::move(right_angle_1_)),
     shift_expression_2(std::move(shift_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // relational_expression_relational_expression_right_angle_shift_expression_t

class relational_expression_relational_expression_le_op_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<relational_expression_t> relational_expression_0;

  std::unique_ptr<token_t> le_op_1;

  std::unique_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_le_op_shift_expression_t(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    std::unique_ptr<token_t> &&le_op_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ): relational_expression_0(std::move(relational_expression_0_)),
     le_op_1(std::move(le_op_1_)),
     shift_expression_2(std::move(shift_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // relational_expression_relational_expression_le_op_shift_expression_t

class relational_expression_relational_expression_ge_op_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<relational_expression_t> relational_expression_0;

  std::unique_ptr<token_t> ge_op_1;

  std::unique_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_ge_op_shift_expression_t(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    std::unique_ptr<token_t> &&ge_op_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ): relational_expression_0(std::move(relational_expression_0_)),
     ge_op_1(std::move(ge_op_1_)),
     shift_expression_2(std::move(shift_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // relational_expression_relational_expression_ge_op_shift_expression_t

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> relational_expression_t::pattern<0>::list = {
  pattern_item_t<shift_expression_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> relational_expression_t::pattern<1>::list = {
  pattern_item_t<relational_expression_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_ANGLE")),
  pattern_item_t<shift_expression_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> relational_expression_t::pattern<2>::list = {
  pattern_item_t<relational_expression_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RIGHT_ANGLE")),
  pattern_item_t<shift_expression_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> relational_expression_t::pattern<3>::list = {
  pattern_item_t<relational_expression_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LE_OP")),
  pattern_item_t<shift_expression_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> relational_expression_t::pattern<4>::list = {
  pattern_item_t<relational_expression_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("GE_OP")),
  pattern_item_t<shift_expression_t>::get()
};

}   // ast

}   // gliss
