const fs = require('fs');
const path = require('path');
const grammar_text = fs.readFileSync(path.join(__dirname, 'grammar.json')).toString();
const grammar = JSON.parse(grammar_text);

var todo_list = [];

function find_todo(todo, spaces = 0) {
  const more_spaces = spaces + 2;
  console.log(new Array(spaces).join(' ') + todo);
  if (todo_list.indexOf(todo) !== -1) return;
  todo_list.push(todo);
  grammar[todo].forEach((list) => {
    list.forEach((item) => {
      if (grammar[item]) {
        find_todo(item, more_spaces);
      }
    });
  });
}

find_todo('translation_unit');