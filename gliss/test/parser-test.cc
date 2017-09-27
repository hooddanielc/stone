#include <iostream>
#include <lick/lick.h>
#include <gliss/parser.h>

using namespace gliss;

FIXTURE(simple_program) {
  auto output = parser_t::parse_string(R"(
    uniform mat4 viewMatrix, projMatrix;

    in vec4 position;
    in vec3 color;

    out vec3 Color;

    void main() {
      Color = color;
      gl_Position = projMatrix * viewMatrix * position ;
    }
  )");

  EXPECT_EQ(output->get_name(), "translation_unit");
}
