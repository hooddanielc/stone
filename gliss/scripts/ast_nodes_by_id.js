const ast_nodes = require('./ast_nodes');
const possible_patterns = {};

const by_id = {};

Object.keys(ast_nodes).forEach((name) => {
  by_id[ast_nodes[name].id] = ast_nodes[name];
});

module.exports = by_id;
