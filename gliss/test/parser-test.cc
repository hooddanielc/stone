#include <iostream>
#include <lick/lick.h>
#include <gliss/parser.h>
#include <gliss/pretty-print.h>

using namespace gliss;

FIXTURE(simple_program) {
  auto output = parser_t::parse_string(R"(
    uniform mat4 viewMatrix, projMatrix;

    in vec4 position;
    in vec3 color;
    out vec3 Color;

    struct Light {
      vec3 eyePosOrDir;
      bool isDirectional;
      vec3 intensity;
      float attenuation;
    } variableName;

    void main() {
      Color = color;
      gl_Position = projMatrix * viewMatrix * position ;
    }
  )");

  EXPECT_EQ(output->get_name(), "translation_unit");
}
