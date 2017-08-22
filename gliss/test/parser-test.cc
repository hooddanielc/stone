#include <iostream>
#include <lick/lick.h>
#include <gliss/lexer.h>
#include <gliss/parser.h>

using namespace gliss;

FIXTURE(auto_match) {
  auto tokens = lexer_t::lex(R"(
    =
  )");

  lexer_t::print_tokens(tokens);
  auto parser = parser_t::make(tokens);
  auto ast = parser.match_assignment_operator();
  // a dragon does not slay itself
}
