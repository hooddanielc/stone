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

  EXPECT_EQ(tokens[0]->get_kind(), token_t::VEC4);
  EXPECT_EQ(tokens[1]->get_kind(), token_t::BOOL);
  EXPECT_EQ(tokens[2]->get_kind(), token_t::IDENTIFIER);
  EXPECT_EQ(tokens[3]->get_kind(), token_t::IDENTIFIER);
}

FIXTURE(equality_operator) {
  auto tokens = lexer_t::lex(R"(
    vec4
    ab==cd123
    varcolor == varcolor
  )");

  EXPECT_EQ(tokens[0]->get_kind(), token_t::VEC4);
  EXPECT_EQ(tokens[1]->get_kind(), token_t::IDENTIFIER);
  EXPECT_EQ(tokens[2]->get_kind(), token_t::EQ_OP);
  EXPECT_EQ(tokens[3]->get_kind(), token_t::IDENTIFIER);
  EXPECT_EQ(tokens[4]->get_kind(), token_t::IDENTIFIER);
  EXPECT_EQ(tokens[5]->get_kind(), token_t::EQ_OP);
  EXPECT_EQ(tokens[6]->get_kind(), token_t::IDENTIFIER);
}

FIXTURE(assignment) {
  auto tokens = lexer_t::lex(R"(
    vec4 something = varcolor;
  )");

  EXPECT_EQ(tokens[0]->get_kind(), token_t::VEC4);
  EXPECT_EQ(tokens[1]->get_kind(), token_t::IDENTIFIER);
  EXPECT_EQ(tokens[2]->get_kind(), token_t::EQUAL);
  EXPECT_EQ(tokens[3]->get_kind(), token_t::IDENTIFIER);
  EXPECT_EQ(tokens[4]->get_kind(), token_t::SEMICOLON);
}

void assert_assigned_kind(const std::string &str, token_t::kind_t kind) {
  std::stringstream ss;
  ss << "a = " << str << ";";
  auto tokens = lexer_t::lex(ss.str().c_str());
  EXPECT_EQ(tokens[2]->get_kind(), kind);
  EXPECT_EQ(tokens[2]->get_text(), str);
}

FIXTURE(numbers) {
  assert_assigned_kind("123", token_t::INTCONSTANT);
  assert_assigned_kind("01111", token_t::INTCONSTANT);
  assert_assigned_kind("0xffff", token_t::INTCONSTANT);
  assert_assigned_kind("0xFFAA", token_t::INTCONSTANT);
  assert_assigned_kind("0Xffff", token_t::INTCONSTANT);
  assert_assigned_kind("0XFFAA", token_t::INTCONSTANT);
  assert_assigned_kind("0.01", token_t::FLOATCONSTANT);
  assert_assigned_kind("12.01", token_t::FLOATCONSTANT);
  assert_assigned_kind(".01", token_t::FLOATCONSTANT);
  assert_assigned_kind("1.0", token_t::FLOATCONSTANT);
  assert_assigned_kind("2.", token_t::FLOATCONSTANT);
  assert_assigned_kind("2.e-2", token_t::FLOATCONSTANT);
  assert_assigned_kind("2.2e-2", token_t::FLOATCONSTANT);
  assert_assigned_kind("2e-2", token_t::FLOATCONSTANT);
  assert_assigned_kind("2.e+2", token_t::FLOATCONSTANT);
  assert_assigned_kind("2.2e+2", token_t::FLOATCONSTANT);
  assert_assigned_kind("2e+2", token_t::FLOATCONSTANT);
  assert_assigned_kind("2e2", token_t::FLOATCONSTANT);
  assert_assigned_kind("12.01l", token_t::FLOATCONSTANT);
  assert_assigned_kind("12.01f", token_t::FLOATCONSTANT);
  assert_assigned_kind("12.01lf", token_t::DOUBLECONSTANT);
}
