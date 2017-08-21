#include <iostream>
#include <lick/lick.h>
#include <gliss/lexer.h>
#include <gliss/parser.h>

using namespace gliss;
using namespace gliss::ast;

FIXTURE(auto_match) {
  auto tokens = lexer_t::lex(R"(
    =
  )");

  lexer_t::print_tokens(tokens);
  auto ast = parser_t::make(tokens);
  ast.auto_match<nothing_t>();
}
