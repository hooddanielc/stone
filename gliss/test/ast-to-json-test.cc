#include <lick/lick.h>
#include <gliss/parser.h>

using namespace gliss;

FIXTURE(does_it_compile) {
  auto output = parser_t::parse_string(R"(
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aNormal;

    void main() {
      if (3 == 3) {
        int a = 3;
      }
      gl_Position = projMatrix * viewMatrix * position;
    }
  )");

  auto json = output->to_json();
  std::cout << json << std::endl;
}
