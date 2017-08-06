#include <iostream>
#include <lick/lick.h>
#include <gliss/lexer.h>

using namespace gliss;

FIXTURE(multiline_comment) {
  lexer_t::lex(R"(
    /**
     * this is ignored
     */
  )");
}

FIXTURE(single_line_comment) {
  lexer_t::lex(R"(
    // this is a comment
  )");
}

FIXTURE(comments_and_names) {
  auto tokens = lexer_t::lex(R"(
    vec4 // pretty cool thing
    bool /* well not that i would comment like
            this, but i've seen it */
    varcolor
    cool123
  )");

  EXPECT_EQ(tokens[0].get_kind(), token_t::vec4);
  EXPECT_EQ(tokens[1].get_kind(), token_t::bool_);
  EXPECT_EQ(tokens[2].get_kind(), token_t::identifier);
  EXPECT_EQ(tokens[3].get_kind(), token_t::identifier);
}

FIXTURE(equality_operator) {
  auto tokens = lexer_t::lex(R"(
    vec4
    ab==cd123
    varcolor == varcolor
  )");

  EXPECT_EQ(tokens[0].get_kind(), token_t::vec4);
  EXPECT_EQ(tokens[1].get_kind(), token_t::identifier);
  EXPECT_EQ(tokens[2].get_kind(), token_t::eq_op);
  EXPECT_EQ(tokens[3].get_kind(), token_t::identifier);
  EXPECT_EQ(tokens[4].get_kind(), token_t::identifier);
  EXPECT_EQ(tokens[5].get_kind(), token_t::eq_op);
  EXPECT_EQ(tokens[6].get_kind(), token_t::identifier);
}

FIXTURE(assignment) {
  auto tokens = lexer_t::lex(R"(
    vec4 something = varcolor;
  )");

  EXPECT_EQ(tokens[0].get_kind(), token_t::vec4);
  EXPECT_EQ(tokens[1].get_kind(), token_t::identifier);
  EXPECT_EQ(tokens[2].get_kind(), token_t::equal);
  EXPECT_EQ(tokens[3].get_kind(), token_t::identifier);
  EXPECT_EQ(tokens[4].get_kind(), token_t::semicolon);
}
