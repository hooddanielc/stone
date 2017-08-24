const fs = require('fs');
const path = require('path');
const grammar = require('./grammar');

var lines = [];

const letters = [
  'A',
  'B',
  'C',
  'D',
  'E',
  'F',
  'G'
]

const is_terminal = (tok) => {
  return !grammar[tok];
}

Object.keys(grammar).forEach((group) => {
  grammar[group].forEach((pattern) => {
    const count_map = { [group]: 1 };
    const toks = pattern.map((tok) => {
      if (typeof count_map[tok] === 'undefined') {
        count_map[tok] = 0;
      }
      const result = `${tok}(${letters[count_map[tok]]})`;
      count_map[tok] += 1;
      return result;
    });
    lines.push(`${group}(A) ::= ${toks.join(' ')}.`);
  });
});

lines.unshift('program ::= translation_unit.');
console.log(lines.join('\n'));

