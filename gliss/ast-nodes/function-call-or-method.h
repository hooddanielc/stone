#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "function-call-generic.h"

namespace gliss {

namespace ast {

class function_call_generic_t;

class function_call_or_method_t: public ast_t {

public:

  static constexpr int num_types = 1;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = function_call_or_method_function_call_generic_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~function_call_or_method_t() = default;

};  // function_call_or_method_t

class function_call_or_method_function_call_generic_t: public function_call_or_method_t {

public:

  std::unique_ptr<function_call_generic_t> function_call_generic_0;

  function_call_or_method_function_call_generic_t(
    std::unique_ptr<function_call_generic_t> &&function_call_generic_0_
  ): function_call_generic_0(std::move(function_call_generic_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // function_call_or_method_function_call_generic_t

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> function_call_or_method_t::pattern<0>::list = {
  pattern_item_t<function_call_generic_t>::get()
};

}   // ast

}   // gliss
