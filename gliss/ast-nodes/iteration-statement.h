#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "condition.h"
#include "statement-no-new-scope.h"
#include "statement.h"
#include "expression.h"
#include "for-init-statement.h"
#include "for-rest-statement.h"

/**
 * Patterns for iteration_statement
 *
 * 1. WHILE LEFT_PAREN condition RIGHT_PAREN statement_no_new_scope
 * 2. DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON
 * 3. FOR LEFT_PAREN for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope
 */

namespace gliss {

namespace ast {

class condition_t;
class statement_no_new_scope_t;
class statement_t;
class expression_t;
class for_init_statement_t;
class for_rest_statement_t;

class iteration_statement_t: public ast_t {

public:

  static constexpr int rules = 3;

  static constexpr int id = 287;

  virtual ~iteration_statement_t() = default;

};  // iteration_statement_t

class iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t: public iteration_statement_t {

public:

  std::unique_ptr<token_t> while_0;

  std::unique_ptr<token_t> left_paren_1;

  std::unique_ptr<condition_t> condition_2;

  std::unique_ptr<token_t> right_paren_3;

  std::unique_ptr<statement_no_new_scope_t> statement_no_new_scope_4;

  iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t(
    std::unique_ptr<token_t> &&while_0_,
    std::unique_ptr<token_t> &&left_paren_1_,
    std::unique_ptr<condition_t> &&condition_2_,
    std::unique_ptr<token_t> &&right_paren_3_,
    std::unique_ptr<statement_no_new_scope_t> &&statement_no_new_scope_4_
  ): while_0(std::move(while_0_)),
     left_paren_1(std::move(left_paren_1_)),
     condition_2(std::move(condition_2_)),
     right_paren_3(std::move(right_paren_3_)),
     statement_no_new_scope_4(std::move(statement_no_new_scope_4_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t> make(
    const token_t *WHILE_0_,
    const token_t *LEFT_PAREN_1_,
    std::unique_ptr<condition_t> &&condition_2_,
    const token_t *RIGHT_PAREN_3_,
    std::unique_ptr<statement_no_new_scope_t> &&statement_no_new_scope_4_
  ) {
    return std::make_unique<iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t>(
      std::make_unique<token_t>(*WHILE_0_),
      std::make_unique<token_t>(*LEFT_PAREN_1_),
      std::move(condition_2_),
      std::make_unique<token_t>(*RIGHT_PAREN_3_),
      std::move(statement_no_new_scope_4_)
    );
  }

};  // iteration_statement_while_left_paren_condition_right_paren_statement_no_new_scope_t

class iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t: public iteration_statement_t {

public:

  std::unique_ptr<token_t> do_0;

  std::unique_ptr<statement_t> statement_1;

  std::unique_ptr<token_t> while_2;

  std::unique_ptr<token_t> left_paren_3;

  std::unique_ptr<expression_t> expression_4;

  std::unique_ptr<token_t> right_paren_5;

  std::unique_ptr<token_t> semicolon_6;

  iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t(
    std::unique_ptr<token_t> &&do_0_,
    std::unique_ptr<statement_t> &&statement_1_,
    std::unique_ptr<token_t> &&while_2_,
    std::unique_ptr<token_t> &&left_paren_3_,
    std::unique_ptr<expression_t> &&expression_4_,
    std::unique_ptr<token_t> &&right_paren_5_,
    std::unique_ptr<token_t> &&semicolon_6_
  ): do_0(std::move(do_0_)),
     statement_1(std::move(statement_1_)),
     while_2(std::move(while_2_)),
     left_paren_3(std::move(left_paren_3_)),
     expression_4(std::move(expression_4_)),
     right_paren_5(std::move(right_paren_5_)),
     semicolon_6(std::move(semicolon_6_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t> make(
    const token_t *DO_0_,
    std::unique_ptr<statement_t> &&statement_1_,
    const token_t *WHILE_2_,
    const token_t *LEFT_PAREN_3_,
    std::unique_ptr<expression_t> &&expression_4_,
    const token_t *RIGHT_PAREN_5_,
    const token_t *SEMICOLON_6_
  ) {
    return std::make_unique<iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t>(
      std::make_unique<token_t>(*DO_0_),
      std::move(statement_1_),
      std::make_unique<token_t>(*WHILE_2_),
      std::make_unique<token_t>(*LEFT_PAREN_3_),
      std::move(expression_4_),
      std::make_unique<token_t>(*RIGHT_PAREN_5_),
      std::make_unique<token_t>(*SEMICOLON_6_)
    );
  }

};  // iteration_statement_do_statement_while_left_paren_expression_right_paren_semicolon_t

class iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t: public iteration_statement_t {

public:

  std::unique_ptr<token_t> for_0;

  std::unique_ptr<token_t> left_paren_1;

  std::unique_ptr<for_init_statement_t> for_init_statement_2;

  std::unique_ptr<for_rest_statement_t> for_rest_statement_3;

  std::unique_ptr<token_t> right_paren_4;

  std::unique_ptr<statement_no_new_scope_t> statement_no_new_scope_5;

  iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t(
    std::unique_ptr<token_t> &&for_0_,
    std::unique_ptr<token_t> &&left_paren_1_,
    std::unique_ptr<for_init_statement_t> &&for_init_statement_2_,
    std::unique_ptr<for_rest_statement_t> &&for_rest_statement_3_,
    std::unique_ptr<token_t> &&right_paren_4_,
    std::unique_ptr<statement_no_new_scope_t> &&statement_no_new_scope_5_
  ): for_0(std::move(for_0_)),
     left_paren_1(std::move(left_paren_1_)),
     for_init_statement_2(std::move(for_init_statement_2_)),
     for_rest_statement_3(std::move(for_rest_statement_3_)),
     right_paren_4(std::move(right_paren_4_)),
     statement_no_new_scope_5(std::move(statement_no_new_scope_5_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t> make(
    const token_t *FOR_0_,
    const token_t *LEFT_PAREN_1_,
    std::unique_ptr<for_init_statement_t> &&for_init_statement_2_,
    std::unique_ptr<for_rest_statement_t> &&for_rest_statement_3_,
    const token_t *RIGHT_PAREN_4_,
    std::unique_ptr<statement_no_new_scope_t> &&statement_no_new_scope_5_
  ) {
    return std::make_unique<iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t>(
      std::make_unique<token_t>(*FOR_0_),
      std::make_unique<token_t>(*LEFT_PAREN_1_),
      std::move(for_init_statement_2_),
      std::move(for_rest_statement_3_),
      std::make_unique<token_t>(*RIGHT_PAREN_4_),
      std::move(statement_no_new_scope_5_)
    );
  }

};  // iteration_statement_for_left_paren_for_init_statement_for_rest_statement_right_paren_statement_no_new_scope_t

}   // ast

}   // gliss
