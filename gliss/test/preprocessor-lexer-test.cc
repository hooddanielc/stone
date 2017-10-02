#include <iostream>
#include <lick/lick.h>
#include <gliss/preprocessor.h>

using namespace gliss;

FIXTURE(multiline_comment) {
  auto result = preprocessor_lexer_t::lex(R"(
    // just some code
    int a;

    #define ADD(a, b) a + b

    void main(void) {
      int a = ADD(1,2);
    }
  )");

  EXPECT_TRUE(result.size() > size_t(0));
}
