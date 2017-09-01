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
    const match = /([A-Z]|[a-z]|[0-9]|_)+$/.exec(this.name);
    assert(match && match.index === 0, 'valid name');
  }
}

const token_names = [];
const reduction_names = [];

class Token extends Symbol {
  constructor({ name }) {
    super({ name });
    this.terminal = true;
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
    this.terminal = false;
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

class Epsilon extends Symbol {
  constructor() {
    super({ name: Epsilon.name });
  }

  print() {
    console.log(Epsilon.name);
  }

  static get name() {
    return 'EPSILON';
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
    this.rhs.forEach((sym) => assert(
      sym instanceof Token ||
      sym instanceof Reduction ||
      sym instanceof Epsilon
    ));

    if (lhs instanceof Top) {
      assert(rhs.length === 1, 'Omega rule has one token on right side');
    }

    this.id = next_id++;
  }

  contains(token) {
    return this.rhs.filter((s) => s.id === token.id).length > 0;
  }

  print() {
    console.log(`Rule(${this.lhs.name} -> ${this.rhs.map(({name}) => name).join(' ')})`);
  }

  get_str() {
    return `${this.lhs.name} -> ${this.rhs.map(({name}) => name).join(' ')}`;
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

  print() {
    console.log(`Rule(${this.lhs.name} -> ${this.rhs.map(({name}) => name).join(' ')}), dot: ${this.dot}, peek: ${this.peek.name}`);
  }

  get_str() {
    return `Rule(${this.lhs.name} -> ${this.rhs.map(({name}) => name).join(' ')}), dot: ${this.dot}, peek: ${this.peek.name}`;
  }

  get_beta_symbols() {
    return this.rule.rhs.slice(this.dot);
  }

  get_next_item() {
    if (!this.is_complete) {
      const { rule, dot, peek } = this;
      return new Item({ rule, dot: dot + 1, peek });
    }
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
    return this.rule.rhs[this.dot];
  }
}

let next_state_id = 1;
const state_cache = {};

class State {
  constructor({items, items_id}) {
    this.id = next_state_id++;
    this.items = items;
    this.goto_actions = {};
    this.items_id = items_id;
  }

  add_goto(symbol, state) {
    this.goto_actions[symbol.id] = this.goto_actions[symbol.id] || [];
    this.goto_actions[symbol.id].push(state.id);
  }

  static get({items}) {
    const items_id = items
      .map((i) => `${i.rule.id}_${i.dot}_${i.peek.id}`)
      .sort()
      .join('_');

    if (state_cache[items_id]) {
      return state_cache[items_id];
    }

    const state = new State({items, items_id});
    state_cache[items_id] = state;
    return state;
  }
}

class StateCollection {
  constructor({states}) {
    this.states = states;
  }

  to_json() {
    return JSON.stringify(this.states);
  }
}

class Grammar {
  static assert_has_starting_rule({rules}) {
    assert(rules.filter((r) => r.lhs instanceof Top).length === 1);
  }

  static assert_all_tokens_used({rules, tokens}) {
    Object.keys(tokens).map((n) => tokens[n]).forEach((token) => {
      const len = rules.filter((r) => r.contains(token)).length;
      assert(len > 0, `token '${token.name}' is used in a rule`);
    });
  }

  static assert_all_reductions_defined({rules, symbols, epsilon}) {
    Object.keys(symbols).forEach((name) => {
      if (name === epsilon) {
        return;
      }
      if (symbols[name] instanceof Reduction) {
        const defs = rules.filter((rule) => {
          return rule.lhs.name === name;
        });
        assert(defs.length > 0, `${name} has a definition`);
      }
    });
  }

  constructor({ rules, tokens, symbols, epsilon }) {
    this.rules = rules;
    this.tokens = tokens;
    this.epsilon = epsilon;
    this.symbols = symbols;
    Grammar.assert_has_starting_rule(this);
    Grammar.assert_all_tokens_used(this);
    Grammar.assert_all_reductions_defined(this);
    this.top = rules.filter((r) => r.lhs instanceof Top)[0];
    this.break = new Break();
    this.follow_sets = {};
    this.first_sets = {};
    this.gather_empties();
  }

  gather_empties() {
    this.empties = this.rules.filter((r) => {
      return r.rhs.length === 0 || r.rhs[0] instanceof Epsilon;
    }).map((r) => r.lhs);
  }

  print() {
    console.log('tokens =', Object.keys(this.tokens).join(' '));
    this.rules.forEach((r) => {
      r.print();
    });
  }

  get_str() {
    let str = '';
    str += 'tokens = ' + Object.keys(this.tokens).join(' ');
    str += '  ' + this.rules.map((r) => r.get_str()).join('\n  ');
  }

  get_starting_items() {
    const result = [];
    const follow = this.get_follow_set(this.top.lhs);
    follow.forEach((f) => {
      result.push(new Item({
        rule: this.top,
        dot: 0,
        peek: f
      }));
    });
    return result;
  }

  get_follow_set(symbol, result = [], taboo = []) {
    if (taboo.indexOf(symbol.id) !== -1) return;
    taboo.push(symbol.id);
    if (this.follow_sets[symbol.name]) return this.follow_sets[symbol.name];
    if (symbol instanceof Top) {
      result.push(this.break);
      this.get_first_set(symbol).forEach((f) => result.push(f));
    } else if (symbol instanceof Symbol) {
      const by_rhs = this.rules.forEach((r) => {
        const dot = r.rhs.map(({id}) => id).indexOf(symbol.id);
        if (dot === -1) {
          return;
        } else if (dot < r.rhs.length - 1) {
          const first = this.get_first_set_sequence(r.rhs.slice(dot + 1));
          first.forEach((f) => this.add_unique(f, result));
        } else {
          this.get_follow_set(r.lhs, result, taboo);
        }
      });
    }
    this.follow_sets[symbol.name] = result;
    return result;
  }

  add_unique(symbol, list) {
    if (!list.filter((s) => s.id === symbol.id).length) {
      list.push(symbol);
    }
  }

  is_empty(symbol) {
    if (symbol instanceof Epsilon) return true;
    const is_empty = this.empties.filter((e) => {
      return e.id === symbol.id
    }).length > 0;
    return is_empty;
  }

  get_first_set_sequence(symbols) {
    const result = [];
    for (let i = 0; i < symbols.length; ++i) {
      const add = this.get_first_set(symbols[i]);
      const without_break = add.filter((s) => s.name !== Break.name);
      without_break.forEach((s) => this.add_unique(s, result));
      if (without_break.length === add.length) {
        break;
      }
    }
    return result;
  }

  get_first_set(symbol, result = [], taboo = []) {
    if (taboo.indexOf(symbol.id) !== -1) {
      return result;
    }
    taboo.push(symbol.id);
    if (this.first_sets[symbol.name]) {
      this.first_sets[symbol.name].forEach((s) => this.add_unique(s, result));
      return result;
    }
    if (symbol instanceof Reduction) {
      const rules = this.rules.filter((r) => r.lhs.id === symbol.id);
      rules.forEach((rule) => {
        for (let i = 0; i < rule.rhs.length; ++i) {
          this.get_first_set(rule.rhs[i], result, taboo);
          if (!this.is_empty(rule.rhs[i])) {
            break;
          }
        }
      });
    } else if (symbol instanceof Token) {
      this.add_unique(symbol, result);
    } else if (symbol instanceof Epsilon) {
      this.add_unique(symbol, result);
    }
    this.first_sets[symbol.name] = result;
    return result;
  }

  get_closure(items) {
    const todo = items.concat([]);
    const done = [];
    const state_items = [];
    while (todo.length) {
      const item = todo.pop();
      const item_id = `${item.rule.id}_${item.dot}_${item.peek.id}`;
      if (done.indexOf(item_id) !== -1) {
        continue;
      }
      done.push(item_id);
      state_items.push(item);
      if (item.is_complete) {
        continue;
      }
      item.get_beta_symbols().concat(item.peek).forEach((peek) => {
        this.rules.filter(({lhs}) => lhs.id === peek.id).forEach((rule) => {
          todo.push(new Item({rule, dot: 0, peek}));
        });
      });
    }

    return State.get({items: state_items});
  }

  get_goto(state, symbol) {
    const items = [];
    state.items.forEach((item) => {
      if (item.corner_symbol && item.corner_symbol.id === symbol.id) {
        const next = item.get_next_item();
        if (next) {
          items.push(next);
        }
      }
    });

    if (items.length) {
      return this.get_closure(items);
    }
  }

  get_state_table() {
    const result = [];
    const start = this.get_starting_items();
    const todo = [this.get_closure(start)];
    const done = [];
    const symbols_array = Object.keys(this.symbols).map((k) => this.symbols[k]);
    const symbols = [this.top.lhs, this.break].concat(symbols_array);

    while(todo.length) {
      const state = todo.pop();
      if (done.indexOf(state.items_id) > -1) {
        continue;
      }

      if (result.filter((s) => s.id === state.id).length > 0) {
        continue;
      }

      result.push(state);
      done.push(state.items_id);
      symbols.forEach((s) => {
        const goto_ = this.get_goto(state, s);
        if (!goto_) return;
        state.add_goto(s, goto_);

        // add to todo if state has not been completed
        if (done.indexOf(goto_.items_id) === -1) {
          todo.push(goto_);
        }
      });
    }

    return new StateCollection({ states: result });
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
              if (epsilon && part_name === epsilon) {
                symbols[part_name] = new Epsilon();
              } else {
                symbols[part_name] = new Reduction({ name: part_name });
                reductions[part_name] = symbols[part_name];
              }
            }
            return symbols[part_name]
          })
        }));
      }
    });

    return new Grammar({
      rules,
      tokens,
      epsilon,
      symbols
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
  Grammar,
  State,
  StateCollection
};
