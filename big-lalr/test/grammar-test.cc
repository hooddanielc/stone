#include <lick/lick.h>
#include <big-lalr/grammar.h>

using namespace biglr;

const std::string &example_grammar = "big-lalr/test/fixtures/pets.tfr";

FIXTURE(constructs) {
  auto grammar = grammar_t::from_file(example_grammar);
}
