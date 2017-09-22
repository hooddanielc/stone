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
  EXPECT_EQ(json["cpp"].size(), size_t(3));
  EXPECT_EQ(json["dot"].size(), size_t(1));
  EXPECT_EQ(json["reductions"].size(), size_t(3));
  EXPECT_EQ(json["rules"].size(), size_t(7));
  EXPECT_EQ(json["tokens"].size(), size_t(10));
}

FIXTURE(parser_gens_tokens_and_compiles) {
  auto grammar = grammar_t::from_file(get_project_path(example_grammar));
  auto full_parse_table = grammar->get_full_parse_table();
  auto input_path = get_tmp_path("test-token-cpp-", ".cc");
  auto output_path = get_tmp_path();

  std::stringstream ss;
  ss << "#include <string>" << std::endl;
  ss << "#include <vector>" << std::endl;
  ss << "#include <memory>" << std::endl;
  ss << "#include <iostream>" << std::endl;
  ss << "#include <cassert>" << std::endl;
  ss << std::endl;
  ss << full_parse_table->get_tokens_h() << std::endl;
  ss << full_parse_table->get_ast_base_h() << std::endl;
  ss << full_parse_table->get_all_reductions_h() << std::endl;
  ss << std::endl;
  ss << "int main(int, char*[]) {" << std::endl;
  ss << "  auto token = token_t::make(token_t::a);" << std::endl;
  ss << "  std::cout << token->get_name();" << std::endl;
  ss << "  auto d = ast_token_t::make(token_t::make(token_t::d));" << std::endl <<
        "  auto o = ast_token_t::make(token_t::make(token_t::o));" << std::endl <<
        "  auto g = ast_token_t::make(token_t::make(token_t::g));" << std::endl <<
        "  auto dog = pet_from_d_o_g_t::make({" << std::endl <<
        "    d," << std::endl <<
        "    o," << std::endl <<
        "    g" << std::endl <<
        "  });" << std::endl;
  ss << "  return 0;" << std::endl;
  ss << "}" << std::endl;
  write_file_contents(input_path, ss.str());

  // run compiler in child process and test output
  auto compiler_process = child_process_t::make("/usr/bin/gcc", {
    input_path,
    "-std=c++14",
    "-lstdc++",
    "-o",
    output_path
  });

  compiler_process->on_exit([&](auto compiler_exit_code) {
    EXPECT_EQ(compiler_exit_code, 0);

    std::string stdout = "";
    auto exec_compiled_file = child_process_t::make(output_path, {});
    exec_compiled_file->on_stdout([&](auto str) {
      stdout += str;
    });

    exec_compiled_file->on_exit([&](auto compiled_file_exit_code) {
      EXPECT_EQ(compiled_file_exit_code, 0);
      EXPECT_EQ(stdout, "a");
    });

    exec_compiled_file->exec_sync();
  });

  compiler_process->exec_sync();
}
