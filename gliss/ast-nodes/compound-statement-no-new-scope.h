#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "statement-list.h"

/**
 * Patterns for compound_statement_no_new_scope
 *
 * 1. LEFT_BRACE RIGHT_BRACE
 * 2. LEFT_BRACE statement_list RIGHT_BRACE
 */

namespace gliss {

namespace ast {

class statement_list_t;

class compound_statement_no_new_scope_t: public ast_t {

public:

  static constexpr int rules = 2;

  static constexpr int id = 279;

  virtual ~compound_statement_no_new_scope_t() = default;

};  // compound_statement_no_new_scope_t

class compound_statement_no_new_scope_left_brace_right_brace_t: public compound_statement_no_new_scope_t {

public:

  std::shared_ptr<ast_token_t> left_brace_0;

  std::shared_ptr<ast_token_t> right_brace_1;

  compound_statement_no_new_scope_left_brace_right_brace_t(
    std::shared_ptr<ast_token_t> left_brace_0_,
    std::shared_ptr<ast_token_t> right_brace_1_
  ): left_brace_0(left_brace_0_),
     right_brace_1(right_brace_1_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 279;
  }

  static std::shared_ptr<compound_statement_no_new_scope_left_brace_right_brace_t> make(
    std::shared_ptr<ast_token_t> LEFT_BRACE_0_,
    std::shared_ptr<ast_token_t> RIGHT_BRACE_1_
  ) {
    return std::make_shared<compound_statement_no_new_scope_left_brace_right_brace_t>(
      LEFT_BRACE_0_,
      RIGHT_BRACE_1_
    );
  }

};  // compound_statement_no_new_scope_left_brace_right_brace_t

class compound_statement_no_new_scope_left_brace_statement_list_right_brace_t: public compound_statement_no_new_scope_t {

public:

  std::shared_ptr<ast_token_t> left_brace_0;

  std::shared_ptr<statement_list_t> statement_list_1;

  std::shared_ptr<ast_token_t> right_brace_2;

  compound_statement_no_new_scope_left_brace_statement_list_right_brace_t(
    std::shared_ptr<ast_token_t> left_brace_0_,
    std::shared_ptr<statement_list_t> statement_list_1_,
    std::shared_ptr<ast_token_t> right_brace_2_
  ): left_brace_0(left_brace_0_),
     statement_list_1(statement_list_1_),
     right_brace_2(right_brace_2_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 279;
  }

  static std::shared_ptr<compound_statement_no_new_scope_left_brace_statement_list_right_brace_t> make(
    std::shared_ptr<ast_token_t> LEFT_BRACE_0_,
    std::shared_ptr<statement_list_t> statement_list_1_,
    std::shared_ptr<ast_token_t> RIGHT_BRACE_2_
  ) {
    return std::make_shared<compound_statement_no_new_scope_left_brace_statement_list_right_brace_t>(
      LEFT_BRACE_0_,
      statement_list_1_,
      RIGHT_BRACE_2_
    );
  }

};  // compound_statement_no_new_scope_left_brace_statement_list_right_brace_t

}   // ast

}   // gliss
