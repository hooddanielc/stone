const fs = require('fs');
const path = require('path');
const ordered_grammar_text = fs.readFileSync(path.join(__dirname, 'ordered_grammar.json'), 'utf8');
const ordered_grammar = JSON.parse(ordered_grammar_text);
const grammar_text = fs.readFileSync(path.join(__dirname, 'grammar.json'), 'utf8');
const grammar = JSON.parse(grammar_text);

let i = 0;
ordered_grammar.forEach((node) => {
  const matcher = `try_match_${node}`;
  console.log(matcher);

  grammar[node].forEach((list) => {
    const class_name = [node].concat(list).map((item) => item.toLowerCase()).join('_');
    console.log(++i + '  ' + class_name + '_t');
  });
});
