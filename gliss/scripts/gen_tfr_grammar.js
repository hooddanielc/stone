const tokens = require('./tokens');
const grammar = require('./grammar');

const token_str = tokens.join(' ');

console.log('/token ' + token_str);
console.log('/top -> translation_unit');
console.log('/epsilon -> nothing');

Object.keys(grammar).forEach((symbol) => {
  grammar[symbol].forEach((rule) => {
    console.log(`${symbol} -> ${rule.join(' ')}`);
  });
});
