#include <unistd.h>
#include <cstdio>
#include <lick/lick.h>
#include <big-lalr/grammar.h>
#include <big-lalr/util.h>

using namespace biglr;

const std::string &example_grammar = "big-lalr/test/fixtures/pets.biglr";

FIXTURE(parser_gens_tokens_and_compiles) {
  auto grammar = grammar_t::from_file(get_project_path(example_grammar));
  auto full_parse_table = grammar->get_full_parse_table();
  auto tokens_header = full_parse_table->get_tokens_h();
  auto ast_base_header = full_parse_table->get_ast_base_h();
  auto input_path = get_tmp_path("test-token-cpp-", ".cc");
  auto output_path = get_tmp_path();
  std::stringstream ss;
  ss << "#include <string>" << std::endl;
  ss << "#include <vector>" << std::endl;
  ss << "#include <memory>" << std::endl;
  ss << "#include <iostream>" << std::endl;
  ss << "#include <cassert>" << std::endl;
  ss << std::endl;
  ss << tokens_header << std::endl;
  ss << ast_base_header << std::endl;
  ss << std::endl;
  ss << "int main(int, char*[]) {" << std::endl;
  ss << "  token_t token(token_t::a);" << std::endl;
  ss << "  std::cout << token.get_name();" << std::endl;
  ss << "  return 0;" << std::endl;
  ss << "}" << std::endl;
  write_file_contents(input_path, ss.str());

  // run compiler in child process and test output
  auto child_process = child_process_t::make("/usr/bin/gcc", {
    input_path,
    "-std=c++14",
    "-lstdc++",
    "-o",
    output_path
  });
  int exit_code = -1;
  child_process->on_exit([&](auto code) {
    exit_code = code;
  });
  child_process->exec_sync();

  // check if generated program compiled successfully
  EXPECT_EQ(exit_code, 0);
  std::remove(input_path.c_str());

  // run and check output of generated program
  auto exec_compiled_file = child_process_t::make(output_path, {});
  std::string compiled_stdout = "";
  exec_compiled_file->on_data([&](auto str) {
    compiled_stdout += str;
  });
  int compiled_exit_code = -1;
  exec_compiled_file->on_exit([&](auto code) {
    compiled_exit_code = code;
  });
  exec_compiled_file->exec_sync();
  std::remove(output_path.c_str());

  // check generated program exit code
  EXPECT_EQ(compiled_exit_code, 0);
  // check generated program std output
  EXPECT_EQ(compiled_stdout, "a");
}
