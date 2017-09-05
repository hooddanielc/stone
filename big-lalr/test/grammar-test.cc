#include <lick/lick.h>
#include <algorithm>
#include <big-lalr/grammar.h>

using namespace biglr;

const std::string &example_grammar = "big-lalr/test/fixtures/pets.tfr";

FIXTURE(constructs) {
  auto grammar = grammar_t::from_file(example_grammar);
  EXPECT_EQ(grammar->get_tokens().size(), size_t(10));
  EXPECT_EQ(grammar->get_reductions().size(), size_t(3));
  EXPECT_EQ(grammar->get_rules().size(), size_t(7));
  EXPECT_EQ(grammar->get_empties().size(), size_t(1));
}

FIXTURE(first_sets) {
  auto grammar = grammar_t::from_file(example_grammar);
  auto set = grammar->get_first_set(grammar->get_reductions()[1]);
  std::vector<std::shared_ptr<symbol_t>> expected = {
    token_t::make("c"),
    token_t::make("d")
  };
  std::sort(set.begin(), set.end(), [](auto a, auto b) { return *a < *b; });
  EXPECT_TRUE(set == expected);
  auto sequence = grammar->get_first_sequence(set);
  EXPECT_TRUE(sequence == std::vector<std::shared_ptr<symbol_t>>({ token_t::make("c") }));
}

FIXTURE(follow_sets) {
  auto grammar = grammar_t::from_file(example_grammar);
  auto follow_set = grammar->get_follow_set(top_t::make());
  EXPECT_EQ(follow_set.size(), size_t(1));
  EXPECT_EQ(follow_set[0], break_t::make());
}
