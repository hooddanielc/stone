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
    cool
  )");

  EXPECT_EQ(tokens[0].get_kind(), token_t::vec4);
  EXPECT_EQ(tokens[1].get_kind(), token_t::bool_);
  EXPECT_EQ(tokens[2].get_kind(), token_t::identifier);
  EXPECT_EQ(tokens[3].get_kind(), token_t::identifier);
}

// FIXTURE(test) {

//   auto lexer = gliss::lexer_t::lex(R"(
//     #version 330 core
//     layout (location = 0) in vec3 aPos;

//     void main() {
//       gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
//     }
//   )");
// }