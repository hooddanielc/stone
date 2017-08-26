#include <iostream>
#include <lick/lick.h>
#include <gliss/lexer.h>
#include <gliss/parser.h>
#include <gliss/pretty-print-ast.h>

using namespace gliss;

FIXTURE(assignment_operator_test) {
  auto tokens = lexer_t::lex(R"(
    =
  )");

  auto parser = parser_t::make(tokens);
}
