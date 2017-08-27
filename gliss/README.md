# Gliss

## A GLSL Lexer and Parser

### Dependencies

None! You can easily copy and paste this code into another build system super easily. I recommend continuing to use ib since it saves you a lot of time by removing some features ;)

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

4. If you modify any of the generator code in `scripts/gen_cpp_node_constants.js` just run it with nodejs.

```
node gliss/scripts/gen_cpp_node_constants.js # generate c++ parser
```

### Getting Started

```c++
#include <iostream>
#include <gliss/lexer.h>
#include <gliss/parser.h>
#include <gliss/pretty-print-ast.h>

using namespace gliss;

int main() {
  // First grab list of token from source text
  auto tokens = lexer_t::lex(R"(
    int blah = 3;
  )");

  // create a parser with tokens
  auto parser = parser_t::make(tokens);
  // reduce to a syntax tree using shift reduce parser
  auto stack = parser.parse(tokens);

  // print the ast using the "pretty-print-ast" visitor
  parser.print_stack();
}
```

To make your own visitor, look at `pretty-print-ast.h`
