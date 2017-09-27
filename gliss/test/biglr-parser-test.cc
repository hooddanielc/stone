#include <lick/lick.h>
#include <gliss/glsl-lang.h>

using namespace glsl;

FIXTURE(does_it_compile) {
  std::vector<std::shared_ptr<token_t>> input = {
    token_t::make(token_t::LAYOUT),
    token_t::make(token_t::LEFT_PAREN),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::EQUAL),
    token_t::make(token_t::INTCONSTANT),
    token_t::make(token_t::RIGHT_PAREN),
    token_t::make(token_t::OUT),
    token_t::make(token_t::VEC4),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::SEMICOLON),
    token_t::make(token_t::IN),
    token_t::make(token_t::VEC4),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::SEMICOLON),
    token_t::make(token_t::IN),
    token_t::make(token_t::VEC4),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::SEMICOLON),
    token_t::make(token_t::VOID),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::LEFT_PAREN),
    token_t::make(token_t::VOID),
    token_t::make(token_t::RIGHT_PAREN),
    token_t::make(token_t::LEFT_BRACE),
    token_t::make(token_t::VEC4),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::EQUAL),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::SEMICOLON),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::EQUAL),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::STAR),
    token_t::make(token_t::IDENTIFIER),
    token_t::make(token_t::SEMICOLON),
    token_t::make(token_t::RIGHT_BRACE)
  };

  auto parser = parser_t::make();

  try {

    parser->on_step([&](auto data) {
      parser->write_states(std::cout); std::cout << std::endl;
      parser->write_output(std::cout); std::cout << std::endl;
      parser->write_input(std::cout); std::cout << std::endl;
      std::cout << "=================================" << std::endl;
    });

    parser->on_reduce([&](auto data) {
      std::cout << "on reduce " << data.second << std::endl;
    });

    parser->on_shift([&](auto data) {
      std::cout << "on shift " << data.second << std::endl;
    });

    parser->on_accept([&](auto data) {
      std::cout << "on accept " << data.second << std::endl;
    });

    auto result = parser->parse(input);
    std::cout << "output size: " << result.size();
  } catch (const std::exception &e) {

    std::cout << "Something bad?" << std::endl;
    std::cout << e.what() << std::endl;
  }
}
