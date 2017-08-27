#pragma once

#include <memory>

#include "token.h"
#include "cursor.h"
#include "ast.h"
#include "ast-nodes/all.h"
#include "symbols.h"
#include "ast-reducer.h"

namespace gliss {

class parser_t final {

public:

  static parser_t make(const std::vector<token_t> &tokens) {
    auto cursor = cursor_t(&tokens[0], &tokens[tokens.size() - 1]);
    parser_t parser(cursor);
    return parser;
  }

  /* Convert an array of tokens into a syntax tree. */
  static std::vector<std::shared_ptr<ast::ast_t>> parse(const std::vector<token_t> &tokens) {
    cursor_t cursor(&tokens[0], &tokens[tokens.size() - 1]);
    return parser_t(cursor).parse();
  }

  /* Check nth index from end of stack for match */
  bool check_stack_item(int n, int kind) {
    if (int(stack.size()) < n + 1) {
      return false;
    }
    return stack[stack.size() - n - 1]->get_id() == kind;
  }

  /* Try reduce */
  bool try_reduce() {
    ast::try_reduce(*this);
    return go;
  }

  /* Shift */
  bool shift() {
    auto token = cursor.shift();

    if (token->get_kind() == symbol_t::end) {
      // done parsing check results
      go = false;
      return false;
    }

    stack.push_back(ast::ast_token_t::make(*token));
    return true;
  }

  /* Reduce n items */
  template <typename reducer_func_t>
  void reduce(int n, const reducer_func_t &reducer) {
    std::vector<std::shared_ptr<ast::ast_t>> list;
    for (int i = 0; i < n; ++i) {
      auto temp = stack.back();
      list.insert(list.begin(), temp);
      stack.pop_back();
    }
    stack.push_back(reducer(list));
  }

  /* Get the last id in the stack */
  int back() {
    if (stack.size() == 0) {
      throw std::runtime_error("can't get last id in empty stack");
    }
    return stack.back()->get_id();
  }

  void print_stack() {
    for (auto ast: stack) {
      std::cout << ast << std::endl;
    }
  }

  std::vector<std::shared_ptr<ast::ast_t>> stack;

private:

  bool go;
  
  cursor_t cursor;

  parser_t(const cursor_t &cursor_) : go(true), cursor(cursor_)  {
    shift();
  }

  std::vector<std::shared_ptr<ast::ast_t>> parse() {
    do {
      try_reduce();
    } while(go);

    return stack;
  }

};  // parser_t

}   // gliss
