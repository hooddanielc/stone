const syms = require('./ast_nodes').symbols_by_group;
const result = {};

const recursive_find_first = (group_id, result=[], taboo_non_terminal=[]) => {  
  if (group_id === -1) { // nothing?
    result.push(-1);
  } else if (syms[group_id].terminal) { // is it a terminal?
    if (result.indexOf(group_id) === -1) {
      result.push(group_id);
    }

    return result;
  } else { // non terminal? add it's first set
    if (taboo_non_terminal.indexOf(group_id) !== -1) {
      return;
    }

    taboo_non_terminal.push(group_id);
    const rules = syms[group_id].rules;
    rules.forEach((right_side) => {
      recursive_find_first(right_side[0], result, taboo_non_terminal);
    });
  }

  return result;
}

// compute the first set of each symbol and return a map
Object.keys(syms).map((group_id) => {
  group_id = parseInt(group_id);
  result[group_id] = recursive_find_first(group_id);
});

// compute the first set of a sequence of symbols
const first_set_sequence = (sequence) => {
  let r = [];

  for (var i = 0; i < sequence.length; ++i) {
    r = r.concat(result[sequence[i]]);
    if (r.indexOf(-1) === -1) {
      return r;
    }
    r = r.filter((a) => {
      return a !== -1;
    });
  }

  // add epsilon if all sets have it
  r.push(-1);
  return r;
}

module.exports = {
  first_sets_by_symbol: result,
  get_first_set_of_sequence: first_set_sequence
};
