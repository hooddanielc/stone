#pragma once

#include "ast-nodes.h"
#include "ast-nodes/all.h"

namespace gliss {

namespace ast {

template <typename delegate_t>
void try_reduce(delegate_t &delegate) {
  switch(delegate.back()) {

  case 2: {
    if (delegate.check_stack_item(0, 2) && delegate.check_stack_item(1, 221)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_call_header_0 = std::static_pointer_cast<function_call_header_t>(nodes[0]); // group_id 221
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 2
        return ast_by_id<479>::type_t::make(function_call_header_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 2)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 2
        return ast_by_id<374>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 4: {
    if (delegate.check_stack_item(0, 4) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 242)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto identifier_list_0 = std::static_pointer_cast<identifier_list_t>(nodes[0]); // group_id 242
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 4
        return ast_by_id<507>::type_t::make(identifier_list_0, ast_token_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 4) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 250)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto init_declarator_list_0 = std::static_pointer_cast<init_declarator_list_t>(nodes[0]); // group_id 250
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 4
        return ast_by_id<533>::type_t::make(init_declarator_list_0, ast_token_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 4) && delegate.check_stack_item(1, 252)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto fully_specified_type_0 = std::static_pointer_cast<fully_specified_type_t>(nodes[0]); // group_id 252
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        return ast_by_id<461>::type_t::make(fully_specified_type_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 4) && delegate.check_stack_item(1, 263)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_specifier_0 = std::static_pointer_cast<type_specifier_t>(nodes[0]); // group_id 263
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        return ast_by_id<466>::type_t::make(type_specifier_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 4) && delegate.check_stack_item(1, 40)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 40
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        return ast_by_id<469>::type_t::make(ast_token_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 4)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 4
        return ast_by_id<213>::type_t::make(ast_token_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 4)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 4
        return ast_by_id<267>::type_t::make(ast_token_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 4)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 4
        return ast_by_id<337>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 5: {
    if (delegate.check_stack_item(0, 5) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 262)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_name_list_0 = std::static_pointer_cast<type_name_list_t>(nodes[0]); // group_id 262
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 5
        return ast_by_id<495>::type_t::make(type_name_list_0, ast_token_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 5)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 5
        return ast_by_id<279>::type_t::make(ast_token_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 5)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 5
        return ast_by_id<366>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 6: {
    if (delegate.check_stack_item(0, 6)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 6
        return ast_by_id<216>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 7: {
    if (delegate.check_stack_item(0, 7)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 7
        return ast_by_id<218>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 8: {
    if (delegate.check_stack_item(0, 8)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 8
        return ast_by_id<214>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 9: {
    if (delegate.check_stack_item(0, 9)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 9
        return ast_by_id<215>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 10: {
    if (delegate.check_stack_item(0, 10)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 10
        return ast_by_id<217>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 11: {
    if (delegate.check_stack_item(0, 11) && delegate.check_stack_item(1, 39) && delegate.check_stack_item(2, 214)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto postfix_expression_0 = std::static_pointer_cast<postfix_expression_t>(nodes[0]); // group_id 214
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 39
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 11
        return ast_by_id<535>::type_t::make(postfix_expression_0, ast_token_1, ast_token_2);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 14: {
    if (delegate.check_stack_item(0, 14) && delegate.check_stack_item(1, 214)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto postfix_expression_0 = std::static_pointer_cast<postfix_expression_t>(nodes[0]); // group_id 214
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 14
        return ast_by_id<460>::type_t::make(postfix_expression_0, ast_token_1);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 15: {
    if (delegate.check_stack_item(0, 15) && delegate.check_stack_item(1, 214)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto postfix_expression_0 = std::static_pointer_cast<postfix_expression_t>(nodes[0]); // group_id 214
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 15
        return ast_by_id<474>::type_t::make(postfix_expression_0, ast_token_1);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 23: {
    if (delegate.check_stack_item(0, 23)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 23
        return ast_by_id<281>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 24: {
    if (delegate.check_stack_item(0, 24)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 24
        return ast_by_id<282>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 25: {
    if (delegate.check_stack_item(0, 25)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 25
        return ast_by_id<284>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 26: {
    if (delegate.check_stack_item(0, 26)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 26
        return ast_by_id<283>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 27: {
    if (delegate.check_stack_item(0, 27)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 27
        return ast_by_id<286>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 28: {
    if (delegate.check_stack_item(0, 28)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 28
        return ast_by_id<287>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 29: {
    if (delegate.check_stack_item(0, 29)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 29
        return ast_by_id<288>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 30: {
    if (delegate.check_stack_item(0, 30)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 30
        return ast_by_id<289>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 31: {
    if (delegate.check_stack_item(0, 31)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 31
        return ast_by_id<290>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 32: {
    if (delegate.check_stack_item(0, 32)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 32
        return ast_by_id<285>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 33: {
    if (delegate.check_stack_item(0, 33) && delegate.check_stack_item(1, 4) && delegate.check_stack_item(2, 252)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto fully_specified_type_0 = std::static_pointer_cast<fully_specified_type_t>(nodes[0]); // group_id 252
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 33
        return ast_by_id<498>::type_t::make(fully_specified_type_0, ast_token_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 33) && delegate.check_stack_item(1, 222)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_identifier_0 = std::static_pointer_cast<function_identifier_t>(nodes[0]); // group_id 222
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 33
        return ast_by_id<491>::type_t::make(function_identifier_0, ast_token_1);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 34: {
    if (delegate.check_stack_item(0, 34) && delegate.check_stack_item(1, 262) && delegate.check_stack_item(2, 33) && delegate.check_stack_item(3, 80)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 80
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 33
        auto type_name_list_2 = std::static_pointer_cast<type_name_list_t>(nodes[2]); // group_id 262
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 34
        return ast_by_id<543>::type_t::make(ast_token_0, ast_token_1, type_name_list_2, ast_token_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 34) && delegate.check_stack_item(1, 256) && delegate.check_stack_item(2, 33) && delegate.check_stack_item(3, 119)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 119
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 33
        auto layout_qualifier_id_list_2 = std::static_pointer_cast<layout_qualifier_id_list_t>(nodes[2]); // group_id 256
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 34
        return ast_by_id<546>::type_t::make(ast_token_0, ast_token_1, layout_qualifier_id_list_2, ast_token_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 34) && delegate.check_stack_item(1, 239) && delegate.check_stack_item(2, 33)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 33
        auto expression_1 = std::static_pointer_cast<expression_t>(nodes[1]); // group_id 239
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 34
        return ast_by_id<501>::type_t::make(ast_token_0, expression_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 34) && delegate.check_stack_item(1, 244)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_declarator_0 = std::static_pointer_cast<function_declarator_t>(nodes[0]); // group_id 244
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 34
        return ast_by_id<468>::type_t::make(function_declarator_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 34) && delegate.check_stack_item(1, 220)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_call_header_with_parameters_0 = std::static_pointer_cast<function_call_header_with_parameters_t>(nodes[0]); // group_id 220
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 34
        return ast_by_id<477>::type_t::make(function_call_header_with_parameters_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 34) && delegate.check_stack_item(1, 219)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_call_header_no_parameters_0 = std::static_pointer_cast<function_call_header_no_parameters_t>(nodes[0]); // group_id 219
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 34
        return ast_by_id<478>::type_t::make(function_call_header_no_parameters_0, ast_token_1);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 36: {
    if (delegate.check_stack_item(0, 36) && delegate.check_stack_item(1, 236) && delegate.check_stack_item(2, 35) && delegate.check_stack_item(3, 264)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto array_specifier_0 = std::static_pointer_cast<array_specifier_t>(nodes[0]); // group_id 264
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 35
        auto conditional_expression_2 = std::static_pointer_cast<conditional_expression_t>(nodes[2]); // group_id 236
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 36
        return ast_by_id<539>::type_t::make(array_specifier_0, ast_token_1, conditional_expression_2, ast_token_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 36) && delegate.check_stack_item(1, 215) && delegate.check_stack_item(2, 35) && delegate.check_stack_item(3, 214)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto postfix_expression_0 = std::static_pointer_cast<postfix_expression_t>(nodes[0]); // group_id 214
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 35
        auto integer_expression_2 = std::static_pointer_cast<integer_expression_t>(nodes[2]); // group_id 215
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 36
        return ast_by_id<547>::type_t::make(postfix_expression_0, ast_token_1, integer_expression_2, ast_token_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 36) && delegate.check_stack_item(1, 35) && delegate.check_stack_item(2, 264)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto array_specifier_0 = std::static_pointer_cast<array_specifier_t>(nodes[0]); // group_id 264
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 35
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 36
        return ast_by_id<508>::type_t::make(array_specifier_0, ast_token_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 36) && delegate.check_stack_item(1, 236) && delegate.check_stack_item(2, 35)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 35
        auto conditional_expression_1 = std::static_pointer_cast<conditional_expression_t>(nodes[1]); // group_id 236
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 36
        return ast_by_id<536>::type_t::make(ast_token_0, conditional_expression_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 36) && delegate.check_stack_item(1, 35)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 35
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 36
        return ast_by_id<473>::type_t::make(ast_token_0, ast_token_1);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 38: {
    if (delegate.check_stack_item(0, 38) && delegate.check_stack_item(1, 286) && delegate.check_stack_item(2, 37) && delegate.check_stack_item(3, 34) && delegate.check_stack_item(4, 239) && delegate.check_stack_item(5, 33) && delegate.check_stack_item(6, 77)) {
      delegate.reduce(7, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 77
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 33
        auto expression_2 = std::static_pointer_cast<expression_t>(nodes[2]); // group_id 239
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 34
        auto ast_token_4 = std::static_pointer_cast<ast_token_t>(nodes[4]); // group_id 37
        auto switch_statement_list_5 = std::static_pointer_cast<switch_statement_list_t>(nodes[5]); // group_id 286
        auto ast_token_6 = std::static_pointer_cast<ast_token_t>(nodes[6]); // group_id 38
        return ast_by_id<561>::type_t::make(ast_token_0, ast_token_1, expression_2, ast_token_3, ast_token_4, switch_statement_list_5, ast_token_6);

      });
      break;
    }
    if (delegate.check_stack_item(0, 38) && delegate.check_stack_item(1, 268) && delegate.check_stack_item(2, 37) && delegate.check_stack_item(3, 4) && delegate.check_stack_item(4, 1)) {
      delegate.reduce(5, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 1
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 37
        auto struct_declaration_list_3 = std::static_pointer_cast<struct_declaration_list_t>(nodes[3]); // group_id 268
        auto ast_token_4 = std::static_pointer_cast<ast_token_t>(nodes[4]); // group_id 38
        return ast_by_id<552>::type_t::make(ast_token_0, ast_token_1, ast_token_2, struct_declaration_list_3, ast_token_4);

      });
      break;
    }
    if (delegate.check_stack_item(0, 38) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 273) && delegate.check_stack_item(3, 37)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 37
        auto initializer_list_1 = std::static_pointer_cast<initializer_list_t>(nodes[1]); // group_id 273
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 40
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 38
        return ast_by_id<540>::type_t::make(ast_token_0, initializer_list_1, ast_token_2, ast_token_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 38) && delegate.check_stack_item(1, 268) && delegate.check_stack_item(2, 37) && delegate.check_stack_item(3, 1)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 1
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 37
        auto struct_declaration_list_2 = std::static_pointer_cast<struct_declaration_list_t>(nodes[2]); // group_id 268
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 38
        return ast_by_id<544>::type_t::make(ast_token_0, ast_token_1, struct_declaration_list_2, ast_token_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 38) && delegate.check_stack_item(1, 273) && delegate.check_stack_item(2, 37)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 37
        auto initializer_list_1 = std::static_pointer_cast<initializer_list_t>(nodes[1]); // group_id 273
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 38
        return ast_by_id<509>::type_t::make(ast_token_0, initializer_list_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 38) && delegate.check_stack_item(1, 280) && delegate.check_stack_item(2, 37)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 37
        auto statement_list_1 = std::static_pointer_cast<statement_list_t>(nodes[1]); // group_id 280
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 38
        return ast_by_id<524>::type_t::make(ast_token_0, statement_list_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 38) && delegate.check_stack_item(1, 280) && delegate.check_stack_item(2, 37)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 37
        auto statement_list_1 = std::static_pointer_cast<statement_list_t>(nodes[1]); // group_id 280
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 38
        return ast_by_id<528>::type_t::make(ast_token_0, statement_list_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 38) && delegate.check_stack_item(1, 37)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 37
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 38
        return ast_by_id<483>::type_t::make(ast_token_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 38) && delegate.check_stack_item(1, 37)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 37
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 38
        return ast_by_id<484>::type_t::make(ast_token_0, ast_token_1);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 41: {
    if (delegate.check_stack_item(0, 41) && delegate.check_stack_item(1, 239) && delegate.check_stack_item(2, 78)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 78
        auto expression_1 = std::static_pointer_cast<expression_t>(nodes[1]); // group_id 239
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 41
        return ast_by_id<510>::type_t::make(ast_token_0, expression_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 41) && delegate.check_stack_item(1, 79)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 79
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 41
        return ast_by_id<481>::type_t::make(ast_token_0, ast_token_1);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 42: {
    if (delegate.check_stack_item(0, 42)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 42
        return ast_by_id<280>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 43: {
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 264) && delegate.check_stack_item(2, 4) && delegate.check_stack_item(3, 38) && delegate.check_stack_item(4, 268) && delegate.check_stack_item(5, 37) && delegate.check_stack_item(6, 4) && delegate.check_stack_item(7, 259)) {
      delegate.reduce(8, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 37
        auto struct_declaration_list_3 = std::static_pointer_cast<struct_declaration_list_t>(nodes[3]); // group_id 268
        auto ast_token_4 = std::static_pointer_cast<ast_token_t>(nodes[4]); // group_id 38
        auto ast_token_5 = std::static_pointer_cast<ast_token_t>(nodes[5]); // group_id 4
        auto array_specifier_6 = std::static_pointer_cast<array_specifier_t>(nodes[6]); // group_id 264
        auto ast_token_7 = std::static_pointer_cast<ast_token_t>(nodes[7]); // group_id 43
        return ast_by_id<562>::type_t::make(type_qualifier_0, ast_token_1, ast_token_2, struct_declaration_list_3, ast_token_4, ast_token_5, array_specifier_6, ast_token_7);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 34) && delegate.check_stack_item(2, 239) && delegate.check_stack_item(3, 33) && delegate.check_stack_item(4, 3) && delegate.check_stack_item(5, 275) && delegate.check_stack_item(6, 71)) {
      delegate.reduce(7, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 71
        auto statement_1 = std::static_pointer_cast<statement_t>(nodes[1]); // group_id 275
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 3
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 33
        auto expression_4 = std::static_pointer_cast<expression_t>(nodes[4]); // group_id 239
        auto ast_token_5 = std::static_pointer_cast<ast_token_t>(nodes[5]); // group_id 34
        auto ast_token_6 = std::static_pointer_cast<ast_token_t>(nodes[6]); // group_id 43
        return ast_by_id<560>::type_t::make(ast_token_0, statement_1, ast_token_2, ast_token_3, expression_4, ast_token_5, ast_token_6);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 4) && delegate.check_stack_item(2, 38) && delegate.check_stack_item(3, 268) && delegate.check_stack_item(4, 37) && delegate.check_stack_item(5, 4) && delegate.check_stack_item(6, 259)) {
      delegate.reduce(7, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 37
        auto struct_declaration_list_3 = std::static_pointer_cast<struct_declaration_list_t>(nodes[3]); // group_id 268
        auto ast_token_4 = std::static_pointer_cast<ast_token_t>(nodes[4]); // group_id 38
        auto ast_token_5 = std::static_pointer_cast<ast_token_t>(nodes[5]); // group_id 4
        auto ast_token_6 = std::static_pointer_cast<ast_token_t>(nodes[6]); // group_id 43
        return ast_by_id<559>::type_t::make(type_qualifier_0, ast_token_1, ast_token_2, struct_declaration_list_3, ast_token_4, ast_token_5, ast_token_6);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 38) && delegate.check_stack_item(2, 268) && delegate.check_stack_item(3, 37) && delegate.check_stack_item(4, 4) && delegate.check_stack_item(5, 259)) {
      delegate.reduce(6, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 37
        auto struct_declaration_list_3 = std::static_pointer_cast<struct_declaration_list_t>(nodes[3]); // group_id 268
        auto ast_token_4 = std::static_pointer_cast<ast_token_t>(nodes[4]); // group_id 38
        auto ast_token_5 = std::static_pointer_cast<ast_token_t>(nodes[5]); // group_id 43
        return ast_by_id<557>::type_t::make(type_qualifier_0, ast_token_1, ast_token_2, struct_declaration_list_3, ast_token_4, ast_token_5);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 263) && delegate.check_stack_item(2, 266) && delegate.check_stack_item(3, 62)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 62
        auto precision_qualifier_1 = std::static_pointer_cast<precision_qualifier_t>(nodes[1]); // group_id 266
        auto type_specifier_2 = std::static_pointer_cast<type_specifier_t>(nodes[2]); // group_id 263
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 43
        return ast_by_id<538>::type_t::make(ast_token_0, precision_qualifier_1, type_specifier_2, ast_token_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 270) && delegate.check_stack_item(2, 263) && delegate.check_stack_item(3, 259)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto type_specifier_1 = std::static_pointer_cast<type_specifier_t>(nodes[1]); // group_id 263
        auto struct_declarator_list_2 = std::static_pointer_cast<struct_declarator_list_t>(nodes[2]); // group_id 270
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 43
        return ast_by_id<541>::type_t::make(type_qualifier_0, type_specifier_1, struct_declarator_list_2, ast_token_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 242) && delegate.check_stack_item(2, 4) && delegate.check_stack_item(3, 259)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto identifier_list_2 = std::static_pointer_cast<identifier_list_t>(nodes[2]); // group_id 242
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 43
        return ast_by_id<545>::type_t::make(type_qualifier_0, ast_token_1, identifier_list_2, ast_token_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 270) && delegate.check_stack_item(2, 263)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_specifier_0 = std::static_pointer_cast<type_specifier_t>(nodes[0]); // group_id 263
        auto struct_declarator_list_1 = std::static_pointer_cast<struct_declarator_list_t>(nodes[1]); // group_id 270
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 43
        return ast_by_id<502>::type_t::make(type_specifier_0, struct_declarator_list_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 4) && delegate.check_stack_item(2, 259)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 43
        return ast_by_id<529>::type_t::make(type_qualifier_0, ast_token_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 239) && delegate.check_stack_item(2, 76)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 76
        auto expression_1 = std::static_pointer_cast<expression_t>(nodes[1]); // group_id 239
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 43
        return ast_by_id<530>::type_t::make(ast_token_0, expression_1, ast_token_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 239)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto expression_0 = std::static_pointer_cast<expression_t>(nodes[0]); // group_id 239
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        return ast_by_id<488>::type_t::make(expression_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 290)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto conditionopt_0 = std::static_pointer_cast<conditionopt_t>(nodes[0]); // group_id 290
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        return ast_by_id<454>::type_t::make(conditionopt_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 75)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 75
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        return ast_by_id<462>::type_t::make(ast_token_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 76)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 76
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        return ast_by_id<463>::type_t::make(ast_token_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 69)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 69
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        return ast_by_id<470>::type_t::make(ast_token_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 259)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        return ast_by_id<471>::type_t::make(type_qualifier_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 70)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 70
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        return ast_by_id<472>::type_t::make(ast_token_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 250)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto init_declarator_list_0 = std::static_pointer_cast<init_declarator_list_t>(nodes[0]); // group_id 250
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        return ast_by_id<475>::type_t::make(init_declarator_list_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43) && delegate.check_stack_item(1, 243)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_prototype_0 = std::static_pointer_cast<function_prototype_t>(nodes[0]); // group_id 243
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        return ast_by_id<476>::type_t::make(function_prototype_0, ast_token_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 43
        return ast_by_id<240>::type_t::make(ast_token_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 43)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 43
        return ast_by_id<219>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 44: {
    if (delegate.check_stack_item(0, 44)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 44
        return ast_by_id<244>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 45: {
    if (delegate.check_stack_item(0, 45)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 45
        return ast_by_id<243>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 46: {
    if (delegate.check_stack_item(0, 46)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 46
        return ast_by_id<245>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 47: {
    if (delegate.check_stack_item(0, 47)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 47
        return ast_by_id<242>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 57: {
    if (delegate.check_stack_item(0, 57)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 57
        return ast_by_id<330>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 58: {
    if (delegate.check_stack_item(0, 58)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 58
        return ast_by_id<340>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 59: {
    if (delegate.check_stack_item(0, 59)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 59
        return ast_by_id<277>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 60: {
    if (delegate.check_stack_item(0, 60)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 60
        return ast_by_id<275>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 61: {
    if (delegate.check_stack_item(0, 61)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 61
        return ast_by_id<273>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 63: {
    if (delegate.check_stack_item(0, 63)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 63
        return ast_by_id<349>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 64: {
    if (delegate.check_stack_item(0, 64)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 64
        return ast_by_id<379>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 65: {
    if (delegate.check_stack_item(0, 65)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 65
        return ast_by_id<375>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 66: {
    if (delegate.check_stack_item(0, 66)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 66
        return ast_by_id<376>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 67: {
    if (delegate.check_stack_item(0, 67)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 67
        return ast_by_id<377>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 68: {
    if (delegate.check_stack_item(0, 68)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 68
        return ast_by_id<378>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 80: {
    if (delegate.check_stack_item(0, 80)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 80
        return ast_by_id<364>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 81: {
    if (delegate.check_stack_item(0, 81)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 81
        return ast_by_id<386>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 82: {
    if (delegate.check_stack_item(0, 82)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 82
        return ast_by_id<212>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 83: {
    if (delegate.check_stack_item(0, 83)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 83
        return ast_by_id<388>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 84: {
    if (delegate.check_stack_item(0, 84)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 84
        return ast_by_id<389>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 85: {
    if (delegate.check_stack_item(0, 85)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 85
        return ast_by_id<390>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 86: {
    if (delegate.check_stack_item(0, 86)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 86
        return ast_by_id<391>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 87: {
    if (delegate.check_stack_item(0, 87)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 87
        return ast_by_id<392>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 88: {
    if (delegate.check_stack_item(0, 88)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 88
        return ast_by_id<393>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 89: {
    if (delegate.check_stack_item(0, 89)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 89
        return ast_by_id<394>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 90: {
    if (delegate.check_stack_item(0, 90)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 90
        return ast_by_id<380>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 91: {
    if (delegate.check_stack_item(0, 91)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 91
        return ast_by_id<381>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 92: {
    if (delegate.check_stack_item(0, 92)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 92
        return ast_by_id<382>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 93: {
    if (delegate.check_stack_item(0, 93)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 93
        return ast_by_id<395>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 94: {
    if (delegate.check_stack_item(0, 94)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 94
        return ast_by_id<396>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 95: {
    if (delegate.check_stack_item(0, 95)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 95
        return ast_by_id<397>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 96: {
    if (delegate.check_stack_item(0, 96)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 96
        return ast_by_id<353>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 97: {
    if (delegate.check_stack_item(0, 97)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 97
        return ast_by_id<351>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 98: {
    if (delegate.check_stack_item(0, 98)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 98
        return ast_by_id<352>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 99: {
    if (delegate.check_stack_item(0, 99)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 99
        return ast_by_id<350>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 100: {
    if (delegate.check_stack_item(0, 100)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 100
        return ast_by_id<356>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 101: {
    if (delegate.check_stack_item(0, 101)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 101
        return ast_by_id<354>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 102: {
    if (delegate.check_stack_item(0, 102)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 102
        return ast_by_id<355>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 103: {
    if (delegate.check_stack_item(0, 103)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 103
        return ast_by_id<357>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 104: {
    if (delegate.check_stack_item(0, 104)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 104
        return ast_by_id<339>::type_t::make(ast_token_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 104)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 104
        return ast_by_id<358>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 105: {
    if (delegate.check_stack_item(0, 105)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 105
        return ast_by_id<359>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 106: {
    if (delegate.check_stack_item(0, 106)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 106
        return ast_by_id<360>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 107: {
    if (delegate.check_stack_item(0, 107)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 107
        return ast_by_id<361>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 108: {
    if (delegate.check_stack_item(0, 108)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 108
        return ast_by_id<362>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 109: {
    if (delegate.check_stack_item(0, 109)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 109
        return ast_by_id<363>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 110: {
    if (delegate.check_stack_item(0, 110)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 110
        return ast_by_id<383>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 111: {
    if (delegate.check_stack_item(0, 111)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 111
        return ast_by_id<384>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 112: {
    if (delegate.check_stack_item(0, 112)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 112
        return ast_by_id<385>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 113: {
    if (delegate.check_stack_item(0, 113)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 113
        return ast_by_id<407>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 114: {
    if (delegate.check_stack_item(0, 114)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 114
        return ast_by_id<408>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 115: {
    if (delegate.check_stack_item(0, 115)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 115
        return ast_by_id<409>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 116: {
    if (delegate.check_stack_item(0, 116)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 116
        return ast_by_id<333>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 117: {
    if (delegate.check_stack_item(0, 117)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 117
        return ast_by_id<332>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 118: {
    if (delegate.check_stack_item(0, 118)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 118
        return ast_by_id<331>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 120: {
    if (delegate.check_stack_item(0, 120)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 120
        return ast_by_id<398>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 121: {
    if (delegate.check_stack_item(0, 121)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 121
        return ast_by_id<399>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 122: {
    if (delegate.check_stack_item(0, 122)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 122
        return ast_by_id<400>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 123: {
    if (delegate.check_stack_item(0, 123)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 123
        return ast_by_id<401>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 124: {
    if (delegate.check_stack_item(0, 124)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 124
        return ast_by_id<402>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 125: {
    if (delegate.check_stack_item(0, 125)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 125
        return ast_by_id<403>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 126: {
    if (delegate.check_stack_item(0, 126)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 126
        return ast_by_id<404>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 127: {
    if (delegate.check_stack_item(0, 127)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 127
        return ast_by_id<405>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 128: {
    if (delegate.check_stack_item(0, 128)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 128
        return ast_by_id<406>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 129: {
    if (delegate.check_stack_item(0, 129)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 129
        return ast_by_id<410>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 130: {
    if (delegate.check_stack_item(0, 130)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 130
        return ast_by_id<411>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 131: {
    if (delegate.check_stack_item(0, 131)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 131
        return ast_by_id<412>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 132: {
    if (delegate.check_stack_item(0, 132)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 132
        return ast_by_id<413>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 133: {
    if (delegate.check_stack_item(0, 133)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 133
        return ast_by_id<414>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 134: {
    if (delegate.check_stack_item(0, 134)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 134
        return ast_by_id<415>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 135: {
    if (delegate.check_stack_item(0, 135)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 135
        return ast_by_id<416>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 136: {
    if (delegate.check_stack_item(0, 136)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 136
        return ast_by_id<417>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 137: {
    if (delegate.check_stack_item(0, 137)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 137
        return ast_by_id<418>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 138: {
    if (delegate.check_stack_item(0, 138)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 138
        return ast_by_id<419>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 139: {
    if (delegate.check_stack_item(0, 139)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 139
        return ast_by_id<420>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 140: {
    if (delegate.check_stack_item(0, 140)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 140
        return ast_by_id<421>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 141: {
    if (delegate.check_stack_item(0, 141)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 141
        return ast_by_id<422>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 142: {
    if (delegate.check_stack_item(0, 142)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 142
        return ast_by_id<423>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 143: {
    if (delegate.check_stack_item(0, 143)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 143
        return ast_by_id<424>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 144: {
    if (delegate.check_stack_item(0, 144)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 144
        return ast_by_id<425>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 145: {
    if (delegate.check_stack_item(0, 145)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 145
        return ast_by_id<426>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 146: {
    if (delegate.check_stack_item(0, 146)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 146
        return ast_by_id<427>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 147: {
    if (delegate.check_stack_item(0, 147)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 147
        return ast_by_id<428>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 148: {
    if (delegate.check_stack_item(0, 148)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 148
        return ast_by_id<429>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 149: {
    if (delegate.check_stack_item(0, 149)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 149
        return ast_by_id<430>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 150: {
    if (delegate.check_stack_item(0, 150)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 150
        return ast_by_id<433>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 151: {
    if (delegate.check_stack_item(0, 151)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 151
        return ast_by_id<434>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 152: {
    if (delegate.check_stack_item(0, 152)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 152
        return ast_by_id<435>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 153: {
    if (delegate.check_stack_item(0, 153)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 153
        return ast_by_id<436>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 154: {
    if (delegate.check_stack_item(0, 154)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 154
        return ast_by_id<437>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 155: {
    if (delegate.check_stack_item(0, 155)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 155
        return ast_by_id<438>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 156: {
    if (delegate.check_stack_item(0, 156)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 156
        return ast_by_id<440>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 157: {
    if (delegate.check_stack_item(0, 157)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 157
        return ast_by_id<441>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 158: {
    if (delegate.check_stack_item(0, 158)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 158
        return ast_by_id<442>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 159: {
    if (delegate.check_stack_item(0, 159)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 159
        return ast_by_id<443>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 160: {
    if (delegate.check_stack_item(0, 160)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 160
        return ast_by_id<444>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 161: {
    if (delegate.check_stack_item(0, 161)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 161
        return ast_by_id<445>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 162: {
    if (delegate.check_stack_item(0, 162)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 162
        return ast_by_id<447>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 163: {
    if (delegate.check_stack_item(0, 163)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 163
        return ast_by_id<448>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 164: {
    if (delegate.check_stack_item(0, 164)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 164
        return ast_by_id<449>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 165: {
    if (delegate.check_stack_item(0, 165)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 165
        return ast_by_id<450>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 166: {
    if (delegate.check_stack_item(0, 166)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 166
        return ast_by_id<451>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 167: {
    if (delegate.check_stack_item(0, 167)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 167
        return ast_by_id<452>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 168: {
    if (delegate.check_stack_item(0, 168)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 168
        return ast_by_id<453>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 169: {
    if (delegate.check_stack_item(0, 169)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 169
        return ast_by_id<431>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 170: {
    if (delegate.check_stack_item(0, 170)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 170
        return ast_by_id<432>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 171: {
    if (delegate.check_stack_item(0, 171)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 171
        return ast_by_id<439>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 172: {
    if (delegate.check_stack_item(0, 172)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 172
        return ast_by_id<446>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 173: {
    if (delegate.check_stack_item(0, 173)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 173
        return ast_by_id<373>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 174: {
    if (delegate.check_stack_item(0, 174)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 174
        return ast_by_id<372>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 175: {
    if (delegate.check_stack_item(0, 175)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 175
        return ast_by_id<371>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 176: {
    if (delegate.check_stack_item(0, 176)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 176
        return ast_by_id<370>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 177: {
    if (delegate.check_stack_item(0, 177)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 177
        return ast_by_id<369>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 178: {
    if (delegate.check_stack_item(0, 178)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 178
        return ast_by_id<367>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 179: {
    if (delegate.check_stack_item(0, 179)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 179
        return ast_by_id<365>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 180: {
    if (delegate.check_stack_item(0, 180)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 180
        return ast_by_id<342>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 181: {
    if (delegate.check_stack_item(0, 181)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 181
        return ast_by_id<338>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 182: {
    if (delegate.check_stack_item(0, 182)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 182
        return ast_by_id<336>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 183: {
    if (delegate.check_stack_item(0, 183)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 183
        return ast_by_id<334>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 184: {
    if (delegate.check_stack_item(0, 184)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 184
        return ast_by_id<329>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 185: {
    if (delegate.check_stack_item(0, 185)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 185
        return ast_by_id<327>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 186: {
    if (delegate.check_stack_item(0, 186)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 186
        return ast_by_id<326>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 187: {
    if (delegate.check_stack_item(0, 187)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 187
        return ast_by_id<325>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 188: {
    if (delegate.check_stack_item(0, 188)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 188
        return ast_by_id<324>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 189: {
    if (delegate.check_stack_item(0, 189)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 189
        return ast_by_id<322>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 190: {
    if (delegate.check_stack_item(0, 190)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 190
        return ast_by_id<321>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 191: {
    if (delegate.check_stack_item(0, 191)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 191
        return ast_by_id<320>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 192: {
    if (delegate.check_stack_item(0, 192)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 192
        return ast_by_id<319>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 193: {
    if (delegate.check_stack_item(0, 193)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 193
        return ast_by_id<315>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 194: {
    if (delegate.check_stack_item(0, 194)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 194
        return ast_by_id<313>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 195: {
    if (delegate.check_stack_item(0, 195)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 195
        return ast_by_id<312>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 196: {
    if (delegate.check_stack_item(0, 196)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 196
        return ast_by_id<311>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 197: {
    if (delegate.check_stack_item(0, 197)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 197
        return ast_by_id<310>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 198: {
    if (delegate.check_stack_item(0, 198)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 198
        return ast_by_id<309>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 199: {
    if (delegate.check_stack_item(0, 199)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 199
        return ast_by_id<308>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 200: {
    if (delegate.check_stack_item(0, 200)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 200
        return ast_by_id<305>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 201: {
    if (delegate.check_stack_item(0, 201)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 201
        return ast_by_id<304>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 202: {
    if (delegate.check_stack_item(0, 202)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 202
        return ast_by_id<303>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 203: {
    if (delegate.check_stack_item(0, 203)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 203
        return ast_by_id<302>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 204: {
    if (delegate.check_stack_item(0, 204)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 204
        return ast_by_id<301>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 205: {
    if (delegate.check_stack_item(0, 205)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 205
        return ast_by_id<300>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 206: {
    if (delegate.check_stack_item(0, 206)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 206
        return ast_by_id<299>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 207: {
    if (delegate.check_stack_item(0, 207)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 207
        return ast_by_id<298>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 208: {
    if (delegate.check_stack_item(0, 208)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 208
        return ast_by_id<297>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 209: {
    if (delegate.check_stack_item(0, 209)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 209
        return ast_by_id<296>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 210: {
    if (delegate.check_stack_item(0, 210)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 210
        return ast_by_id<295>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 211: {
    if (delegate.check_stack_item(0, 211)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 211
        return ast_by_id<294>::type_t::make(ast_token_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 212: {
    if (delegate.check_stack_item(0, 212)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto variable_identifier_0 = std::static_pointer_cast<variable_identifier_t>(nodes[0]); // group_id 212
        return ast_by_id<387>::type_t::make(variable_identifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 213: {
    if (delegate.check_stack_item(0, 213)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto primary_expression_0 = std::static_pointer_cast<primary_expression_t>(nodes[0]); // group_id 213
        return ast_by_id<220>::type_t::make(primary_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 214: {
    if (delegate.check_stack_item(0, 214)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto postfix_expression_0 = std::static_pointer_cast<postfix_expression_t>(nodes[0]); // group_id 214
        return ast_by_id<237>::type_t::make(postfix_expression_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 214)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto postfix_expression_0 = std::static_pointer_cast<postfix_expression_t>(nodes[0]); // group_id 214
        return ast_by_id<238>::type_t::make(postfix_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 216: {
    if (delegate.check_stack_item(0, 216)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_call_0 = std::static_pointer_cast<function_call_t>(nodes[0]); // group_id 216
        return ast_by_id<222>::type_t::make(function_call_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 217: {
    if (delegate.check_stack_item(0, 217)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_call_or_method_0 = std::static_pointer_cast<function_call_or_method_t>(nodes[0]); // group_id 217
        return ast_by_id<227>::type_t::make(function_call_or_method_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 218: {
    if (delegate.check_stack_item(0, 218)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_call_generic_0 = std::static_pointer_cast<function_call_generic_t>(nodes[0]); // group_id 218
        return ast_by_id<228>::type_t::make(function_call_generic_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 221: {
    if (delegate.check_stack_item(0, 221)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_call_header_0 = std::static_pointer_cast<function_call_header_t>(nodes[0]); // group_id 221
        return ast_by_id<232>::type_t::make(function_call_header_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 223: {
    if (delegate.check_stack_item(0, 223) && delegate.check_stack_item(1, 50) && delegate.check_stack_item(2, 225)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto multiplicative_expression_0 = std::static_pointer_cast<multiplicative_expression_t>(nodes[0]); // group_id 225
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 50
        auto unary_expression_2 = std::static_pointer_cast<unary_expression_t>(nodes[2]); // group_id 223
        return ast_by_id<522>::type_t::make(multiplicative_expression_0, ast_token_1, unary_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 223) && delegate.check_stack_item(1, 49) && delegate.check_stack_item(2, 225)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto multiplicative_expression_0 = std::static_pointer_cast<multiplicative_expression_t>(nodes[0]); // group_id 225
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 49
        auto unary_expression_2 = std::static_pointer_cast<unary_expression_t>(nodes[2]); // group_id 223
        return ast_by_id<525>::type_t::make(multiplicative_expression_0, ast_token_1, unary_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 223) && delegate.check_stack_item(1, 48) && delegate.check_stack_item(2, 225)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto multiplicative_expression_0 = std::static_pointer_cast<multiplicative_expression_t>(nodes[0]); // group_id 225
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 48
        auto unary_expression_2 = std::static_pointer_cast<unary_expression_t>(nodes[2]); // group_id 223
        return ast_by_id<526>::type_t::make(multiplicative_expression_0, ast_token_1, unary_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 223) && delegate.check_stack_item(1, 224)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto unary_operator_0 = std::static_pointer_cast<unary_operator_t>(nodes[0]); // group_id 224
        auto unary_expression_1 = std::static_pointer_cast<unary_expression_t>(nodes[1]); // group_id 223
        return ast_by_id<485>::type_t::make(unary_operator_0, unary_expression_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 223) && delegate.check_stack_item(1, 15)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 15
        auto unary_expression_1 = std::static_pointer_cast<unary_expression_t>(nodes[1]); // group_id 223
        return ast_by_id<487>::type_t::make(ast_token_0, unary_expression_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 223) && delegate.check_stack_item(1, 14)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 14
        auto unary_expression_1 = std::static_pointer_cast<unary_expression_t>(nodes[1]); // group_id 223
        return ast_by_id<490>::type_t::make(ast_token_0, unary_expression_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 223)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto unary_expression_0 = std::static_pointer_cast<unary_expression_t>(nodes[0]); // group_id 223
        return ast_by_id<246>::type_t::make(unary_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 225: {
    if (delegate.check_stack_item(0, 225) && delegate.check_stack_item(1, 45) && delegate.check_stack_item(2, 226)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto additive_expression_0 = std::static_pointer_cast<additive_expression_t>(nodes[0]); // group_id 226
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 45
        auto multiplicative_expression_2 = std::static_pointer_cast<multiplicative_expression_t>(nodes[2]); // group_id 225
        return ast_by_id<520>::type_t::make(additive_expression_0, ast_token_1, multiplicative_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 225) && delegate.check_stack_item(1, 47) && delegate.check_stack_item(2, 226)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto additive_expression_0 = std::static_pointer_cast<additive_expression_t>(nodes[0]); // group_id 226
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 47
        auto multiplicative_expression_2 = std::static_pointer_cast<multiplicative_expression_t>(nodes[2]); // group_id 225
        return ast_by_id<521>::type_t::make(additive_expression_0, ast_token_1, multiplicative_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 225)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto multiplicative_expression_0 = std::static_pointer_cast<multiplicative_expression_t>(nodes[0]); // group_id 225
        return ast_by_id<250>::type_t::make(multiplicative_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 226: {
    if (delegate.check_stack_item(0, 226) && delegate.check_stack_item(1, 13) && delegate.check_stack_item(2, 227)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto shift_expression_0 = std::static_pointer_cast<shift_expression_t>(nodes[0]); // group_id 227
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 13
        auto additive_expression_2 = std::static_pointer_cast<additive_expression_t>(nodes[2]); // group_id 226
        return ast_by_id<518>::type_t::make(shift_expression_0, ast_token_1, additive_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 226) && delegate.check_stack_item(1, 12) && delegate.check_stack_item(2, 227)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto shift_expression_0 = std::static_pointer_cast<shift_expression_t>(nodes[0]); // group_id 227
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 12
        auto additive_expression_2 = std::static_pointer_cast<additive_expression_t>(nodes[2]); // group_id 226
        return ast_by_id<519>::type_t::make(shift_expression_0, ast_token_1, additive_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 226)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto additive_expression_0 = std::static_pointer_cast<additive_expression_t>(nodes[0]); // group_id 226
        return ast_by_id<253>::type_t::make(additive_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 227: {
    if (delegate.check_stack_item(0, 227) && delegate.check_stack_item(1, 17) && delegate.check_stack_item(2, 228)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto relational_expression_0 = std::static_pointer_cast<relational_expression_t>(nodes[0]); // group_id 228
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 17
        auto shift_expression_2 = std::static_pointer_cast<shift_expression_t>(nodes[2]); // group_id 227
        return ast_by_id<514>::type_t::make(relational_expression_0, ast_token_1, shift_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 227) && delegate.check_stack_item(1, 16) && delegate.check_stack_item(2, 228)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto relational_expression_0 = std::static_pointer_cast<relational_expression_t>(nodes[0]); // group_id 228
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 16
        auto shift_expression_2 = std::static_pointer_cast<shift_expression_t>(nodes[2]); // group_id 227
        return ast_by_id<515>::type_t::make(relational_expression_0, ast_token_1, shift_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 227) && delegate.check_stack_item(1, 52) && delegate.check_stack_item(2, 228)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto relational_expression_0 = std::static_pointer_cast<relational_expression_t>(nodes[0]); // group_id 228
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 52
        auto shift_expression_2 = std::static_pointer_cast<shift_expression_t>(nodes[2]); // group_id 227
        return ast_by_id<516>::type_t::make(relational_expression_0, ast_token_1, shift_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 227) && delegate.check_stack_item(1, 51) && delegate.check_stack_item(2, 228)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto relational_expression_0 = std::static_pointer_cast<relational_expression_t>(nodes[0]); // group_id 228
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 51
        auto shift_expression_2 = std::static_pointer_cast<shift_expression_t>(nodes[2]); // group_id 227
        return ast_by_id<517>::type_t::make(relational_expression_0, ast_token_1, shift_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 227)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto shift_expression_0 = std::static_pointer_cast<shift_expression_t>(nodes[0]); // group_id 227
        return ast_by_id<256>::type_t::make(shift_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 228: {
    if (delegate.check_stack_item(0, 228) && delegate.check_stack_item(1, 19) && delegate.check_stack_item(2, 229)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto equality_expression_0 = std::static_pointer_cast<equality_expression_t>(nodes[0]); // group_id 229
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 19
        auto relational_expression_2 = std::static_pointer_cast<relational_expression_t>(nodes[2]); // group_id 228
        return ast_by_id<511>::type_t::make(equality_expression_0, ast_token_1, relational_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 228) && delegate.check_stack_item(1, 18) && delegate.check_stack_item(2, 229)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto equality_expression_0 = std::static_pointer_cast<equality_expression_t>(nodes[0]); // group_id 229
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 18
        auto relational_expression_2 = std::static_pointer_cast<relational_expression_t>(nodes[2]); // group_id 228
        return ast_by_id<513>::type_t::make(equality_expression_0, ast_token_1, relational_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 228)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto relational_expression_0 = std::static_pointer_cast<relational_expression_t>(nodes[0]); // group_id 228
        return ast_by_id<261>::type_t::make(relational_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 229: {
    if (delegate.check_stack_item(0, 229) && delegate.check_stack_item(1, 55) && delegate.check_stack_item(2, 230)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto and_expression_0 = std::static_pointer_cast<and_expression_t>(nodes[0]); // group_id 230
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 55
        auto equality_expression_2 = std::static_pointer_cast<equality_expression_t>(nodes[2]); // group_id 229
        return ast_by_id<523>::type_t::make(and_expression_0, ast_token_1, equality_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 229)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto equality_expression_0 = std::static_pointer_cast<equality_expression_t>(nodes[0]); // group_id 229
        return ast_by_id<264>::type_t::make(equality_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 230: {
    if (delegate.check_stack_item(0, 230) && delegate.check_stack_item(1, 54) && delegate.check_stack_item(2, 231)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto exclusive_or_expression_0 = std::static_pointer_cast<exclusive_or_expression_t>(nodes[0]); // group_id 231
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 54
        auto and_expression_2 = std::static_pointer_cast<and_expression_t>(nodes[2]); // group_id 230
        return ast_by_id<506>::type_t::make(exclusive_or_expression_0, ast_token_1, and_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 230)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto and_expression_0 = std::static_pointer_cast<and_expression_t>(nodes[0]); // group_id 230
        return ast_by_id<266>::type_t::make(and_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 231: {
    if (delegate.check_stack_item(0, 231) && delegate.check_stack_item(1, 53) && delegate.check_stack_item(2, 232)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto inclusive_or_expression_0 = std::static_pointer_cast<inclusive_or_expression_t>(nodes[0]); // group_id 232
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 53
        auto exclusive_or_expression_2 = std::static_pointer_cast<exclusive_or_expression_t>(nodes[2]); // group_id 231
        return ast_by_id<504>::type_t::make(inclusive_or_expression_0, ast_token_1, exclusive_or_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 231)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto exclusive_or_expression_0 = std::static_pointer_cast<exclusive_or_expression_t>(nodes[0]); // group_id 231
        return ast_by_id<268>::type_t::make(exclusive_or_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 232: {
    if (delegate.check_stack_item(0, 232) && delegate.check_stack_item(1, 20) && delegate.check_stack_item(2, 233)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto logical_and_expression_0 = std::static_pointer_cast<logical_and_expression_t>(nodes[0]); // group_id 233
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 20
        auto inclusive_or_expression_2 = std::static_pointer_cast<inclusive_or_expression_t>(nodes[2]); // group_id 232
        return ast_by_id<500>::type_t::make(logical_and_expression_0, ast_token_1, inclusive_or_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 232)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto inclusive_or_expression_0 = std::static_pointer_cast<inclusive_or_expression_t>(nodes[0]); // group_id 232
        return ast_by_id<270>::type_t::make(inclusive_or_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 233: {
    if (delegate.check_stack_item(0, 233) && delegate.check_stack_item(1, 22) && delegate.check_stack_item(2, 234)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto logical_xor_expression_0 = std::static_pointer_cast<logical_xor_expression_t>(nodes[0]); // group_id 234
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 22
        auto logical_and_expression_2 = std::static_pointer_cast<logical_and_expression_t>(nodes[2]); // group_id 233
        return ast_by_id<497>::type_t::make(logical_xor_expression_0, ast_token_1, logical_and_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 233)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto logical_and_expression_0 = std::static_pointer_cast<logical_and_expression_t>(nodes[0]); // group_id 233
        return ast_by_id<272>::type_t::make(logical_and_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 234: {
    if (delegate.check_stack_item(0, 234) && delegate.check_stack_item(1, 21) && delegate.check_stack_item(2, 235)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto logical_or_expression_0 = std::static_pointer_cast<logical_or_expression_t>(nodes[0]); // group_id 235
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 21
        auto logical_xor_expression_2 = std::static_pointer_cast<logical_xor_expression_t>(nodes[2]); // group_id 234
        return ast_by_id<496>::type_t::make(logical_or_expression_0, ast_token_1, logical_xor_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 234)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto logical_xor_expression_0 = std::static_pointer_cast<logical_xor_expression_t>(nodes[0]); // group_id 234
        return ast_by_id<274>::type_t::make(logical_xor_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 235: {
    if (delegate.check_stack_item(0, 235)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto logical_or_expression_0 = std::static_pointer_cast<logical_or_expression_t>(nodes[0]); // group_id 235
        return ast_by_id<276>::type_t::make(logical_or_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 236: {
    if (delegate.check_stack_item(0, 236)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto conditional_expression_0 = std::static_pointer_cast<conditional_expression_t>(nodes[0]); // group_id 236
        return ast_by_id<278>::type_t::make(conditional_expression_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 236)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto conditional_expression_0 = std::static_pointer_cast<conditional_expression_t>(nodes[0]); // group_id 236
        return ast_by_id<293>::type_t::make(conditional_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 237: {
    if (delegate.check_stack_item(0, 237) && delegate.check_stack_item(1, 41) && delegate.check_stack_item(2, 239) && delegate.check_stack_item(3, 56) && delegate.check_stack_item(4, 235)) {
      delegate.reduce(5, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto logical_or_expression_0 = std::static_pointer_cast<logical_or_expression_t>(nodes[0]); // group_id 235
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 56
        auto expression_2 = std::static_pointer_cast<expression_t>(nodes[2]); // group_id 239
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 41
        auto assignment_expression_4 = std::static_pointer_cast<assignment_expression_t>(nodes[4]); // group_id 237
        return ast_by_id<551>::type_t::make(logical_or_expression_0, ast_token_1, expression_2, ast_token_3, assignment_expression_4);

      });
      break;
    }
    if (delegate.check_stack_item(0, 237) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 239)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto expression_0 = std::static_pointer_cast<expression_t>(nodes[0]); // group_id 239
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto assignment_expression_2 = std::static_pointer_cast<assignment_expression_t>(nodes[2]); // group_id 237
        return ast_by_id<493>::type_t::make(expression_0, ast_token_1, assignment_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 237) && delegate.check_stack_item(1, 238) && delegate.check_stack_item(2, 223)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto unary_expression_0 = std::static_pointer_cast<unary_expression_t>(nodes[0]); // group_id 223
        auto assignment_operator_1 = std::static_pointer_cast<assignment_operator_t>(nodes[1]); // group_id 238
        auto assignment_expression_2 = std::static_pointer_cast<assignment_expression_t>(nodes[2]); // group_id 237
        return ast_by_id<494>::type_t::make(unary_expression_0, assignment_operator_1, assignment_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 237) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 220)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_call_header_with_parameters_0 = std::static_pointer_cast<function_call_header_with_parameters_t>(nodes[0]); // group_id 220
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto assignment_expression_2 = std::static_pointer_cast<assignment_expression_t>(nodes[2]); // group_id 237
        return ast_by_id<537>::type_t::make(function_call_header_with_parameters_0, ast_token_1, assignment_expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 237) && delegate.check_stack_item(1, 221)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_call_header_0 = std::static_pointer_cast<function_call_header_t>(nodes[0]); // group_id 221
        auto assignment_expression_1 = std::static_pointer_cast<assignment_expression_t>(nodes[1]); // group_id 237
        return ast_by_id<489>::type_t::make(function_call_header_0, assignment_expression_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 237)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto assignment_expression_0 = std::static_pointer_cast<assignment_expression_t>(nodes[0]); // group_id 237
        return ast_by_id<265>::type_t::make(assignment_expression_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 237)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto assignment_expression_0 = std::static_pointer_cast<assignment_expression_t>(nodes[0]); // group_id 237
        return ast_by_id<291>::type_t::make(assignment_expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 239: {
    if (delegate.check_stack_item(0, 239) && delegate.check_stack_item(1, 43) && delegate.check_stack_item(2, 290)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto conditionopt_0 = std::static_pointer_cast<conditionopt_t>(nodes[0]); // group_id 290
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 43
        auto expression_2 = std::static_pointer_cast<expression_t>(nodes[2]); // group_id 239
        return ast_by_id<532>::type_t::make(conditionopt_0, ast_token_1, expression_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 239)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto expression_0 = std::static_pointer_cast<expression_t>(nodes[0]); // group_id 239
        return ast_by_id<226>::type_t::make(expression_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 239)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto expression_0 = std::static_pointer_cast<expression_t>(nodes[0]); // group_id 239
        return ast_by_id<235>::type_t::make(expression_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 240: {
    if (delegate.check_stack_item(0, 240) && delegate.check_stack_item(1, 42) && delegate.check_stack_item(2, 4)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 4
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 42
        auto constant_expression_2 = std::static_pointer_cast<constant_expression_t>(nodes[2]); // group_id 240
        return ast_by_id<527>::type_t::make(ast_token_0, ast_token_1, constant_expression_2);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 241: {
    if (delegate.check_stack_item(0, 241)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto declaration_0 = std::static_pointer_cast<declaration_t>(nodes[0]); // group_id 241
        return ast_by_id<221>::type_t::make(declaration_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 241)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto declaration_0 = std::static_pointer_cast<declaration_t>(nodes[0]); // group_id 241
        return ast_by_id<262>::type_t::make(declaration_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 245: {
    if (delegate.check_stack_item(0, 245)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_header_with_parameters_0 = std::static_pointer_cast<function_header_with_parameters_t>(nodes[0]); // group_id 245
        return ast_by_id<307>::type_t::make(function_header_with_parameters_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 246: {
    if (delegate.check_stack_item(0, 246)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_header_0 = std::static_pointer_cast<function_header_t>(nodes[0]); // group_id 246
        return ast_by_id<306>::type_t::make(function_header_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 247: {
    if (delegate.check_stack_item(0, 247) && delegate.check_stack_item(1, 259)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto parameter_declarator_1 = std::static_pointer_cast<parameter_declarator_t>(nodes[1]); // group_id 247
        return ast_by_id<465>::type_t::make(type_qualifier_0, parameter_declarator_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 247)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto parameter_declarator_0 = std::static_pointer_cast<parameter_declarator_t>(nodes[0]); // group_id 247
        return ast_by_id<314>::type_t::make(parameter_declarator_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 248: {
    if (delegate.check_stack_item(0, 248) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 245)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_header_with_parameters_0 = std::static_pointer_cast<function_header_with_parameters_t>(nodes[0]); // group_id 245
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto parameter_declaration_2 = std::static_pointer_cast<parameter_declaration_t>(nodes[2]); // group_id 248
        return ast_by_id<499>::type_t::make(function_header_with_parameters_0, ast_token_1, parameter_declaration_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 248) && delegate.check_stack_item(1, 246)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_header_0 = std::static_pointer_cast<function_header_t>(nodes[0]); // group_id 246
        auto parameter_declaration_1 = std::static_pointer_cast<parameter_declaration_t>(nodes[1]); // group_id 248
        return ast_by_id<467>::type_t::make(function_header_0, parameter_declaration_1);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 249: {
    if (delegate.check_stack_item(0, 249) && delegate.check_stack_item(1, 259)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto parameter_type_specifier_1 = std::static_pointer_cast<parameter_type_specifier_t>(nodes[1]); // group_id 249
        return ast_by_id<464>::type_t::make(type_qualifier_0, parameter_type_specifier_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 249)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto parameter_type_specifier_0 = std::static_pointer_cast<parameter_type_specifier_t>(nodes[0]); // group_id 249
        return ast_by_id<316>::type_t::make(parameter_type_specifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 251: {
    if (delegate.check_stack_item(0, 251)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto single_declaration_0 = std::static_pointer_cast<single_declaration_t>(nodes[0]); // group_id 251
        return ast_by_id<318>::type_t::make(single_declaration_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 252: {
    if (delegate.check_stack_item(0, 252)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto fully_specified_type_0 = std::static_pointer_cast<fully_specified_type_t>(nodes[0]); // group_id 252
        return ast_by_id<323>::type_t::make(fully_specified_type_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 253: {
    if (delegate.check_stack_item(0, 253)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto invariant_qualifier_0 = std::static_pointer_cast<invariant_qualifier_t>(nodes[0]); // group_id 253
        return ast_by_id<347>::type_t::make(invariant_qualifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 254: {
    if (delegate.check_stack_item(0, 254)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto interpolation_qualifier_0 = std::static_pointer_cast<interpolation_qualifier_t>(nodes[0]); // group_id 254
        return ast_by_id<346>::type_t::make(interpolation_qualifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 255: {
    if (delegate.check_stack_item(0, 255)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto layout_qualifier_0 = std::static_pointer_cast<layout_qualifier_t>(nodes[0]); // group_id 255
        return ast_by_id<344>::type_t::make(layout_qualifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 257: {
    if (delegate.check_stack_item(0, 257) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 256)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto layout_qualifier_id_list_0 = std::static_pointer_cast<layout_qualifier_id_list_t>(nodes[0]); // group_id 256
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto layout_qualifier_id_2 = std::static_pointer_cast<layout_qualifier_id_t>(nodes[2]); // group_id 257
        return ast_by_id<531>::type_t::make(layout_qualifier_id_list_0, ast_token_1, layout_qualifier_id_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 257)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto layout_qualifier_id_0 = std::static_pointer_cast<layout_qualifier_id_t>(nodes[0]); // group_id 257
        return ast_by_id<335>::type_t::make(layout_qualifier_id_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 258: {
    if (delegate.check_stack_item(0, 258)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto precise_qualifier_0 = std::static_pointer_cast<precise_qualifier_t>(nodes[0]); // group_id 258
        return ast_by_id<348>::type_t::make(precise_qualifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 260: {
    if (delegate.check_stack_item(0, 260) && delegate.check_stack_item(1, 259)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto single_type_qualifier_1 = std::static_pointer_cast<single_type_qualifier_t>(nodes[1]); // group_id 260
        return ast_by_id<457>::type_t::make(type_qualifier_0, single_type_qualifier_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 260)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto single_type_qualifier_0 = std::static_pointer_cast<single_type_qualifier_t>(nodes[0]); // group_id 260
        return ast_by_id<341>::type_t::make(single_type_qualifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 261: {
    if (delegate.check_stack_item(0, 261)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto storage_qualifier_0 = std::static_pointer_cast<storage_qualifier_t>(nodes[0]); // group_id 261
        return ast_by_id<343>::type_t::make(storage_qualifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 263: {
    if (delegate.check_stack_item(0, 263) && delegate.check_stack_item(1, 259)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_qualifier_0 = std::static_pointer_cast<type_qualifier_t>(nodes[0]); // group_id 259
        auto type_specifier_1 = std::static_pointer_cast<type_specifier_t>(nodes[1]); // group_id 263
        return ast_by_id<458>::type_t::make(type_qualifier_0, type_specifier_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 263)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_specifier_0 = std::static_pointer_cast<type_specifier_t>(nodes[0]); // group_id 263
        return ast_by_id<236>::type_t::make(type_specifier_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 263)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_specifier_0 = std::static_pointer_cast<type_specifier_t>(nodes[0]); // group_id 263
        return ast_by_id<317>::type_t::make(type_specifier_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 263)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_specifier_0 = std::static_pointer_cast<type_specifier_t>(nodes[0]); // group_id 263
        return ast_by_id<328>::type_t::make(type_specifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 264: {
    if (delegate.check_stack_item(0, 264) && delegate.check_stack_item(1, 4) && delegate.check_stack_item(2, 40) && delegate.check_stack_item(3, 250)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto init_declarator_list_0 = std::static_pointer_cast<init_declarator_list_t>(nodes[0]); // group_id 250
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 4
        auto array_specifier_3 = std::static_pointer_cast<array_specifier_t>(nodes[3]); // group_id 264
        return ast_by_id<542>::type_t::make(init_declarator_list_0, ast_token_1, ast_token_2, array_specifier_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 264) && delegate.check_stack_item(1, 4) && delegate.check_stack_item(2, 263)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_specifier_0 = std::static_pointer_cast<type_specifier_t>(nodes[0]); // group_id 263
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto array_specifier_2 = std::static_pointer_cast<array_specifier_t>(nodes[2]); // group_id 264
        return ast_by_id<492>::type_t::make(type_specifier_0, ast_token_1, array_specifier_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 264) && delegate.check_stack_item(1, 4) && delegate.check_stack_item(2, 252)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto fully_specified_type_0 = std::static_pointer_cast<fully_specified_type_t>(nodes[0]); // group_id 252
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto array_specifier_2 = std::static_pointer_cast<array_specifier_t>(nodes[2]); // group_id 264
        return ast_by_id<503>::type_t::make(fully_specified_type_0, ast_token_1, array_specifier_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 264) && delegate.check_stack_item(1, 265)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_specifier_nonarray_0 = std::static_pointer_cast<type_specifier_nonarray_t>(nodes[0]); // group_id 265
        auto array_specifier_1 = std::static_pointer_cast<array_specifier_t>(nodes[1]); // group_id 264
        return ast_by_id<456>::type_t::make(type_specifier_nonarray_0, array_specifier_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 264) && delegate.check_stack_item(1, 4)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 4
        auto array_specifier_1 = std::static_pointer_cast<array_specifier_t>(nodes[1]); // group_id 264
        return ast_by_id<482>::type_t::make(ast_token_0, array_specifier_1);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 265: {
    if (delegate.check_stack_item(0, 265)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto type_specifier_nonarray_0 = std::static_pointer_cast<type_specifier_nonarray_t>(nodes[0]); // group_id 265
        return ast_by_id<368>::type_t::make(type_specifier_nonarray_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 266: {
    if (delegate.check_stack_item(0, 266)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto precision_qualifier_0 = std::static_pointer_cast<precision_qualifier_t>(nodes[0]); // group_id 266
        return ast_by_id<345>::type_t::make(precision_qualifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 267: {
    if (delegate.check_stack_item(0, 267)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto struct_specifier_0 = std::static_pointer_cast<struct_specifier_t>(nodes[0]); // group_id 267
        return ast_by_id<292>::type_t::make(struct_specifier_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 269: {
    if (delegate.check_stack_item(0, 269) && delegate.check_stack_item(1, 268)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto struct_declaration_list_0 = std::static_pointer_cast<struct_declaration_list_t>(nodes[0]); // group_id 268
        auto struct_declaration_1 = std::static_pointer_cast<struct_declaration_t>(nodes[1]); // group_id 269
        return ast_by_id<480>::type_t::make(struct_declaration_list_0, struct_declaration_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 269)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto struct_declaration_0 = std::static_pointer_cast<struct_declaration_t>(nodes[0]); // group_id 269
        return ast_by_id<271>::type_t::make(struct_declaration_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 271: {
    if (delegate.check_stack_item(0, 271) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 270)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto struct_declarator_list_0 = std::static_pointer_cast<struct_declarator_list_t>(nodes[0]); // group_id 270
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto struct_declarator_2 = std::static_pointer_cast<struct_declarator_t>(nodes[2]); // group_id 271
        return ast_by_id<505>::type_t::make(struct_declarator_list_0, ast_token_1, struct_declarator_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 271)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto struct_declarator_0 = std::static_pointer_cast<struct_declarator_t>(nodes[0]); // group_id 271
        return ast_by_id<269>::type_t::make(struct_declarator_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 272: {
    if (delegate.check_stack_item(0, 272) && delegate.check_stack_item(1, 42) && delegate.check_stack_item(2, 264) && delegate.check_stack_item(3, 4) && delegate.check_stack_item(4, 40) && delegate.check_stack_item(5, 250)) {
      delegate.reduce(6, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto init_declarator_list_0 = std::static_pointer_cast<init_declarator_list_t>(nodes[0]); // group_id 250
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 4
        auto array_specifier_3 = std::static_pointer_cast<array_specifier_t>(nodes[3]); // group_id 264
        auto ast_token_4 = std::static_pointer_cast<ast_token_t>(nodes[4]); // group_id 42
        auto initializer_5 = std::static_pointer_cast<initializer_t>(nodes[5]); // group_id 272
        return ast_by_id<558>::type_t::make(init_declarator_list_0, ast_token_1, ast_token_2, array_specifier_3, ast_token_4, initializer_5);

      });
      break;
    }
    if (delegate.check_stack_item(0, 272) && delegate.check_stack_item(1, 42) && delegate.check_stack_item(2, 4) && delegate.check_stack_item(3, 40) && delegate.check_stack_item(4, 250)) {
      delegate.reduce(5, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto init_declarator_list_0 = std::static_pointer_cast<init_declarator_list_t>(nodes[0]); // group_id 250
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 4
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 42
        auto initializer_4 = std::static_pointer_cast<initializer_t>(nodes[4]); // group_id 272
        return ast_by_id<554>::type_t::make(init_declarator_list_0, ast_token_1, ast_token_2, ast_token_3, initializer_4);

      });
      break;
    }
    if (delegate.check_stack_item(0, 272) && delegate.check_stack_item(1, 42) && delegate.check_stack_item(2, 264) && delegate.check_stack_item(3, 4) && delegate.check_stack_item(4, 252)) {
      delegate.reduce(5, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto fully_specified_type_0 = std::static_pointer_cast<fully_specified_type_t>(nodes[0]); // group_id 252
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto array_specifier_2 = std::static_pointer_cast<array_specifier_t>(nodes[2]); // group_id 264
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 42
        auto initializer_4 = std::static_pointer_cast<initializer_t>(nodes[4]); // group_id 272
        return ast_by_id<555>::type_t::make(fully_specified_type_0, ast_token_1, array_specifier_2, ast_token_3, initializer_4);

      });
      break;
    }
    if (delegate.check_stack_item(0, 272) && delegate.check_stack_item(1, 42) && delegate.check_stack_item(2, 4) && delegate.check_stack_item(3, 252)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto fully_specified_type_0 = std::static_pointer_cast<fully_specified_type_t>(nodes[0]); // group_id 252
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 42
        auto initializer_3 = std::static_pointer_cast<initializer_t>(nodes[3]); // group_id 272
        return ast_by_id<548>::type_t::make(fully_specified_type_0, ast_token_1, ast_token_2, initializer_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 272) && delegate.check_stack_item(1, 42) && delegate.check_stack_item(2, 4) && delegate.check_stack_item(3, 252)) {
      delegate.reduce(4, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto fully_specified_type_0 = std::static_pointer_cast<fully_specified_type_t>(nodes[0]); // group_id 252
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 4
        auto ast_token_2 = std::static_pointer_cast<ast_token_t>(nodes[2]); // group_id 42
        auto initializer_3 = std::static_pointer_cast<initializer_t>(nodes[3]); // group_id 272
        return ast_by_id<549>::type_t::make(fully_specified_type_0, ast_token_1, ast_token_2, initializer_3);

      });
      break;
    }
    if (delegate.check_stack_item(0, 272) && delegate.check_stack_item(1, 40) && delegate.check_stack_item(2, 273)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto initializer_list_0 = std::static_pointer_cast<initializer_list_t>(nodes[0]); // group_id 273
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 40
        auto initializer_2 = std::static_pointer_cast<initializer_t>(nodes[2]); // group_id 272
        return ast_by_id<512>::type_t::make(initializer_list_0, ast_token_1, initializer_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 272)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto initializer_0 = std::static_pointer_cast<initializer_t>(nodes[0]); // group_id 272
        return ast_by_id<263>::type_t::make(initializer_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 274: {
    if (delegate.check_stack_item(0, 274)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto declaration_statement_0 = std::static_pointer_cast<declaration_statement_t>(nodes[0]); // group_id 274
        return ast_by_id<230>::type_t::make(declaration_statement_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 274)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto declaration_statement_0 = std::static_pointer_cast<declaration_statement_t>(nodes[0]); // group_id 274
        return ast_by_id<258>::type_t::make(declaration_statement_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 275: {
    if (delegate.check_stack_item(0, 275) && delegate.check_stack_item(1, 72) && delegate.check_stack_item(2, 275)) {
      delegate.reduce(3, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto statement_0 = std::static_pointer_cast<statement_t>(nodes[0]); // group_id 275
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 72
        auto statement_2 = std::static_pointer_cast<statement_t>(nodes[2]); // group_id 275
        return ast_by_id<534>::type_t::make(statement_0, ast_token_1, statement_2);

      });
      break;
    }
    if (delegate.check_stack_item(0, 275) && delegate.check_stack_item(1, 280)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto statement_list_0 = std::static_pointer_cast<statement_list_t>(nodes[0]); // group_id 280
        auto statement_1 = std::static_pointer_cast<statement_t>(nodes[1]); // group_id 275
        return ast_by_id<486>::type_t::make(statement_list_0, statement_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 275)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto statement_0 = std::static_pointer_cast<statement_t>(nodes[0]); // group_id 275
        return ast_by_id<239>::type_t::make(statement_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 275)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto statement_0 = std::static_pointer_cast<statement_t>(nodes[0]); // group_id 275
        return ast_by_id<241>::type_t::make(statement_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 276: {
    if (delegate.check_stack_item(0, 276)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto simple_statement_0 = std::static_pointer_cast<simple_statement_t>(nodes[0]); // group_id 276
        return ast_by_id<247>::type_t::make(simple_statement_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 276)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto simple_statement_0 = std::static_pointer_cast<simple_statement_t>(nodes[0]); // group_id 276
        return ast_by_id<259>::type_t::make(simple_statement_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 277: {
    if (delegate.check_stack_item(0, 277)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto compound_statement_0 = std::static_pointer_cast<compound_statement_t>(nodes[0]); // group_id 277
        return ast_by_id<260>::type_t::make(compound_statement_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 278: {
    if (delegate.check_stack_item(0, 278) && delegate.check_stack_item(1, 34) && delegate.check_stack_item(2, 291) && delegate.check_stack_item(3, 289) && delegate.check_stack_item(4, 33) && delegate.check_stack_item(5, 73)) {
      delegate.reduce(6, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 73
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 33
        auto for_init_statement_2 = std::static_pointer_cast<for_init_statement_t>(nodes[2]); // group_id 289
        auto for_rest_statement_3 = std::static_pointer_cast<for_rest_statement_t>(nodes[3]); // group_id 291
        auto ast_token_4 = std::static_pointer_cast<ast_token_t>(nodes[4]); // group_id 34
        auto statement_no_new_scope_5 = std::static_pointer_cast<statement_no_new_scope_t>(nodes[5]); // group_id 278
        return ast_by_id<556>::type_t::make(ast_token_0, ast_token_1, for_init_statement_2, for_rest_statement_3, ast_token_4, statement_no_new_scope_5);

      });
      break;
    }
    if (delegate.check_stack_item(0, 278) && delegate.check_stack_item(1, 34) && delegate.check_stack_item(2, 284) && delegate.check_stack_item(3, 33) && delegate.check_stack_item(4, 3)) {
      delegate.reduce(5, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 3
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 33
        auto condition_2 = std::static_pointer_cast<condition_t>(nodes[2]); // group_id 284
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 34
        auto statement_no_new_scope_4 = std::static_pointer_cast<statement_no_new_scope_t>(nodes[4]); // group_id 278
        return ast_by_id<553>::type_t::make(ast_token_0, ast_token_1, condition_2, ast_token_3, statement_no_new_scope_4);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 279: {
    if (delegate.check_stack_item(0, 279) && delegate.check_stack_item(1, 243)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_prototype_0 = std::static_pointer_cast<function_prototype_t>(nodes[0]); // group_id 243
        auto compound_statement_no_new_scope_1 = std::static_pointer_cast<compound_statement_no_new_scope_t>(nodes[1]); // group_id 279
        return ast_by_id<455>::type_t::make(function_prototype_0, compound_statement_no_new_scope_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 279)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto compound_statement_no_new_scope_0 = std::static_pointer_cast<compound_statement_no_new_scope_t>(nodes[0]); // group_id 279
        return ast_by_id<248>::type_t::make(compound_statement_no_new_scope_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 280: {
    if (delegate.check_stack_item(0, 280)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto statement_list_0 = std::static_pointer_cast<statement_list_t>(nodes[0]); // group_id 280
        return ast_by_id<233>::type_t::make(statement_list_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 281: {
    if (delegate.check_stack_item(0, 281)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto expression_statement_0 = std::static_pointer_cast<expression_statement_t>(nodes[0]); // group_id 281
        return ast_by_id<231>::type_t::make(expression_statement_0);

      });
      break;
    }
    if (delegate.check_stack_item(0, 281)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto expression_statement_0 = std::static_pointer_cast<expression_statement_t>(nodes[0]); // group_id 281
        return ast_by_id<257>::type_t::make(expression_statement_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 282: {
    if (delegate.check_stack_item(0, 282)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto selection_statement_0 = std::static_pointer_cast<selection_statement_t>(nodes[0]); // group_id 282
        return ast_by_id<255>::type_t::make(selection_statement_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 283: {
    if (delegate.check_stack_item(0, 283) && delegate.check_stack_item(1, 34) && delegate.check_stack_item(2, 239) && delegate.check_stack_item(3, 33) && delegate.check_stack_item(4, 74)) {
      delegate.reduce(5, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto ast_token_0 = std::static_pointer_cast<ast_token_t>(nodes[0]); // group_id 74
        auto ast_token_1 = std::static_pointer_cast<ast_token_t>(nodes[1]); // group_id 33
        auto expression_2 = std::static_pointer_cast<expression_t>(nodes[2]); // group_id 239
        auto ast_token_3 = std::static_pointer_cast<ast_token_t>(nodes[3]); // group_id 34
        auto selection_rest_statement_4 = std::static_pointer_cast<selection_rest_statement_t>(nodes[4]); // group_id 283
        return ast_by_id<550>::type_t::make(ast_token_0, ast_token_1, expression_2, ast_token_3, selection_rest_statement_4);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 284: {
    if (delegate.check_stack_item(0, 284)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto condition_0 = std::static_pointer_cast<condition_t>(nodes[0]); // group_id 284
        return ast_by_id<229>::type_t::make(condition_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 285: {
    if (delegate.check_stack_item(0, 285)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto switch_statement_0 = std::static_pointer_cast<switch_statement_t>(nodes[0]); // group_id 285
        return ast_by_id<254>::type_t::make(switch_statement_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 287: {
    if (delegate.check_stack_item(0, 287)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto case_label_0 = std::static_pointer_cast<case_label_t>(nodes[0]); // group_id 287
        return ast_by_id<252>::type_t::make(case_label_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 288: {
    if (delegate.check_stack_item(0, 288)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto iteration_statement_0 = std::static_pointer_cast<iteration_statement_t>(nodes[0]); // group_id 288
        return ast_by_id<251>::type_t::make(iteration_statement_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 292: {
    if (delegate.check_stack_item(0, 292)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto jump_statement_0 = std::static_pointer_cast<jump_statement_t>(nodes[0]); // group_id 292
        return ast_by_id<249>::type_t::make(jump_statement_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 294: {
    if (delegate.check_stack_item(0, 294) && delegate.check_stack_item(1, 293)) {
      delegate.reduce(2, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto translation_unit_0 = std::static_pointer_cast<translation_unit_t>(nodes[0]); // group_id 293
        auto external_declaration_1 = std::static_pointer_cast<external_declaration_t>(nodes[1]); // group_id 294
        return ast_by_id<459>::type_t::make(translation_unit_0, external_declaration_1);

      });
      break;
    }
    if (delegate.check_stack_item(0, 294)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto external_declaration_0 = std::static_pointer_cast<external_declaration_t>(nodes[0]); // group_id 294
        return ast_by_id<224>::type_t::make(external_declaration_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

  case 295: {
    if (delegate.check_stack_item(0, 295)) {
      delegate.reduce(1, [](std::vector<std::shared_ptr<ast_t>> nodes) {

        auto function_definition_0 = std::static_pointer_cast<function_definition_t>(nodes[0]); // group_id 295
        return ast_by_id<223>::type_t::make(function_definition_0);

      });
      break;
    }
    // if can't reduce, shift()
    delegate.shift();
    break;
  }

    default: {
      delegate.shift();
      break;
    }
  }
}

}   // ast

}   // gliss
