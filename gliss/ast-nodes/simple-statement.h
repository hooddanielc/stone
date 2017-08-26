#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "declaration-statement.h"
#include "expression-statement.h"
#include "selection-statement.h"
#include "switch-statement.h"
#include "case-label.h"
#include "iteration-statement.h"
#include "jump-statement.h"

/**
 * Patterns for simple_statement
 *
 * 1. declaration_statement
 * 2. expression_statement
 * 3. selection_statement
 * 4. switch_statement
 * 5. case_label
 * 6. iteration_statement
 * 7. jump_statement
 */

namespace gliss {

namespace ast {

class declaration_statement_t;
class expression_statement_t;
class selection_statement_t;
class switch_statement_t;
class case_label_t;
class iteration_statement_t;
class jump_statement_t;

class simple_statement_t: public ast_t {

public:

  static constexpr int rules = 7;

  static constexpr int id = 275;

  virtual ~simple_statement_t() = default;

};  // simple_statement_t

class simple_statement_declaration_statement_t: public simple_statement_t {

public:

  std::unique_ptr<declaration_statement_t> declaration_statement_0;

  simple_statement_declaration_statement_t(
    std::unique_ptr<declaration_statement_t> &&declaration_statement_0_
  ): declaration_statement_0(std::move(declaration_statement_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<simple_statement_declaration_statement_t> make(
    std::unique_ptr<declaration_statement_t> &&declaration_statement_0_
  ) {
    return std::make_unique<simple_statement_declaration_statement_t>(
      std::move(declaration_statement_0_)
    );
  }

};  // simple_statement_declaration_statement_t

class simple_statement_expression_statement_t: public simple_statement_t {

public:

  std::unique_ptr<expression_statement_t> expression_statement_0;

  simple_statement_expression_statement_t(
    std::unique_ptr<expression_statement_t> &&expression_statement_0_
  ): expression_statement_0(std::move(expression_statement_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<simple_statement_expression_statement_t> make(
    std::unique_ptr<expression_statement_t> &&expression_statement_0_
  ) {
    return std::make_unique<simple_statement_expression_statement_t>(
      std::move(expression_statement_0_)
    );
  }

};  // simple_statement_expression_statement_t

class simple_statement_selection_statement_t: public simple_statement_t {

public:

  std::unique_ptr<selection_statement_t> selection_statement_0;

  simple_statement_selection_statement_t(
    std::unique_ptr<selection_statement_t> &&selection_statement_0_
  ): selection_statement_0(std::move(selection_statement_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<simple_statement_selection_statement_t> make(
    std::unique_ptr<selection_statement_t> &&selection_statement_0_
  ) {
    return std::make_unique<simple_statement_selection_statement_t>(
      std::move(selection_statement_0_)
    );
  }

};  // simple_statement_selection_statement_t

class simple_statement_switch_statement_t: public simple_statement_t {

public:

  std::unique_ptr<switch_statement_t> switch_statement_0;

  simple_statement_switch_statement_t(
    std::unique_ptr<switch_statement_t> &&switch_statement_0_
  ): switch_statement_0(std::move(switch_statement_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<simple_statement_switch_statement_t> make(
    std::unique_ptr<switch_statement_t> &&switch_statement_0_
  ) {
    return std::make_unique<simple_statement_switch_statement_t>(
      std::move(switch_statement_0_)
    );
  }

};  // simple_statement_switch_statement_t

class simple_statement_case_label_t: public simple_statement_t {

public:

  std::unique_ptr<case_label_t> case_label_0;

  simple_statement_case_label_t(
    std::unique_ptr<case_label_t> &&case_label_0_
  ): case_label_0(std::move(case_label_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<simple_statement_case_label_t> make(
    std::unique_ptr<case_label_t> &&case_label_0_
  ) {
    return std::make_unique<simple_statement_case_label_t>(
      std::move(case_label_0_)
    );
  }

};  // simple_statement_case_label_t

class simple_statement_iteration_statement_t: public simple_statement_t {

public:

  std::unique_ptr<iteration_statement_t> iteration_statement_0;

  simple_statement_iteration_statement_t(
    std::unique_ptr<iteration_statement_t> &&iteration_statement_0_
  ): iteration_statement_0(std::move(iteration_statement_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<simple_statement_iteration_statement_t> make(
    std::unique_ptr<iteration_statement_t> &&iteration_statement_0_
  ) {
    return std::make_unique<simple_statement_iteration_statement_t>(
      std::move(iteration_statement_0_)
    );
  }

};  // simple_statement_iteration_statement_t

class simple_statement_jump_statement_t: public simple_statement_t {

public:

  std::unique_ptr<jump_statement_t> jump_statement_0;

  simple_statement_jump_statement_t(
    std::unique_ptr<jump_statement_t> &&jump_statement_0_
  ): jump_statement_0(std::move(jump_statement_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<simple_statement_jump_statement_t> make(
    std::unique_ptr<jump_statement_t> &&jump_statement_0_
  ) {
    return std::make_unique<simple_statement_jump_statement_t>(
      std::move(jump_statement_0_)
    );
  }

};  // simple_statement_jump_statement_t

}   // ast

}   // gliss
