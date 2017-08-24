const ast_nodes = require('./ast_nodes');
const ast_nodes_by_id = require('./ast_nodes_by_id');
const possible_patterns = {};

const nodes = Object.keys(ast_nodes).map((id) => ast_nodes[id]);

nodes.forEach((node) => {
  nodes.forEach((possible) => {
    if (!possible.terminal) {
      const pattern_id = possible.pattern_id;
      const last = pattern_id[pattern_id.length - 1];
      const id = node.id;

      if (id === last) {
        console.log(pattern_id[pattern_id.length - 1], id);
        possible_patterns[id] = possible_patterns[id] || [];
        possible_patterns[id].push(possible.pattern_id);
      }
    }
  });
});

module.exports = possible_patterns;
console.log(possible_patterns);
console.log(ast_nodes_by_id[287]);
console.log(ast_nodes_by_id[287].pattern_id[ast_nodes_by_id[287].pattern_id.length - 1], ast_nodes_by_id[287].id);
console.log(possible_patterns[287]);