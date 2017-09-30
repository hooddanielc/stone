#include <lick/lick.h>
#include <gliss/parser.h>

using namespace gliss;

FIXTURE(does_it_compile) {
  auto output = parser_t::parse_string(R"(
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aNormal;

    int bar(int a, int b) {
      return 3;
    }

    void main() {
      for (int i = 0; i < 10; ++i) {
        i += 1;
      }
    }
  )");

  auto json = output->to_json();
  std::cout << json << std::endl;
}
