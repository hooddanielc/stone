const grammar = require('./grammar');
const tokens = require('./tokens');

let idx = 0;
let importance = 0;
const id_map = {};
const group_ids = {};

const get_ast_name = (group_name, pattern) => {
  return `${group_name}_${pattern.join('_')}`;
}

tokens.forEach((terminal) => {
  group_ids[terminal] = idx++;

  id_map[terminal] = {
    id: group_ids[terminal],
    importance: importance++,
    terminal: true,
    pattern: [terminal],
    pattern_id: [group_ids[terminal]]
  };
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
  id_map[get_ast_name(group_item.group_name, group_item.pattern)] = {
    /* multiple tokens may have the same id, use importance for uniqueness */
    /* each ast node is identified by the group it's production was reduced to */
    id: group_ids[group_item.group_name],
    /* an ast's group_name and production is always unique, but to make things easier, */
    /* added another number here */
    importance: importance++,
    terminal: false,
    group_name: group_item.group_name,
    pattern: group_item.pattern,
    pattern_id: group_item.pattern.map((name) => group_ids[name] || -1)
  };
});

module.exports = id_map;
