#!/usr/bin/env node
const program = require('commander');
const path = require('path');
const fs = require('fs');
const { Grammar } = require('./grammar');

program
  .version('1.0.0')
  .option('-r, --rules [path]', 'Grammar to generate states with')
  .option('-o, --out', 'Output path, defaults name of input file')
  .parse(process.argv);

if (!program.rules) {
  throw new Error('program.rules required');
}

const rules_ext = path.extname(program.rules);
const rules_name = `${path.basename(program.rules, rules_ext)}-preprocessed`;
const rules_dir = path.dirname(program.rules);
const rules_base = path.basename(program.rules);

if (!program.out) {
  program.out = path.resolve(rules_dir, rules_name);
}

let i = 0;
while (fs.existsSync(program.out)) {
  program.out = path.join(rules_dir, `${rules_name}_${++i}`);
}

const grammar = Grammar.from_file(program.rules);
console.log('Preprocessing the compiler compiler...');
const states = grammar.get_state_table();
const { tokens, symbols, rules } = grammar;
const output = JSON.stringify({ states: states.states, tokens, symbols, rules });

fs.mkdirSync(program.out);
fs.writeFileSync(path.join(program.out, 'grammar.json'), output);
const input = fs.readFileSync(path.join(program.rules), 'utf8');
fs.writeFileSync(path.join(program.out, rules_base), input);
