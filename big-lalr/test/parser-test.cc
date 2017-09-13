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
  auto src = full_parse_table->get_tokens_h();
  auto input_path = get_tmp_path("test-token-cpp-", ".cc");
  auto output_path = get_tmp_path();
  std::stringstream ss;
  ss << src;
  ss << std::endl;
  ss << "int main(int, char*[]) {" << std::endl;
  ss << "  return 0;" << std::endl;
  ss << "}" << std::endl;
  write_file_contents(input_path, ss.str());

  // run compiler in child process and test output
  auto child_process = child_process_t::make("/bin/gcc", {
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

  // check if exit status = 0
  EXPECT_EQ(exit_code, 0);
  std::remove(input_path.c_str());
  std::remove(output_path.c_str());
}
