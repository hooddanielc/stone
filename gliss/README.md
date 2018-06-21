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

### Building the NodeJS Module

Requires nodejs and emscripten

```
./build_js_binding.sh
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

# Use the NodeJS Binding!

`npm install gliss`

Generate an AST from GLSL source code

```
const gliss = require('gliss');

const ast = gliss.parse_glsl(`
  #ifdef GL_ES
  precision mediump float;
  #endif
  #extension GL_OES_standard_derivatives : enable
  uniform float time;
  uniform vec2 mouse;
  uniform vec2 resolution;
  void main( void ) {
    vec2 pos = gl_FragCoord.xy/resolution.xy;
    vec2 dif = pos - mouse;
    float dist = 1.0-length(dif);
    float power = pow(dist, 10.0);
    float pulse = sin(time*20.0);
    gl_FragColor = vec4(pos*dist, pulse*power, 1.0);
  }
`);

console.log(ast);

```