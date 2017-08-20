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

console.log([
  '# Grammar',
  '',
  '### The following describes the grammar for the OpenGL Shading Language in terms of [these tokens](tokens.md).',
  '',
  `The starting rule is [translation_unit](#translation_unit). An empty shader
  (one having no tokens to parse, after preprocessing) is valid, resulting in
  no compile-time errors, even though the grammar below does not have a rule to accept an
  empty token stream. Taken from [OpenGL 4.60 Specification Ch. 9](https://www.khronos.org/registry/OpenGL/specs/gl/GLSLangSpec.4.60.pdf)
  `.split('\n  ').join(' ').split('\n ').join(' '),
].concat(lines).join('\n'));