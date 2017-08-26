#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "primary-expression.h"

#include "integer-expression.h"
#include "function-call.h"

/**
 * Patterns for postfix_expression
 *
 * 1. primary_expression
 * 2. postfix_expression LEFT_BRACKET integer_expression RIGHT_BRACKET
 * 3. function_call
 * 4. postfix_expression DOT FIELD_SELECTION
 * 5. postfix_expression INC_OP
 * 6. postfix_expression DEC_OP
 */

namespace gliss {

namespace ast {

class primary_expression_t;

class integer_expression_t;
class function_call_t;

class postfix_expression_t: public ast_t {

public:

  static constexpr int rules = 6;

  static constexpr int id = 213;

  virtual ~postfix_expression_t() = default;

};  // postfix_expression_t

class postfix_expression_primary_expression_t: public postfix_expression_t {

public:

  std::unique_ptr<primary_expression_t> primary_expression_0;

  postfix_expression_primary_expression_t(
    std::unique_ptr<primary_expression_t> &&primary_expression_0_
  ): primary_expression_0(std::move(primary_expression_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<postfix_expression_primary_expression_t> make(
    std::unique_ptr<primary_expression_t> &&primary_expression_0_
  ) {
    return std::make_unique<postfix_expression_primary_expression_t>(
      std::move(primary_expression_0_)
    );
  }

};  // postfix_expression_primary_expression_t

class postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t: public postfix_expression_t {

public:

  std::unique_ptr<postfix_expression_t> postfix_expression_0;

  std::unique_ptr<token_t> left_bracket_1;

  std::unique_ptr<integer_expression_t> integer_expression_2;

  std::unique_ptr<token_t> right_bracket_3;

  postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_,
    std::unique_ptr<token_t> &&left_bracket_1_,
    std::unique_ptr<integer_expression_t> &&integer_expression_2_,
    std::unique_ptr<token_t> &&right_bracket_3_
  ): postfix_expression_0(std::move(postfix_expression_0_)),
     left_bracket_1(std::move(left_bracket_1_)),
     integer_expression_2(std::move(integer_expression_2_)),
     right_bracket_3(std::move(right_bracket_3_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t> make(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_,
    const token_t *LEFT_BRACKET_1_,
    std::unique_ptr<integer_expression_t> &&integer_expression_2_,
    const token_t *RIGHT_BRACKET_3_
  ) {
    return std::make_unique<postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t>(
      std::move(postfix_expression_0_),
      std::make_unique<token_t>(*LEFT_BRACKET_1_),
      std::move(integer_expression_2_),
      std::make_unique<token_t>(*RIGHT_BRACKET_3_)
    );
  }

};  // postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t

class postfix_expression_function_call_t: public postfix_expression_t {

public:

  std::unique_ptr<function_call_t> function_call_0;

  postfix_expression_function_call_t(
    std::unique_ptr<function_call_t> &&function_call_0_
  ): function_call_0(std::move(function_call_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<postfix_expression_function_call_t> make(
    std::unique_ptr<function_call_t> &&function_call_0_
  ) {
    return std::make_unique<postfix_expression_function_call_t>(
      std::move(function_call_0_)
    );
  }

};  // postfix_expression_function_call_t

class postfix_expression_postfix_expression_dot_field_selection_t: public postfix_expression_t {

public:

  std::unique_ptr<postfix_expression_t> postfix_expression_0;

  std::unique_ptr<token_t> dot_1;

  std::unique_ptr<token_t> field_selection_2;

  postfix_expression_postfix_expression_dot_field_selection_t(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_,
    std::unique_ptr<token_t> &&dot_1_,
    std::unique_ptr<token_t> &&field_selection_2_
  ): postfix_expression_0(std::move(postfix_expression_0_)),
     dot_1(std::move(dot_1_)),
     field_selection_2(std::move(field_selection_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<postfix_expression_postfix_expression_dot_field_selection_t> make(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_,
    const token_t *DOT_1_,
    const token_t *FIELD_SELECTION_2_
  ) {
    return std::make_unique<postfix_expression_postfix_expression_dot_field_selection_t>(
      std::move(postfix_expression_0_),
      std::make_unique<token_t>(*DOT_1_),
      std::make_unique<token_t>(*FIELD_SELECTION_2_)
    );
  }

};  // postfix_expression_postfix_expression_dot_field_selection_t

class postfix_expression_postfix_expression_inc_op_t: public postfix_expression_t {

public:

  std::unique_ptr<postfix_expression_t> postfix_expression_0;

  std::unique_ptr<token_t> inc_op_1;

  postfix_expression_postfix_expression_inc_op_t(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_,
    std::unique_ptr<token_t> &&inc_op_1_
  ): postfix_expression_0(std::move(postfix_expression_0_)),
     inc_op_1(std::move(inc_op_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<postfix_expression_postfix_expression_inc_op_t> make(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_,
    const token_t *INC_OP_1_
  ) {
    return std::make_unique<postfix_expression_postfix_expression_inc_op_t>(
      std::move(postfix_expression_0_),
      std::make_unique<token_t>(*INC_OP_1_)
    );
  }

};  // postfix_expression_postfix_expression_inc_op_t

class postfix_expression_postfix_expression_dec_op_t: public postfix_expression_t {

public:

  std::unique_ptr<postfix_expression_t> postfix_expression_0;

  std::unique_ptr<token_t> dec_op_1;

  postfix_expression_postfix_expression_dec_op_t(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_,
    std::unique_ptr<token_t> &&dec_op_1_
  ): postfix_expression_0(std::move(postfix_expression_0_)),
     dec_op_1(std::move(dec_op_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<postfix_expression_postfix_expression_dec_op_t> make(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_,
    const token_t *DEC_OP_1_
  ) {
    return std::make_unique<postfix_expression_postfix_expression_dec_op_t>(
      std::move(postfix_expression_0_),
      std::make_unique<token_t>(*DEC_OP_1_)
    );
  }

};  // postfix_expression_postfix_expression_dec_op_t

}   // ast

}   // gliss
