#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"

/**
 * Patterns for invariant_qualifier
 *
 * 1. INVARIANT
 */

namespace gliss {

namespace ast {

class invariant_qualifier_t: public ast_t {

public:

  static constexpr int rules = 1;

  static constexpr int id = 252;

  virtual ~invariant_qualifier_t() = default;

};  // invariant_qualifier_t

class invariant_qualifier_invariant_t: public invariant_qualifier_t {

public:

  std::unique_ptr<token_t> invariant_0;

  invariant_qualifier_invariant_t(
    std::unique_ptr<token_t> &&invariant_0_
  ): invariant_0(std::move(invariant_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<invariant_qualifier_invariant_t> make(
    const token_t *INVARIANT_0_
  ) {
    return std::make_unique<invariant_qualifier_invariant_t>(
      std::make_unique<token_t>(*INVARIANT_0_)
    );
  }

};  // invariant_qualifier_invariant_t

}   // ast

}   // gliss
