const fs = require('fs');
const path = require('path');
const grammar_text = fs.readFileSync(path.join(__dirname, 'grammar.json')).toString();
const grammar = JSON.parse(grammar_text);

var todo_list = [];

function find_todo(todo) {
  if (todo_list.indexOf(todo) !== -1) return;
  todo_list.push(todo);
  grammar[todo].forEach((list) => {
    list.forEach((item) => {
      if (grammar[item]) {
        find_todo(item);
      }
    });
  });
}

find_todo('translation_unit');
console.log(todo_list.map((todo) => {
  return '- [ ] [' + todo + '](grammar.md#' + todo + ')';
}).join('\n'));
