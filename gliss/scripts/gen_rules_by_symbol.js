const path = require('path');
const fs = require('fs');
const ast_nodes = require('./ast_nodes');

const lines = [];
lines.push('# Rules By Symbol');
lines.push('');

Object.keys(ast_nodes.rules_by_symbol).sort((a, b) => {
  let A = ast_nodes.rules_by_symbol[a].patterns;
  let B = ast_nodes.rules_by_symbol[b].patterns;
  if (A < B) return 1;
  if (A > B) return -1;
  if (A === B) return 0;
}).forEach((symbol) => {
  lines.push(`#### ${symbol} - ${ast_nodes.rules_by_symbol[symbol].patterns} rules`);
  lines.push('');
  Object.keys(ast_nodes.rules_by_symbol[symbol]).forEach((group) => {
    if (!ast_nodes.rules_by_symbol[symbol][group].forEach) return;
    lines.push(`  __${group}__`);

    ast_nodes.rules_by_symbol[symbol][group].forEach((pattern) => {
      lines.push(`    - ${pattern.join(' ')}`);
    });
    lines.push('');
  });
  lines.push('');
});

fs.writeFileSync(path.resolve(__dirname, '..', 'docs', 'rules-by-symbol.md'), lines.join('\n'));