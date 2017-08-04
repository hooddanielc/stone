#include <iostream>
#include <lick/lick.h>
#include <gliss/lexer.h>

FIXTURE(test) {
  auto lexer = gliss::lexer_t::lex(R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;

    void main() {
      gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
  )");
}