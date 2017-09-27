#include <unistd.h>
#include <cstdio>
#include <lick/lick.h>
#include <big-lalr/grammar.h>
#include <big-lalr/util.h>

using namespace biglr;

const std::string &example_grammar = "big-lalr/test/fixtures/pets.biglr";

FIXTURE(parser_gens_json) {
  auto grammar = grammar_t::from_file(get_project_path(example_grammar));
  auto full_parse_table = grammar->get_full_parse_table();
  auto json = full_parse_table->to_json();
  // iterate the array
  EXPECT_TRUE(json.find("actions") != json.end());
  EXPECT_TRUE(json.find("cpp") != json.end());
  EXPECT_TRUE(json.find("dot") != json.end());
  EXPECT_TRUE(json.find("reductions") != json.end());
  EXPECT_TRUE(json.find("rules") != json.end());
  EXPECT_TRUE(json.find("tokens") != json.end());

  // check valid length
  EXPECT_EQ(json["actions"].size(), size_t(14));
  EXPECT_TRUE(json["cpp"].size() > size_t(4));
  EXPECT_EQ(json["dot"].size(), size_t(1));
  EXPECT_EQ(json["reductions"].size(), size_t(3));
  EXPECT_EQ(json["rules"].size(), size_t(7));
  EXPECT_EQ(json["tokens"].size(), size_t(10));
}

std::string generate_pets_code(const std::string &grammar_file) {
  auto grammar = grammar_t::from_file(get_project_path(grammar_file));
  auto full_parse_table = grammar->get_full_parse_table();

  std::stringstream ss;
  ss << "#include <string>" << std::endl;
  ss << "#include <vector>" << std::endl;
  ss << "#include <memory>" << std::endl;
  ss << "#include <iostream>" << std::endl;
  ss << "#include <cassert>" << std::endl;
  ss << "#include <utility>" << std::endl;
  ss << "#include <unordered_map>" << std::endl;
  ss << "#include <functional>" << std::endl;
  ss << std::endl;
  ss << full_parse_table->get_symbols_h() << std::endl;
  ss << full_parse_table->get_tokens_h() << std::endl;
  ss << full_parse_table->get_ast_base_h() << std::endl;
  ss << full_parse_table->get_all_reductions_h() << std::endl;
  ss << full_parse_table->get_actions_h() << std::endl;
  ss << full_parse_table->get_driver_h() << std::endl;
  ss << std::endl;
  return ss.str();
}

std::string token_fixture_program = R"(

int main(int, char*[]) {
  auto token = token_t::make(token_t::a);
  std::cout << token->get_name();
  auto d = ast_token_t::make(token_t::make(token_t::d));
  auto o = ast_token_t::make(token_t::make(token_t::o));
  auto g = ast_token_t::make(token_t::make(token_t::g));
  auto dog = pet_from_d_o_g_t::make({
    d,
    o,
    g
  });
  return 0;
}

)";

std::string symbols_program = R"(

int main(int, char*[]) {
  std::cout << symbol_t::get_name(symbol_t::r);
  return 0;
}

)";

std::string reduction_lookup_program = R"(

int main (int, char*[]) {
  auto size = reduction_lookup_t<nothing_as_epsilon_t::rule_id>::type::pattern.size();
  std::cout << "empty rule has " << size << " children";
  return 0;
}

)";

std::string driver_functionality = R"(

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

    // parser->on_step([&](auto data) {
    //   parser->write_states(std::cout); std::cout << std::endl;
    //   parser->write_output(std::cout); std::cout << std::endl;
    //   parser->write_input(std::cout); std::cout << std::endl;
    //   std::cout << "=================================" << std::endl;
    // });

    // parser->on_reduce([&](auto data) {
    //   std::cout << "on reduce " << data.second << std::endl;
    // });

    // parser->on_shift([&](auto data) {
    //   std::cout << "on shift " << data.second << std::endl;
    // });

    // parser->on_accept([&](auto data) {
    //   std::cout << "on accept " << data.second << std::endl;
    // });

    // parser->on_accept([&](auto data) {
    //   std::cout << "on transition " << data.second << std::endl;
    //   parser->write_states(std::cout); std::cout << std::endl;
    //   parser->write_output(std::cout); std::cout << std::endl;
    //   parser->write_input(std::cout); std::cout << std::endl;
    //   std::cout << "=================================" << std::endl;
    // });

    auto result = parser->parse(input);
    std::cout << "output size: " << result.size() << ", name: " << result[0]->get_name();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}

)";

std::string get_program_output(const std::string &src) {
  auto input_path = get_tmp_path("test-token-cpp-", ".cc");
  auto output_path = get_tmp_path();
  write_file_contents(input_path, src);

  // compile src
  auto compiler_process = child_process_t::make("/usr/bin/gcc", {
    input_path,
    "-std=c++14",
    "-lstdc++",
    "-o",
    output_path,
    "-v"
  });

  compiler_process->on_stdout([](auto) {
    //std::cout << str;
  });
  compiler_process->on_stderr([](auto) {
    //std::cout << str;
  });
  compiler_process->on_exit([](auto code) {
    EXPECT_EQ(code, 0);
  });
  compiler_process->exec_sync();

  // execute
  std::string result;
  auto executable = child_process_t::make(output_path, {});
  executable->on_stdout([&](auto str) {
    result += str;
  });

  executable->on_exit([&](auto code) {
    EXPECT_EQ(code, 0);
    std::remove(input_path.c_str());
    std::remove(output_path.c_str());
  });

  executable->exec_sync();
  return result;
}

FIXTURE(parser_gens_tokens_and_compiles) {
  auto input_path = get_tmp_path("test-token-cpp-", ".cc");
  auto output_path = get_tmp_path();
  auto pets_code_gen = generate_pets_code("big-lalr/test/fixtures/pets.biglr");

  EXPECT_EQ(get_program_output(pets_code_gen + token_fixture_program), "a");
  EXPECT_EQ(get_program_output(pets_code_gen + symbols_program), "r");

  EXPECT_EQ(
    get_program_output(pets_code_gen + reduction_lookup_program),
    "empty rule has 0 children"
  );

  EXPECT_EQ(get_program_output(pets_code_gen + driver_functionality), "output size: 1, name: pets");
}
