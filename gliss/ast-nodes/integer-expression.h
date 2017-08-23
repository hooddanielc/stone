#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "expression.h"

/**
 * Patterns for integer_expression
 *
 * 1. expression
 */

namespace gliss {

namespace ast {

class expression_t;

class integer_expression_t: public ast_t {

public:

  static constexpr int num_types = 1;

  virtual ~integer_expression_t() = default;

};  // integer_expression_t

class integer_expression_expression_t: public integer_expression_t {

public:

  std::unique_ptr<expression_t> expression_0;

  integer_expression_expression_t(
    std::unique_ptr<expression_t> &&expression_0_
  ): expression_0(std::move(expression_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<integer_expression_expression_t> make(
    std::unique_ptr<expression_t> &&expression_0_
  ) {
    return std::make_unique<integer_expression_expression_t>(
      std::move(expression_0_)
    );
  }

};  // integer_expression_expression_t

}   // ast

}   // gliss
