#pragma once

#include <memory>

#include "token.h"
#include "cursor.h"
#include "ast.h"
#include "ast-nodes/all.h"

namespace gliss {

class parser_t final {

public:

  static parser_t make(const std::vector<token_t> &tokens) {
    return cursor_t(&tokens[0], &tokens[tokens.size() - 1]);
  }

  /* Convert an array of tokens into a syntax tree. */
  static std::unique_ptr<ast::ast_t> parse(const std::vector<token_t> &tokens) {
    cursor_t cursor(&tokens[0], &tokens[tokens.size() - 1]);
    return parser_t(cursor).parse();
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
  std::unique_ptr<ast::ast_t> match_assignment_operator() {
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
    switch (match->get_kind()) {
      case token_t::mul_assign:
        return std::make_unique<ast::assignment_operator_mul_assign_t>(std::make_unique<token_t>(*match));
      case token_t::equal:
        return std::make_unique<ast::assignment_operator_equal_t>(std::make_unique<token_t>(*match));
      case token_t::div_assign:
        return std::make_unique<ast::assignment_operator_div_assign_t>(std::make_unique<token_t>(*match));
      case token_t::mod_assign:
        return std::make_unique<ast::assignment_operator_mod_assign_t>(std::make_unique<token_t>(*match));
      case token_t::add_assign:
        return std::make_unique<ast::assignment_operator_add_assign_t>(std::make_unique<token_t>(*match));
      case token_t::sub_assign:
        return std::make_unique<ast::assignment_operator_sub_assign_t>(std::make_unique<token_t>(*match));
      case token_t::left_assign:
        return std::make_unique<ast::assignment_operator_left_assign_t>(std::make_unique<token_t>(*match));
      case token_t::right_assign:
        return std::make_unique<ast::assignment_operator_right_assign_t>(std::make_unique<token_t>(*match));
      case token_t::and_assign:
        return std::make_unique<ast::assignment_operator_and_assign_t>(std::make_unique<token_t>(*match));
      case token_t::xor_assign:
        return std::make_unique<ast::assignment_operator_xor_assign_t>(std::make_unique<token_t>(*match));
      case token_t::or_assign:
        return std::make_unique<ast::assignment_operator_or_assign_t>(std::make_unique<token_t>(*match));
    }
  }

private:

  cursor_t cursor;

  parser_t(const cursor_t &cursor_) : cursor(cursor_) {}

  std::unique_ptr<ast::ast_t> parse() {
    auto ptr = std::make_unique<ast::nothing_t>();
    return std::move(ptr);
  }

};  // parser_t

}   // gliss
