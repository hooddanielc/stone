#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "struct-declaration.h"

/**
 * Patterns for struct_declaration_list
 *
 * 1. struct_declaration
 * 2. struct_declaration_list struct_declaration
 */

namespace gliss {

namespace ast {

class struct_declaration_t;

class struct_declaration_list_t: public ast_t {

public:

  static constexpr int num_types = 2;

  virtual ~struct_declaration_list_t() = default;

};  // struct_declaration_list_t

class struct_declaration_list_struct_declaration_t: public struct_declaration_list_t {

public:

  std::unique_ptr<struct_declaration_t> struct_declaration_0;

  struct_declaration_list_struct_declaration_t(
    std::unique_ptr<struct_declaration_t> &&struct_declaration_0_
  ): struct_declaration_0(std::move(struct_declaration_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<struct_declaration_list_struct_declaration_t> make(
    std::unique_ptr<struct_declaration_t> &&struct_declaration_0_
  ) {
    return std::make_unique<struct_declaration_list_struct_declaration_t>(
      std::move(struct_declaration_0_)
    );
  }

};  // struct_declaration_list_struct_declaration_t

class struct_declaration_list_struct_declaration_list_struct_declaration_t: public struct_declaration_list_t {

public:

  std::unique_ptr<struct_declaration_list_t> struct_declaration_list_0;

  std::unique_ptr<struct_declaration_t> struct_declaration_1;

  struct_declaration_list_struct_declaration_list_struct_declaration_t(
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_0_,
    std::unique_ptr<struct_declaration_t> &&struct_declaration_1_
  ): struct_declaration_list_0(std::move(struct_declaration_list_0_)),
     struct_declaration_1(std::move(struct_declaration_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<struct_declaration_list_struct_declaration_list_struct_declaration_t> make(
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_0_,
    std::unique_ptr<struct_declaration_t> &&struct_declaration_1_
  ) {
    return std::make_unique<struct_declaration_list_struct_declaration_list_struct_declaration_t>(
      std::move(struct_declaration_list_0_),
      std::move(struct_declaration_1_)
    );
  }

};  // struct_declaration_list_struct_declaration_list_struct_declaration_t

}   // ast

}   // gliss
