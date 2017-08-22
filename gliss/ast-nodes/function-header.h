#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "fully-specified-type.h"

namespace gliss {

namespace ast {

class fully_specified_type_t;

class function_header_t: public ast_t {

public:

  static constexpr int num_types = 1;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = function_header_fully_specified_type_identifier_left_paren_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~function_header_t() = default;

};  // function_header_t

class function_header_fully_specified_type_identifier_left_paren_t: public function_header_t {

public:

  std::unique_ptr<fully_specified_type_t> fully_specified_type_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<token_t> left_paren_2;

  function_header_fully_specified_type_identifier_left_paren_t(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<token_t> &&left_paren_2_
  ): fully_specified_type_0(std::move(fully_specified_type_0_)),
     identifier_1(std::move(identifier_1_)),
     left_paren_2(std::move(left_paren_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // function_header_fully_specified_type_identifier_left_paren_t

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> function_header_t::pattern<0>::list = {
  pattern_item_t<fully_specified_type_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IDENTIFIER")),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_PAREN"))
};

}   // ast

}   // gliss
