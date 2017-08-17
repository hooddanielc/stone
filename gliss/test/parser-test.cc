#include <iostream>
#include <lick/lick.h>
#include <gliss/lexer.h>
#include <gliss/parser.h>

using namespace gliss;

FIXTURE(constructs) {
  auto tokens = lexer_t::lex(R"(
    in vec3 vertex_position;

    void main() {
      gl_Position = vec4(vertex_position, 1.0);
    }
  )");
}
