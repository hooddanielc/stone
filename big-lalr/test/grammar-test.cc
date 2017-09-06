#include <lick/lick.h>
#include <algorithm>
#include <big-lalr/grammar.h>

using namespace biglr;

const std::string &example_grammar = "big-lalr/test/fixtures/pets.biglr";

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

FIXTURE(starting_items) {
  auto grammar = grammar_t::from_file(example_grammar);
  auto starting_items = grammar->get_start_items();
  EXPECT_EQ(starting_items.size(), size_t(1));
  EXPECT_EQ(starting_items[0], item_t::make(
    rule_t::make(top_t::make(), {reduction_t::make("pets")}),
    0,
    break_t::make()
  ));
}

FIXTURE(get_closure) {
  auto grammar = grammar_t::from_file(example_grammar);
  auto starting_items = grammar->get_start_items();
  auto state = grammar->get_closure(starting_items);
  EXPECT_EQ(state->get_items().size(), size_t(10));
}

FIXTURE(get_goto) {
  auto grammar = grammar_t::from_file(example_grammar);
  auto starting_items = grammar->get_start_items();
  auto state = grammar->get_closure(starting_items);
  auto goto_for_pets = grammar->get_goto(state, reduction_t::make("pets"));
  EXPECT_EQ(goto_for_pets->get_items().size(), size_t(13));
  auto goto_for_g = grammar->get_goto(state, token_t::make("g"));
  EXPECT_FALSE(goto_for_g);
}

FIXTURE(get_all_states) {
  auto grammar = grammar_t::from_file(example_grammar);
  auto full_parse_table = grammar->get_full_parse_table();
  EXPECT_EQ(full_parse_table.size(), size_t(14));
}
