Big LALR
========

> An LALR parser generator that works!

No really, it works. Big LALR is a parser generator for C++. It can yield huge goto and action tables within seconds. It's easy to use and doesn't require code in your grammar file. Provide and the tokens produced by your lexer and you're good to go.

## How To Use

`biglr -h`

Generate parser next to grammar file

`biglr --rules pets.biglr`

View generated tools/documentation in a web app

`biglr --rules pets.biglr -s`

## Example Rules

`pets.biglr`

```
/token c a t d o g c a n a r y
/top -> pets
pets -> pets pet
pets -> nothing
pet -> c a t
pet -> d o g
pet -> c a n a r y
nothing ->
```

_/token_ should list all tokens
_/top_ is the starting rule, commonly known as omega.
_reduction_name -> token sequence_ is an example rule.
_nothing ->_ Rule without right side (epsilon) is aloud.

## How to use generated parser

The generated parser and token class is simple to use.

```
using namespace pets; // <-- namespace is customizable

int main (int, char*[]) {
  try {
    std::vector<std::shared_ptr<token_t>> input = {
      token_t::make(token_t::d),
      token_t::make(token_t::o),
      token_t::make(token_t::g),
      token_t::make(token_t::d),
      token_t::make(token_t::o),
      token_t::make(token_t::g),
      token_t::make(token_t::c),
      token_t::make(token_t::a),
      token_t::make(token_t::t)
    };
    auto parser = parser_t::make();

    // called on every action
    parser->on_step([&](auto data) {
      parser->write_states(std::cout); std::cout << std::endl;
      parser->write_output(std::cout); std::cout << std::endl;
      parser->write_input(std::cout); std::cout << std::endl;
      std::cout << "=================================" << std::endl;
    });

    // called before reduce action
    parser->on_reduce([&](auto data) {
      std::cout << "on reduce " << data.second << std::endl;
    });

    // called before reduce shift action
    parser->on_shift([&](auto data) {
      std::cout << "on shift " << data.second << std::endl;
    });

    // called on accept action
    parser->on_accept([&](auto data) {
      std::cout << "on accept " << data.second << std::endl;
    });

    // result contains your AST
    auto result = parser->parse(input);
    std::cout << "output size: " << result.size() << ", name: " << result[0]->get_name();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
```

You might want to override the construction of specific AST nodes. You may do this by inheriting parser and overriding the `on_reduce` method.

```
  virtual std::shared_ptr<ast_t> reduce_by_id(int id, std::vector<std::shared_ptr<ast_t>> &children) {
    return default_reduce_by_id(id, children);
  }
```

If the entire parser is of no use to you, you may of course create your own. Have a look at the default parser generator included in your generated output [here](codegen/included_driver.cc)

## Building

- Install [clang](https://clang.llvm.org/)
- Install [ib](https://github.com/JasonL9000/ib)
- build generator `ib --cfg release big-lalr/biglr`
- launch biglr `../out/release/big-lalr/biglr -r big-lalr/test/fixtures/pets.biglr`

## Run Tests

`ib --test_all big-lalr`
