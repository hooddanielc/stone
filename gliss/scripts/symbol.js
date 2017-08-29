const fs = require('fs');
const assert = require('assert');
let next_id = 1;
const symbol_ids = {};

class Symbol {
  constructor({ name }) {
    this.name = name;

    if (!symbol_ids[name]) {
      symbol_ids[name] = next_id++;
    }

    this.id = symbol_ids[name];
    assert(this.name, 'symbol must have a name');
    assert(!/\s+/g.exec(this.name), 'no spaces in name');
    const match = /([A-Z]|[a-z]|[0-9])+$/.exec(this.name);
    assert(match && match.index === 0, 'valid name');
  }
}

const token_names = [];
const reduction_names = [];

class Token extends Symbol {
  constructor({ name }) {
    super({ name });
    assert(reduction_names.indexOf(name) === -1, 'token can not be a reduction');
    if (token_names.indexOf(name) === -1) {
      token_names.push(name);
    }
  }

  print() {
    console.log(`Token(${this.name})`);
  }
}

class Reduction extends Symbol {
  constructor({ name }) {
    super({ name });
    assert(token_names.indexOf(name) === -1, 'reduction can not be a reduction');
    if (reduction_names.indexOf(name) === -1) {
      reduction_names.push(name);
    }
  }

  print() {
    console.log(`Reduction(${this.name})`);
  }
}

class Break extends Symbol {
  constructor() {
    super({ name: Break.name });
  }

  print() {
    console.log(Break.name);
  }

  static get name() {
    return 'BREAK';
  }
}

class Top extends Reduction {
  constructor() {
    super({ name: Top.name });
  }

  print() {
    console.log(Top.name);
  }

  static get name() {
    return 'TOP';
  }
}

class Rule {
  constructor({ rhs, lhs, timeout=0 }) {
    this.lhs = lhs;
    this.rhs = rhs || [];
    this.timeout = timeout;
    assert(this.lhs, 'Rule requires a left hand side');
    assert(this.rhs instanceof Array, 'Right is always an array');
    assert(this.lhs instanceof Reduction, 'Left is always reduction');
    this.rhs.forEach((sym) => assert(sym instanceof Token || sym instanceof Reduction));

    if (lhs instanceof Top) {
      assert(rhs.length === 1, 'Omega rule has one token on right side');
    }
  }

  print() {
    console.log(`Rule(${this.lhs.name} -> ${this.rhs.map(({name}) => name).join(' ')})`);
  }

  get length() {
    return this.rhs.length;
  }
}

class Item {
  constructor({ rule, dot, peek }) {
    this.rule = rule;
    this.dot = dot;
    this.peek = peek;
    assert(dot >= 0 && dot <= rule.length, 'dot is within rule');
  }

  get rhs() {
    return this.rule.rhs;
  }

  get lhs() {
    return this.rule.lhs;
  }

  get is_complete() {
    return this.rule.length === this.dot;
  }

  get corner_symbol() {
    return this.rule[this.dot];
  }
}

class Grammar {
  constructor({ rules, tokens, symbols, epsilon }) {
    this.rules = rules;
    this.tokens = tokens;
    this.epsilon = epsilon;
    this.symbols = symbols;
  }

  static from_str(str) {
    const rules = [];
    const tokens = {};
    const symbols = {};
    const reductions = {};
    let epsilon = null;
    const lines = str.split('\n');
    assert(lines[0].substring(0, 6) === '/token', 'first line must declare tokens');

    lines.forEach((line) => {
      const trimmed = line.trim();
      const parts = line.split(/\s+/);

      if (parts[0] === '/token') {
        parts.shift();
        parts.forEach((part) => {
          if (part !== '->') {
            tokens[part] = new Token({ name: part });
            symbols[part] = tokens[part];
          }
        });
      } else if (parts[0] === '/top') {
        parts.shift();
        assert(parts[0] === '->', '/top has an arrow to the right');
        parts.shift();
        assert(parts.length === 1);
        symbols[parts[0]] = symbols[parts[0]] || new Reduction({ name: parts[0] });
        reductions[parts[0]] = symbols[parts[0]];
        rules.push(new Rule({
          lhs: new Top(),
          rhs: [symbols[parts[0]]]
        }));
      } else if (parts[0] === '/epsilon') {
        parts.shift();
        assert(parts[0] === '->', '/epsilon has an arrow to the right');
        parts.shift();
        epsilon = parts[0];
      } else if (parts.length && parts[0]) {
        const name = parts.shift();
        assert(parts[0] === '->', 'reduction has an arrow to the right');
        parts.shift();

        if (!symbols[name]) {
          symbols[name] = new Reduction({ name });
          reductions[name] = symbols[name];
        }

        rules.push(new Rule({
          lhs: symbols[name],
          rhs: parts.map((part_name) => {
            if (!symbols[part_name]) {
              symbols[part_name] = new Reduction({ name: part_name });
              reductions[part_name] = symbols[part_name];
            }
            return symbols[part_name]
          })
        }));
      }
    });

    // assert reductions has at least one definition
    Object.keys(reductions).forEach((name) => {
      const defs = rules.filter((rule) => {
        return rule.lhs.name === name;
      });
      assert(defs.length > 0, `${name} has a definition`);
    });
  }

  static from_file(file_path) {
    return this.from_str(fs.readFileSync(file_path, 'utf8'));
  }
}

module.exports = {
  Symbol,
  Token,
  Reduction,
  Rule,
  Grammar
};
