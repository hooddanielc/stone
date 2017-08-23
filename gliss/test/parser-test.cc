#include <iostream>
#include <lick/lick.h>
#include <gliss/lexer.h>
#include <gliss/parser.h>
#include <gliss/pretty-print-ast.h>

using namespace gliss;

FIXTURE(assignment_operator) {
  auto tokens = lexer_t::lex(R"(
    =
  )");

  auto parser = parser_t::make(tokens);
  parser.match_assignment_operator(parser.get_cursor());
  // a dragon does not slay itself
}

FIXTURE(variable_identifier) {
  auto tokens = lexer_t::lex(R"(
    asdf = 3;
  )");

  auto parser = parser_t::make(tokens);
  parser.match_variable_identifier(parser.get_cursor());
  // a dragon does not slay itself
}

FIXTURE(primary_expression) {
  auto t1 = lexer_t::lex("31");
  auto p1 = parser_t::make(t1);
  p1.match_primary_expression(p1.get_cursor());
  auto t2 = lexer_t::lex("31.54");
  auto p2 = parser_t::make(t2);
  p2.match_primary_expression(p2.get_cursor());
  auto t3 = lexer_t::lex("0xffff");
  auto p3 = parser_t::make(t3);
  p3.match_primary_expression(p3.get_cursor());
  
  // a dragon does not slay itself
}
