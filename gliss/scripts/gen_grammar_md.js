const fs = require('fs');
const path = require('path');
const grammar_text = fs.readFileSync(path.join(__dirname, 'grammar.json')).toString();
const grammar = JSON.parse(grammar_text);

var lines = [];

Object.keys(grammar).forEach((node) => {
  lines.push('');
  lines.push('#### ' + node + ':');
  const block_lines = [];

  grammar[node].forEach((list) => {
    var line = [];
    list.forEach((item) => {
      if (grammar[item]) {
        line.push('[' + item + '](#' + item + ')');
      } else {
        line.push('_' + item + '_');
      }
    });
    block_lines.push('*  ' + line.join(' '));
  });
  lines = lines.concat(block_lines.sort());
});

console.log(lines.join('\n'));