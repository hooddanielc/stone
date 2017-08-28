const grammar = require('./grammar');
const tokens = require('./tokens');
const nice_token_names = require('./nice_token_names');

let idx = 1;
let importance = 1;
const id_map = {};
const group_ids = {};
const terminal_symbols = [];
const reduced_symbols = [];
const rules = {};

const get_ast_name = (group_name, pattern) => {
  return `${group_name}_${pattern.join('_')}`.toLowerCase();
}

tokens.forEach((terminal) => {
  group_ids[terminal] = idx++;

  id_map[terminal] = {
    name: terminal,
    nice_name: nice_token_names[terminal],
    group_id: group_ids[terminal],
    group_name: 'ast_token',
    rule_id: importance++,
    terminal: true,
    rule_def: [terminal],
    rule: [group_ids[terminal]]
  };

  terminal_symbols.push(id_map[terminal]);
});

const patterns = [];

Object.keys(grammar).forEach((group_name) => {
  grammar[group_name].forEach((pattern) => {
    group_ids[group_name] = group_ids[group_name] || idx++;
    patterns.push({group_name, pattern});
  });
});

patterns.sort((A, B) => {
  const a = A.pattern.length;
  const b = B.pattern.length;

  if (a > b) {
    return 1;
  } else if (a < b) {
    return -1;
  } else if (a === b) {
    return 0;
  }
}).forEach((group_item) => {
  const name = get_ast_name(group_item.group_name, group_item.pattern);
  id_map[name] = {
    group_id: group_ids[group_item.group_name],
    rule_id: importance++,
    terminal: false,
    name: name,
    nice_name: group_item.group_name,
    group_name: group_item.group_name,
    rule_def: group_item.pattern,
    rule: group_item.pattern.map((name) => group_ids[name] || -1)
  };

  reduced_symbols.push(id_map[name]);
});

const get_reductions = (symbol) => {
  const reductions = [];
  reduced_symbols.forEach((reduction) => {
    const last_symbol = reduction.rule[reduction.rule.length - 1];
    if (last_symbol === symbol.group_id) {
      reductions.push({
        group_id: reduction.group_id,
        id: reduction.rule_id,
        name: reduction.name,
        rule: reduction.rule
      });
    }
  });
  return reductions.sort((a, b) => {
    const d = a.rule.length - b.rule.length;
    if (d < 0) return 1;
    if (d > 0) return -1;
    return 0;
  });
}

const symbol_to_reductions = {};

terminal_symbols.forEach((symbol) => {
  const reductions = get_reductions(symbol);
  if (!reductions.length) {
    return;
  }
  symbol_to_reductions[symbol.group_id] = reductions;
});

reduced_symbols.forEach((symbol) => {
  const reductions = get_reductions(symbol);
  if (!reductions.length) {
    return;
  }
  symbol_to_reductions[symbol.group_id] = reductions;
});

const symbol_enum_values = {};

terminal_symbols.forEach(({group_id, nice_name}) => {
  symbol_enum_values[nice_name] = group_id;
});

reduced_symbols.forEach(({group_id, nice_name}) => {
  symbol_enum_values[nice_name] = group_id;
});

const symbols_by_group = () => {
  const result = {};
  const syms = Object.keys(id_map).map((key) => id_map[key]);
  syms.forEach((sym) => {
    result[sym.group_id] = result[sym.group_id] || {};
    result[sym.group_id].group_name = sym.group_name;
    result[sym.group_id].terminal = sym.terminal;
    result[sym.group_id].group_id = sym.group_id;

    if (sym.terminal) {
      result[sym.group_id].symbol_name = sym.name;
    } else {
      result[sym.group_id].symbol_name = sym.group_name;
    }

    if (sym.rule) {
      result[sym.group_id].rules = result[sym.group_id].rules || [];
      result[sym.group_id].rules.push(sym.rule);
    }
  });
  return result;
}

const rules_by_symbol = {};

Object.keys(grammar).forEach((group_name) => {
  grammar[group_name].forEach((pattern) => {
    pattern.forEach((symbol) => {
      rules_by_symbol[symbol] = rules_by_symbol[symbol] || {patterns: 0};
      rules_by_symbol[symbol][group_name] = rules_by_symbol[symbol][group_name] || [];
      rules_by_symbol[symbol][group_name].push(pattern);
      rules_by_symbol[symbol].patterns += 1;
    });
  });
});

module.exports = {
  symbols: id_map,
  terminal_symbols: terminal_symbols,
  reduced_symbols: reduced_symbols,
  symbol_enum_values: symbol_enum_values,
  symbol_to_reductions,
  symbols_by_group: symbols_by_group(),
  rules_by_symbol
};
