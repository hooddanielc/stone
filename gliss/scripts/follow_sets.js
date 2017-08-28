const syms = require('./ast_nodes').symbols_by_group;
const first_sets = require('./first_sets');

const result = {};

const get_follow_set = (group_id, taboo_tokens = []) => {
  if (result[group_id]) {
    return;
  }

  result[group_id] = [];

  // if symbol is Ω it contains break event as well as
  // all the events in First(Ω)
  if (syms[group_id].group_name === 'translation_unit') {
    result[group_id].push({ event: 'break' });
    const first_set = first_sets.first_sets_by_symbol[group_id];
    first_set.forEach((first_id) => {
      if (taboo_tokens.indexOf(first_id) === -1) {
        result[group_id].push({ event: 'token', id: first_id });
        taboo_tokens.push(first_id);
      }
    });
  }

  Object.keys(syms).forEach((sym_id) => {
    sym_id = parseInt(sym_id);

    syms[sym_id].rules.forEach((rule) => {
      // Examine each rule in which X appears on the right-hand side
      // Let A be the left hand side of this rule.
      // Let X be group_id
      // Let beta be the symbols that appear to the right of X
      if (rule.indexOf(group_id) !== -1) {
        let beta_found = false;
        const beta = [];
        rule.forEach((sym_in_rule_id) => {
          if (beta_found) {
            beta.push(sym_in_rule_id);
          } else if (group_id === sym_in_rule_id) {
            beta_found = true;
          }
        });

        // if beta is non empty, then Follow(X) includes First(beta),
        // otherwise, Follow(X) includes Follow(A).
        if (beta.length > 0) {
          first_sets.get_first_set_of_sequence(beta).forEach((sym_in_beta_id) => {
            if (sym_in_beta_id === -1) {
              return;
            }

            if (taboo_tokens.indexOf(sym_in_beta_id) === -1) {
              result[group_id].push({ event: 'token', id: sym_in_beta_id });
              taboo_tokens.push(sym_in_beta_id);
            }
          });
        } else { // Follow(A)
          get_follow_set(sym_id);
          result[sym_id].forEach((ev) => {
            if (ev.id === -1) {
              return;
            }

            if (taboo_tokens.indexOf(ev.id) === -1) {
              taboo_tokens.push(ev.id);
              result[group_id].push(ev);
            }
          });
        }
      }
    });
  });
}

Object.keys(syms).forEach((key) => {
  key = parseInt(key);
  get_follow_set(key);
});

module.exports = result;
