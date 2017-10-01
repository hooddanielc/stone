#include <iostream>
#include <lick/lick.h>
#include <gliss/parser.h>
#include <gliss/pretty-print.h>

using namespace gliss;

FIXTURE(simple_program) {
  auto output = parser_t::parse_string(R"(

    void main(void) {
      mat2x2 a = mat2( vec2( 1.0, 0.0 ), vec2( 0.0, 1.0 ) );
    }
  )");

  EXPECT_EQ(output->get_name(), "translation_unit");
}
