#pragma once

#include <memory>

#include "token.h"
#include "cursor.h"
#include "ast.h"
#include "ast-nodes/all.h"
#include "symbols.h"

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

  /* Check if the pattern matches */
  bool check_stack_item(int n, symbol_t kind) {
    // todo
    return false;
  }

  /* Shift */
  bool shift() {
    // todo
    return false;
  }

  /* Reduce n items */
  template <typename reducer_func_t>
  void reduce(int n, const reducer_func_t &reducer) {
    // todo
  }

  /* Get the last id in the stack */
  int end() {
    // todo
    return -1;
  }

private:

  cursor_t start_cursor;

  parser_t(const cursor_t &cursor_) : start_cursor(cursor_) {}

  std::vector<std::shared_ptr<ast::ast_t>> stack;

  std::unique_ptr<ast::ast_t> parse() {
    auto ptr = std::make_unique<ast::nothing_t>();
    return std::move(ptr);
  }

};  // parser_t

}   // gliss
