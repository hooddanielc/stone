#include <lick/lick.h>
#include <gliss/parser.h>

using namespace gliss;

FIXTURE(does_it_compile) {
  auto output = parser_t::parse_string(R"(
    struct Light {
      vec3 eyePosOrDir;
      bool isDirectional;
      vec3 intensity;
      float attenuation;
    } f;
    layout (location = 0) in vec3 a;
    layout (location = 1) in vec3 b;

    in vec4 c;
    in vec3 d;
    out vec3 e;

    int g = 1;

    int h(int i) {
      int j = 3;
      {
        int k = k + 3; // 2nd k is parameter, initializing nested first k
        int l = k; // use of new k, which is hiding the parameter
      }
    }

    void main() {
      Color = color;
      for ( /* nested scope begins here */ int m = 0; m < 10; m++) {
        int n; // redeclaration error
      }
      int o = 17;
      do {
        int p = 4; // okay, in nested scope

        while (i = 2) {
          i -= 4;
        }

      } while (i == 0); // i is 17, scoped outside the do-while body

      switch (i) {
        case 0: break;
        case 1: break;
        case 2: a = 3;
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
        case 2: int q = 3; break;
        case 4: int r = 2; break;
        default: int s = 4;
      }

      if (i == 3) {
        int t = 3;
      } else if (i == 4) {
        int u = 3;
        int v;
      }

      vec4 w;
      int x, y, z;

      gl_Position = projMatrix * viewMatrix * position;
    }
  )");

  auto json = output->to_json();
  std::cout << json << std::endl;
}
