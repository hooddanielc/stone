const ast_nodes = require('./ast_nodes');
const ast_nodes_by_id = require('./ast_nodes_by_id');
const possible_patterns = {};

const nodes = Object.keys(ast_nodes).map((id) => ast_nodes[id]);

nodes.forEach((node) => {
  const id = node.id;
  const taboo = [];

  nodes.forEach((possible) => {
    if (!possible.terminal) {
      const last = possible.pattern_id[possible.pattern_id.length - 1];

      if (id === last) {
        if (!possible_patterns[id]) {
          possible_patterns[id] = [];
        }

        if (taboo.indexOf(possible.pattern_id) > -1) {
          return;
        }

        possible_patterns[id].push(possible.pattern_id);
      }
    }
  });
});

/* return a map of possible reductions starting */
/* from the right most symbol of a production */
module.exports = possible_patterns;
