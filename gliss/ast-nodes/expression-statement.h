#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "expression.h"

/**
 * Patterns for expression_statement
 *
 * 1. SEMICOLON
 * 2. expression SEMICOLON
 */

namespace gliss {

namespace ast {

class expression_t;

class expression_statement_t: public ast_t {

public:

  static constexpr int rules = 2;

  static constexpr int id = 280;

  virtual ~expression_statement_t() = default;

};  // expression_statement_t

class expression_statement_semicolon_t: public expression_statement_t {

public:

  std::unique_ptr<token_t> semicolon_0;

  expression_statement_semicolon_t(
    std::unique_ptr<token_t> &&semicolon_0_
  ): semicolon_0(std::move(semicolon_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<expression_statement_semicolon_t> make(
    const token_t *SEMICOLON_0_
  ) {
    return std::make_unique<expression_statement_semicolon_t>(
      std::make_unique<token_t>(*SEMICOLON_0_)
    );
  }

};  // expression_statement_semicolon_t

class expression_statement_expression_semicolon_t: public expression_statement_t {

public:

  std::unique_ptr<expression_t> expression_0;

  std::unique_ptr<token_t> semicolon_1;

  expression_statement_expression_semicolon_t(
    std::unique_ptr<expression_t> &&expression_0_,
    std::unique_ptr<token_t> &&semicolon_1_
  ): expression_0(std::move(expression_0_)),
     semicolon_1(std::move(semicolon_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<expression_statement_expression_semicolon_t> make(
    std::unique_ptr<expression_t> &&expression_0_,
    const token_t *SEMICOLON_1_
  ) {
    return std::make_unique<expression_statement_expression_semicolon_t>(
      std::move(expression_0_),
      std::make_unique<token_t>(*SEMICOLON_1_)
    );
  }

};  // expression_statement_expression_semicolon_t

}   // ast

}   // gliss
