const fs = require('fs');
const path = require('path');
const grammar_text = fs.readFileSync(path.join(__dirname, 'grammar.json')).toString();
const grammar = JSON.parse(grammar_text);

var todo_list = [];
const todo_errors_map = {};
let greatestDepth = 0;

function find_todo(todo, taboo = []) {
  if (taboo.indexOf(todo) !== -1) {
    return;
  }

  taboo.push(todo);

  grammar[todo].forEach((list) => {
    list.forEach((item) => {
      if (grammar[item]) {
        find_todo(item, taboo);
      } else if (item !== item.toUpperCase()) {
        throw new Error('non terminal symbol does not exist in grammar map: ' + item);
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

if (Object.keys(todo_errors_map).length) {
  throw new Error('not left factored');
}

console.log('success, grammar is left factored');