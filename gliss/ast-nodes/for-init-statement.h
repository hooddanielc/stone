#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "expression-statement.h"
#include "declaration-statement.h"

/**
 * Patterns for for_init_statement
 *
 * 1. expression_statement
 * 2. declaration_statement
 */

namespace gliss {

namespace ast {

class expression_statement_t;
class declaration_statement_t;

class for_init_statement_t: public ast_t {

public:

  static constexpr int rules = 2;

  static constexpr int id = 288;

  virtual ~for_init_statement_t() = default;

};  // for_init_statement_t

class for_init_statement_expression_statement_t: public for_init_statement_t {

public:

  std::unique_ptr<expression_statement_t> expression_statement_0;

  for_init_statement_expression_statement_t(
    std::unique_ptr<expression_statement_t> &&expression_statement_0_
  ): expression_statement_0(std::move(expression_statement_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<for_init_statement_expression_statement_t> make(
    std::unique_ptr<expression_statement_t> &&expression_statement_0_
  ) {
    return std::make_unique<for_init_statement_expression_statement_t>(
      std::move(expression_statement_0_)
    );
  }

};  // for_init_statement_expression_statement_t

class for_init_statement_declaration_statement_t: public for_init_statement_t {

public:

  std::unique_ptr<declaration_statement_t> declaration_statement_0;

  for_init_statement_declaration_statement_t(
    std::unique_ptr<declaration_statement_t> &&declaration_statement_0_
  ): declaration_statement_0(std::move(declaration_statement_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<for_init_statement_declaration_statement_t> make(
    std::unique_ptr<declaration_statement_t> &&declaration_statement_0_
  ) {
    return std::make_unique<for_init_statement_declaration_statement_t>(
      std::move(declaration_statement_0_)
    );
  }

};  // for_init_statement_declaration_statement_t

}   // ast

}   // gliss
