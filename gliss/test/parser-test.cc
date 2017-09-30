#include <iostream>
#include <lick/lick.h>
#include <gliss/parser.h>
#include <gliss/pretty-print.h>

using namespace gliss;

FIXTURE(simple_program) {
  auto output = parser_t::parse_string(R"(
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aNormal;

    in vec4 position;
    in vec3 color;
    out vec3 Color;

    struct Light {
      vec3 eyePosOrDir;
      bool isDirectional;
      vec3 intensity;
      float attenuation;
    } variableName;

    int ok = 1;

    int f(int k) {
      int y = 3;
      {
        int k = k + 3; // 2nd k is parameter, initializing nested first k
        int m = k; // use of new k, which is hiding the parameter
      }
    }

    void main() {
      Color = color;
      for ( /* nested scope begins here */ int i = 0; i < 10; i++) {
        int i; // redeclaration error
      }
      int i = 17;
      do {
        int i = 4; // okay, in nested scope

        while (i = 2) {
          i -= 4;
        }

      } while (i == 0); // i is 17, scoped outside the do-while body

      switch (i) {
        case 0: break;
        case 1: break;
        case 2: y = 3;
        default: m = 3;
      }

      while(i = 0) {
        a += 2;

        if (i == 2) {
          a += 3;

          if (i = 2) {
            a += 4;
          } else {
            a += 2;
          }
        }
      }

      switch(i) {
        case 1: break;
        case 2: int y = 3; break;
        case 4: int y = 2; break;
        default: int y = 4;
      }

      if (i == 3) {
        int b = 3;
      } else if (i == 4) {
        int a = 3;
      }

      gl_Position = projMatrix * viewMatrix * position;
    }
  )");

  // std::cout << output.get() << std::endl;

  EXPECT_EQ(output->get_name(), "translation_unit");
}
