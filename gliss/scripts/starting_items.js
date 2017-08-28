const follow_sets = require('./follow_sets');
const first_sets = require('./first_sets').first_sets_by_symbol;
const symbols_by_group = require('./ast_nodes').symbols_by_group;

const omega = Object.keys(symbols_by_group).filter((group_id) => {
  return symbols_by_group[group_id].group_name === 'translation_unit';
})[0];

// console.log('follow sets');
// Object.keys(follow_sets).forEach((group_id) => {
//   console.log(symbols_by_group[group_id].symbol_name);
//   follow_sets[group_id].forEach((s) => {
//     if (s.event === 'break') {
//       console.log('  --');
//     } else{
//       console.log('  ' + symbols_by_group[s.id].symbol_name);
//     }
//   });
// });

console.log('first sets');
Object.keys(first_sets).forEach((group_id) => {
  console.log(symbols_by_group[group_id].symbol_name);
  first_sets[group_id].forEach((s) => {
    if (s === -1) {
      return;
    }

    console.log('  ' + symbols_by_group[s].symbol_name);
  });
});
