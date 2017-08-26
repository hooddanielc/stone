#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "struct-declaration-list.h"

/**
 * Patterns for struct_specifier
 *
 * 1. STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE
 * 2. STRUCT LEFT_BRACE struct_declaration_list RIGHT_BRACE
 */

namespace gliss {

namespace ast {

class struct_declaration_list_t;

class struct_specifier_t: public ast_t {

public:

  static constexpr int rules = 2;

  static constexpr int id = 266;

  virtual ~struct_specifier_t() = default;

};  // struct_specifier_t

class struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t: public struct_specifier_t {

public:

  std::unique_ptr<token_t> struct_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<token_t> left_brace_2;

  std::unique_ptr<struct_declaration_list_t> struct_declaration_list_3;

  std::unique_ptr<token_t> right_brace_4;

  struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t(
    std::unique_ptr<token_t> &&struct_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<token_t> &&left_brace_2_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_3_,
    std::unique_ptr<token_t> &&right_brace_4_
  ): struct_0(std::move(struct_0_)),
     identifier_1(std::move(identifier_1_)),
     left_brace_2(std::move(left_brace_2_)),
     struct_declaration_list_3(std::move(struct_declaration_list_3_)),
     right_brace_4(std::move(right_brace_4_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t> make(
    const token_t *STRUCT_0_,
    const token_t *IDENTIFIER_1_,
    const token_t *LEFT_BRACE_2_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_3_,
    const token_t *RIGHT_BRACE_4_
  ) {
    return std::make_unique<struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t>(
      std::make_unique<token_t>(*STRUCT_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::make_unique<token_t>(*LEFT_BRACE_2_),
      std::move(struct_declaration_list_3_),
      std::make_unique<token_t>(*RIGHT_BRACE_4_)
    );
  }

};  // struct_specifier_struct_identifier_left_brace_struct_declaration_list_right_brace_t

class struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t: public struct_specifier_t {

public:

  std::unique_ptr<token_t> struct_0;

  std::unique_ptr<token_t> left_brace_1;

  std::unique_ptr<struct_declaration_list_t> struct_declaration_list_2;

  std::unique_ptr<token_t> right_brace_3;

  struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t(
    std::unique_ptr<token_t> &&struct_0_,
    std::unique_ptr<token_t> &&left_brace_1_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_2_,
    std::unique_ptr<token_t> &&right_brace_3_
  ): struct_0(std::move(struct_0_)),
     left_brace_1(std::move(left_brace_1_)),
     struct_declaration_list_2(std::move(struct_declaration_list_2_)),
     right_brace_3(std::move(right_brace_3_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t> make(
    const token_t *STRUCT_0_,
    const token_t *LEFT_BRACE_1_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_2_,
    const token_t *RIGHT_BRACE_3_
  ) {
    return std::make_unique<struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t>(
      std::make_unique<token_t>(*STRUCT_0_),
      std::make_unique<token_t>(*LEFT_BRACE_1_),
      std::move(struct_declaration_list_2_),
      std::make_unique<token_t>(*RIGHT_BRACE_3_)
    );
  }

};  // struct_specifier_struct_left_brace_struct_declaration_list_right_brace_t

}   // ast

}   // gliss
