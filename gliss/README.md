# Gliss

## A GLSL Lexer and Parser

### Dependencies

None! You can easily copy and paste this code into another build system without much hassle.

### Building

1. Install [ib](https://github.com/JasonL9000/ib)

2. Install clang

3. Run the build. To build on osx, use osx-debug config

```
# Use default debug config
ib gliss/test/lexer-test

# Use osx-debug config
ib gliss/test/lexer-test --cfg osx-debug.cfg
```

4. If you modify the grammar file `docs/glsl.biglr` be sure to regenerate the parser using the provided script.

```
./regenerate_parser.sh
```

### View Language Docs

`./view_parser_doc.sh`

### Getting Started

```c++
#include <iostream>
#include <gliss/parser.h>

using namespace gliss;

int main() {
  auto output = parser_t::parse_string(R"(
    uniform mat4 viewMatrix, projMatrix;

    in vec4 position;
    in vec3 color;

    out vec3 Color;

    void main() {
      Color = color;
      gl_Position = projMatrix * viewMatrix * position;
    }
  )");

  std::cout << output->get_name() << std::endl;

  return 0;
}
```
