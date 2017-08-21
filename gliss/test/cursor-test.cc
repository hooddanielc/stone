#include <iostream>
#include <lick/lick.h>
#include <gliss/cursor.h>
#include <gliss/lexer.h>

using namespace gliss;

FIXTURE(increment) {
  auto tokens = lexer_t::lex(R"(
    layout(location = 2) in vec3 values[4];
  )");
  cursor_t cursor(&tokens[0], &tokens[tokens.size() - 1]);
  for (size_t i = 0; i < tokens.size(); ++i) {
    EXPECT_EQ(cursor->get_kind(), tokens[i].get_kind());
    ++cursor;
  }
}

FIXTURE(matching) {
  auto tokens = lexer_t::lex(R"(
    layout(location = 2) in vec3 values[4];
  )");
  cursor_t cursor(&tokens[0], &tokens[tokens.size() - 1]);
  EXPECT_FALSE(cursor.try_match(token_t::equal));
  EXPECT_TRUE(cursor.try_match(token_t::layout));
  EXPECT_TRUE(cursor.try_match(token_t::left_paren));
  EXPECT_FALSE(cursor.try_match(token_t::left_paren));
  auto catched = false;
  try {
    cursor.match(token_t::left_paren);
  } catch (const std::exception &) {
    catched = true;
  }
  EXPECT_TRUE(catched);
  EXPECT_EQ(cursor.match(token_t::identifier)->get_kind(), token_t::identifier);
  EXPECT_TRUE(cursor.try_match_any({
    token_t::equal,
    token_t::intconstant,
    token_t::right_paren
  }));
  EXPECT_TRUE(cursor.match_any({
    token_t::equal,
    token_t::intconstant,
    token_t::right_paren
  }));
  EXPECT_TRUE(cursor.match_any({
    token_t::equal,
    token_t::intconstant,
    token_t::right_paren
  }));
  catched = false;
  try {
    EXPECT_TRUE(cursor.match_any({
      token_t::equal,
      token_t::intconstant,
      token_t::right_paren
    }));
  } catch (const std::exception &e) {
    catched = true;
  }
  EXPECT_TRUE(catched);
  EXPECT_FALSE(cursor.try_match_any({
    token_t::equal,
    token_t::intconstant,
    token_t::right_paren
  }));
  EXPECT_TRUE(cursor.try_match_any({
    token_t::in,
    token_t::vec3,
    token_t::identifier
  }));
  EXPECT_TRUE(cursor.try_match_any({
    token_t::in,
    token_t::vec3,
    token_t::identifier
  }));
  EXPECT_TRUE(cursor.try_match_any({
    token_t::in,
    token_t::vec3,
    token_t::identifier
  }));
  EXPECT_TRUE(cursor.match(token_t::left_bracket));
  EXPECT_TRUE(cursor.match(token_t::intconstant));
  EXPECT_TRUE(cursor.match(token_t::right_bracket));
  EXPECT_TRUE(cursor.match(token_t::semicolon));
  EXPECT_TRUE(cursor.match(token_t::end));
  EXPECT_TRUE(cursor.match(token_t::end));
  EXPECT_TRUE(cursor.match(token_t::end));
  EXPECT_FALSE(cursor.try_match(token_t::identifier));
}

FIXTURE(copy) {
  auto tokens = lexer_t::lex(R"(
    layout(location = 2) in vec3 values[4];
  )");
  cursor_t cursor(&tokens[0], &tokens[tokens.size() - 1]);
  cursor.match(token_t::layout);
  auto another_cursor = cursor;
  another_cursor.match(token_t::left_paren);
  cursor.match(token_t::left_paren);
}
