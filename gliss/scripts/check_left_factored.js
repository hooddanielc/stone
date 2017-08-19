const fs = require('fs');
const path = require('path');
const grammar_text = fs.readFileSync(path.join(__dirname, 'grammar.json')).toString();
const grammar = JSON.parse(grammar_text);

var todo_list = [];
const todo_errors_map = {};

function find_todo(todo, spaces = 0) {
  const more_spaces = spaces + 2;
  if (todo_list.indexOf(todo) !== -1) return;
  todo_list.push(todo);
  const joined_list = [];
  grammar[todo].forEach((list) => {
    const joined_item = list.join(' ');
    joined_list.push(joined_item);
    console.log(new Array(spaces).join(' ') + joined_item);
    list.forEach((item) => {
      if (grammar[item]) {
        find_todo(item, more_spaces);
      }
    });
  });

  grammar[todo].forEach((list, idx) => {
    grammar[todo].forEach((check, check_idx) => {
      if (idx === check_idx) return;
      if (check.length > list.length) {
        list.forEach((item, idx) => {
          if (item === check[idx]) {
            console.log(`### ${list.join(' ')} conflicts with ${check.join(' ')} ###`);
            //throw new Error('must be left factored');
            todo_errors_map[todo] = todo_errors_map[todo] || [];
            todo_errors_map[todo].push(`  '${list.join(' ')}' conflicts with '${check.join(' ')}'`);
          }
        });
      }
    });
  });
}

find_todo('translation_unit');

Object.keys(todo_errors_map).forEach((key) => {
  console.log(`${key} needs factoring`)
  todo_errors_map[key].forEach((err) => {
    console.log(`  ${err}`);
  });
});

throw new Error('not left factored');