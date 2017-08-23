#pragma once

#include <memory>

#include "token.h"
#include "cursor.h"
#include "ast.h"
#include "ast-nodes/all.h"

namespace gliss {

class parser_t final {

public:

  cursor_t get_cursor() {
    return start_cursor;
  }

  static parser_t make(const std::vector<token_t> &tokens) {
    return cursor_t(&tokens[0], &tokens[tokens.size() - 1]);
  }

  /* Convert an array of tokens into a syntax tree. */
  static std::unique_ptr<ast::ast_t> parse(const std::vector<token_t> &tokens) {
    cursor_t cursor(&tokens[0], &tokens[tokens.size() - 1]);
    return parser_t(cursor).parse();
  }

  /**
   * #### function_call:
   *  [function_call_or_method](#function_call_or_method)
   */
  std::unique_ptr<ast::function_call_t> match_function_call(cursor_t) {
    return nullptr;
  }

  /**
   * #### function_call_or_method:
   *   [function_call_generic](#function_call_generic)
   */
  std::unique_ptr<ast::function_call_or_method_t> match_function_call_or_method(cursor_t) {
    return nullptr;
  }

  /**
   * #### function_call_generic:
   *   [function_call_header_no_parameters](#function_call_header_no_parameters) _RIGHT_PAREN_
   *   [function_call_header_with_parameters](#function_call_header_with_parameters) _RIGHT_PAREN_
   */
  std::unique_ptr<ast::function_call_generic_t> match_function_call_generic(cursor_t) {
    return nullptr;
  }

  /**
   * #### function_call_header_no_parameters:
   *  [function_call_header](#function_call_header)
   *  [function_call_header](#function_call_header) _VOID_
   */

  /**
   * #### function_call_header_with_parameters:
   *  [function_call_header](#function_call_header) [assignment_expression](#assignment_expression)
   *  [function_call_header_with_parameters](#function_call_header_with_parameters) _COMMA_ [assignment_expression](#assignment_expression)
   */

  /**
   * #### function_call_header:
   *   [function_identifier](#function_identifier) _LEFT_PAREN_
   */

  /**
   * #### function_identifier:
   *  [postfix_expression](#postfix_expression)
   *  [type_specifier](#type_specifier)
  */

  /**
   * #### unary_expression:
   *  [postfix_expression](#postfix_expression)
   *  [unary_operator](#unary_operator) [unary_expression](#unary_expression)
   *  _DEC_OP_ [unary_expression](#unary_expression)
   *  _INC_OP_ [unary_expression](#unary_expression)
   */

  /**
   * #### multiplicative_expression:
   *  [multiplicative_expression](#multiplicative_expression) _PERCENT_ [unary_expression](#unary_expression)
   *  [multiplicative_expression](#multiplicative_expression) _SLASH_ [unary_expression](#unary_expression)
   *  [multiplicative_expression](#multiplicative_expression) _STAR_ [unary_expression](#unary_expression)
   *  [unary_expression](#unary_expression)
   */

  /**
   * #### additive_expression:
   *  [additive_expression](#additive_expression) _DASH_ [multiplicative_expression](#multiplicative_expression)
   *  [additive_expression](#additive_expression) _PLUS_ [multiplicative_expression](#multiplicative_expression)
   *  [multiplicative_expression](#multiplicative_expression)
   */

  /**
   * #### postfix_expression:
   *  [function_call](#function_call)
   *  [postfix_expression](#postfix_expression) _DEC_OP_
   *  [postfix_expression](#postfix_expression) _DOT_ _FIELD_SELECTION_
   *  [postfix_expression](#postfix_expression) _INC_OP_
   *  [postfix_expression](#postfix_expression) _LEFT_BRACKET_ [integer_expression](#integer_expression) _RIGHT_BRACKET_
   *  [primary_expression](#primary_expression)
   */
  std::unique_ptr<ast::postfix_expression_t> match_postfix_expression(cursor_t cursor) {
    try {
      auto match = match_function_call(cursor);
      return ast::postfix_expression_function_call_t::make(std::move(match));
    } catch (const std::exception &) {
      try {
        auto match_nested_postfix = match_postfix_expression(cursor);
        auto match_opt1 = cursor.match_any({
          token_t::dec_op,
          token_t::dot,
          token_t::inc_op,
          token_t::left_bracket
        });

        if (match_opt1->get_kind() == token_t::dec_op)
          return ast::postfix_expression_postfix_expression_dec_op_t::make(
            std::move(match_nested_postfix),
            match_opt1
          );

        if (match_opt1->get_kind() == token_t::inc_op)
          return ast::postfix_expression_postfix_expression_inc_op_t::make(
            std::move(match_nested_postfix),
            match_opt1
          );

        if (match_opt1->get_kind() == token_t::dot) {
          auto field_selection = cursor.match(token_t::field_selection);
          return ast::postfix_expression_postfix_expression_dot_field_selection_t::make(
            std::move(match_nested_postfix),
            match_opt1,
            field_selection
          );
        }

        auto integer = match_integer_expression(cursor);
        auto right_bracket = cursor.match(token_t::right_bracket);
        return ast::postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t::make(
          std::move(match_nested_postfix),
          match_opt1,
          std::move(integer),
          right_bracket
        );
      } catch (const std::exception &e) {
        auto primary = match_primary_expression(cursor);
        return ast::postfix_expression_primary_expression_t::make(std::move(primary));
      }
    }

    return nullptr;
  }

  /**
   * #### integer_expression:
   *  [expression](#expression)
   */
  std::unique_ptr<ast::integer_expression_t> match_integer_expression(cursor_t) {
    return nullptr;
  }

  /**
   * #### unary_operator:
   *   _BANG_
   *   _DASH_
   *   _PLUS_
   *   _TILDE_
   */
  std::unique_ptr<ast::unary_operator_t> match_unary_operator(cursor_t cursor) {
    auto match = cursor.match_any({
      token_t::bang,
      token_t::dash,
      token_t::plus,
      token_t::tilde
    });

    if (match->get_kind() == token_t::bang)
      return ast::unary_operator_bang_t::make(match);
    if (match->get_kind() == token_t::dash)
      return ast::unary_operator_dash_t::make(match);
    if (match->get_kind() == token_t::plus)
      return ast::unary_operator_plus_t::make(match);
    
    return ast::unary_operator_tilde_t::make(match);
  }

  /**
  * #### expression:
  *   [assignment_expression](#assignment_expression)
  *   [expression](#expression) _COMMA_ [assignment_expression](#assignment_expression)
  */
  std::unique_ptr<ast::expression_t> match_expression(cursor_t) {
    return nullptr;
  }

  /**
   *#### primary_expression:
   *  [variable_identifier](#variable_identifier)
   *  _BOOLCONSTANT_
   *  _DOUBLECONSTANT_
   *  _FLOATCONSTANT_
   *  _INTCONSTANT_
   *  _LEFT_PAREN_ [expression](#expression) _RIGHT_PAREN_
   *  _UINTCONSTANT_
   */
  std::unique_ptr<ast::primary_expression_t> match_primary_expression(cursor_t cursor) {
    try {
      auto match = match_variable_identifier(cursor);
      return ast::primary_expression_variable_identifier_t::make(std::move(match));
    } catch (const std::exception &) {
      auto match1 = cursor.match_any({
        token_t::boolconstant,
        token_t::doubleconstant,
        token_t::floatconstant,
        token_t::intconstant,
        token_t::left_paren,
        token_t::uintconstant
      });

      if (match1->get_kind() == token_t::boolconstant)
        return ast::primary_expression_boolconstant_t::make(match1);
      if (match1->get_kind() == token_t::doubleconstant)
        return ast::primary_expression_doubleconstant_t::make(match1);
      if (match1->get_kind() == token_t::floatconstant)
        return ast::primary_expression_floatconstant_t::make(match1);
      if (match1->get_kind() == token_t::intconstant)
        return ast::primary_expression_intconstant_t::make(match1);
      if (match1->get_kind() == token_t::uintconstant)
        return ast::primary_expression_uintconstant_t::make(match1);

      auto match2 = match_expression(cursor);
      auto match3 = cursor.match(token_t::right_paren);
      return ast::primary_expression_left_paren_expression_right_paren_t::make(
        match1, std::move(match2), match3
      );
    }
  }

  /**
   * #### variable_identifier:
   *  _IDENTIFIER_
   */
  std::unique_ptr<ast::variable_identifier_t> match_variable_identifier(cursor_t cursor) {
    auto match = cursor.match(token_t::identifier);
    return ast::variable_identifier_identifier_t::make(match);
  }

  /*
   * #### assignment_operator:
   *  _ADD_ASSIGN_
   *  _AND_ASSIGN_
   *  _DIV_ASSIGN_
   *  _EQUAL_
   *  _LEFT_ASSIGN_
   *  _MOD_ASSIGN_
   *  _MUL_ASSIGN_
   *  _OR_ASSIGN_
   *  _RIGHT_ASSIGN_
   *  _SUB_ASSIGN_
   *  _XOR_ASSIGN_
   */
  std::unique_ptr<ast::assignment_operator_t> match_assignment_operator(cursor_t cursor) {
    auto match = cursor.match_any({
      token_t::equal,
      token_t::mul_assign,
      token_t::div_assign,
      token_t::mod_assign,
      token_t::add_assign,
      token_t::sub_assign,
      token_t::left_assign,
      token_t::right_assign,
      token_t::and_assign,
      token_t::xor_assign,
      token_t::or_assign
    });
    if (match->get_kind() == token_t::mul_assign)
      return ast::assignment_operator_mul_assign_t::make(match);
    if (match->get_kind() == token_t::equal)
      return ast::assignment_operator_equal_t::make(match);
    if (match->get_kind() == token_t::div_assign)
      return ast::assignment_operator_div_assign_t::make(match);
    if (match->get_kind() == token_t::mod_assign)
      return ast::assignment_operator_mod_assign_t::make(match);
    if (match->get_kind() == token_t::add_assign)
      return ast::assignment_operator_add_assign_t::make(match);
    if (match->get_kind() == token_t::sub_assign)
      return ast::assignment_operator_sub_assign_t::make(match);
    if (match->get_kind() == token_t::left_assign)
      return ast::assignment_operator_left_assign_t::make(match);
    if (match->get_kind() == token_t::right_assign)
      return ast::assignment_operator_right_assign_t::make(match);
    if (match->get_kind() == token_t::and_assign)
      return ast::assignment_operator_and_assign_t::make(match);
    if (match->get_kind() == token_t::xor_assign)
      return ast::assignment_operator_xor_assign_t::make(match);

    return ast::assignment_operator_or_assign_t::make(match);
  }

private:

  cursor_t start_cursor;

  parser_t(const cursor_t &cursor_) : start_cursor(cursor_) {}

  std::unique_ptr<ast::ast_t> parse() {
    auto ptr = std::make_unique<ast::nothing_t>();
    return std::move(ptr);
  }

};  // parser_t

}   // gliss
