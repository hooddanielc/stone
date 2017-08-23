#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"

/**
 * Patterns for type_name_list
 *
 * 1. TYPE_NAME
 * 2. type_name_list COMMA TYPE_NAME
 */

namespace gliss {

namespace ast {

class type_name_list_t: public ast_t {

public:

  static constexpr int num_types = 2;

  virtual ~type_name_list_t() = default;

};  // type_name_list_t

class type_name_list_type_name_t: public type_name_list_t {

public:

  std::unique_ptr<token_t> type_name_0;

  type_name_list_type_name_t(
    std::unique_ptr<token_t> &&type_name_0_
  ): type_name_0(std::move(type_name_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<type_name_list_type_name_t> make(
    const token_t *TYPE_NAME_0_
  ) {
    return std::make_unique<type_name_list_type_name_t>(
      std::make_unique<token_t>(*TYPE_NAME_0_)
    );
  }

};  // type_name_list_type_name_t

class type_name_list_type_name_list_comma_type_name_t: public type_name_list_t {

public:

  std::unique_ptr<type_name_list_t> type_name_list_0;

  std::unique_ptr<token_t> comma_1;

  std::unique_ptr<token_t> type_name_2;

  type_name_list_type_name_list_comma_type_name_t(
    std::unique_ptr<type_name_list_t> &&type_name_list_0_,
    std::unique_ptr<token_t> &&comma_1_,
    std::unique_ptr<token_t> &&type_name_2_
  ): type_name_list_0(std::move(type_name_list_0_)),
     comma_1(std::move(comma_1_)),
     type_name_2(std::move(type_name_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<type_name_list_type_name_list_comma_type_name_t> make(
    std::unique_ptr<type_name_list_t> &&type_name_list_0_,
    const token_t *COMMA_1_,
    const token_t *TYPE_NAME_2_
  ) {
    return std::make_unique<type_name_list_type_name_list_comma_type_name_t>(
      std::move(type_name_list_0_),
      std::make_unique<token_t>(*COMMA_1_),
      std::make_unique<token_t>(*TYPE_NAME_2_)
    );
  }

};  // type_name_list_type_name_list_comma_type_name_t

}   // ast

}   // gliss
