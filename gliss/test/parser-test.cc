#include <iostream>
#include <lick/lick.h>
#include <gliss/lexer.h>
#include <gliss/parser.h>
#include <gliss/pretty-print-ast.h>

using namespace gliss;

FIXTURE(shifting) {
  auto tokens = lexer_t::lex(R"(
    =
  )");

  auto parser = parser_t::make(tokens);
  EXPECT_TRUE(parser.check_stack_item(0, symbol_t::equal));
  EXPECT_FALSE(parser.shift());
}

FIXTURE(reduce_variable_identifier) {
  auto tokens = lexer_t::lex(R"(
    blah = 3;
  )");

  auto stack = parser_t::parse(tokens);
  EXPECT_EQ(int(stack.size()), 4);
}
