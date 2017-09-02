/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId]) {
/******/ 			return installedModules[moduleId].exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			i: moduleId,
/******/ 			l: false,
/******/ 			exports: {}
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.l = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// define getter function for harmony exports
/******/ 	__webpack_require__.d = function(exports, name, getter) {
/******/ 		if(!__webpack_require__.o(exports, name)) {
/******/ 			Object.defineProperty(exports, name, {
/******/ 				configurable: false,
/******/ 				enumerable: true,
/******/ 				get: getter
/******/ 			});
/******/ 		}
/******/ 	};
/******/
/******/ 	// getDefaultExport function for compatibility with non-harmony modules
/******/ 	__webpack_require__.n = function(module) {
/******/ 		var getter = module && module.__esModule ?
/******/ 			function getDefault() { return module['default']; } :
/******/ 			function getModuleExports() { return module; };
/******/ 		__webpack_require__.d(getter, 'a', getter);
/******/ 		return getter;
/******/ 	};
/******/
/******/ 	// Object.prototype.hasOwnProperty.call
/******/ 	__webpack_require__.o = function(object, property) { return Object.prototype.hasOwnProperty.call(object, property); };
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(__webpack_require__.s = 2);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */,
/* 1 */
/***/ (function(module, exports) {

module.exports = require("fs");

/***/ }),
/* 2 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.StateCollection = exports.State = exports.Grammar = exports.Rule = exports.Item = exports.Reduction = exports.Token = exports.Symbol = undefined;

var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

var _fs = __webpack_require__(1);

var _fs2 = _interopRequireDefault(_fs);

var _assert = __webpack_require__(3);

var _assert2 = _interopRequireDefault(_assert);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

var next_id = 1;
var symbol_ids = {};

var _Symbol = function _Symbol(_ref) {
  var name = _ref.name;

  _classCallCheck(this, _Symbol);

  this.name = name;

  if (!symbol_ids[name]) {
    symbol_ids[name] = next_id++;
  }

  this.id = symbol_ids[name];
  (0, _assert2.default)(this.name, 'symbol must have a name');
  (0, _assert2.default)(!/\s+/g.exec(this.name), 'no spaces in name');
  var match = /([A-Z]|[a-z]|[0-9]|_)+$/.exec(this.name);
  (0, _assert2.default)(match && match.index === 0, 'valid name');
};

var token_names = [];
var reduction_names = [];

var Token = function (_Symbol2) {
  _inherits(Token, _Symbol2);

  function Token(_ref2) {
    var name = _ref2.name;

    _classCallCheck(this, Token);

    var _this = _possibleConstructorReturn(this, (Token.__proto__ || Object.getPrototypeOf(Token)).call(this, { name: name }));

    _this.terminal = true;
    (0, _assert2.default)(reduction_names.indexOf(name) === -1, 'token can not be a reduction');
    if (token_names.indexOf(name) === -1) {
      token_names.push(name);
    }
    return _this;
  }

  _createClass(Token, [{
    key: 'print',
    value: function print() {
      console.log('Token(' + this.name + ')');
    }
  }]);

  return Token;
}(_Symbol);

var Reduction = function (_Symbol3) {
  _inherits(Reduction, _Symbol3);

  function Reduction(_ref3) {
    var name = _ref3.name;

    _classCallCheck(this, Reduction);

    var _this2 = _possibleConstructorReturn(this, (Reduction.__proto__ || Object.getPrototypeOf(Reduction)).call(this, { name: name }));

    _this2.terminal = false;
    (0, _assert2.default)(token_names.indexOf(name) === -1, 'reduction can not be a reduction');
    if (reduction_names.indexOf(name) === -1) {
      reduction_names.push(name);
    }
    return _this2;
  }

  _createClass(Reduction, [{
    key: 'print',
    value: function print() {
      console.log('Reduction(' + this.name + ')');
    }
  }]);

  return Reduction;
}(_Symbol);

var Break = function (_Symbol4) {
  _inherits(Break, _Symbol4);

  function Break() {
    _classCallCheck(this, Break);

    return _possibleConstructorReturn(this, (Break.__proto__ || Object.getPrototypeOf(Break)).call(this, { name: Break.name }));
  }

  _createClass(Break, [{
    key: 'print',
    value: function print() {
      console.log(Break.name);
    }
  }], [{
    key: 'name',
    get: function get() {
      return 'BREAK';
    }
  }]);

  return Break;
}(_Symbol);

var Epsilon = function (_Symbol5) {
  _inherits(Epsilon, _Symbol5);

  function Epsilon() {
    _classCallCheck(this, Epsilon);

    return _possibleConstructorReturn(this, (Epsilon.__proto__ || Object.getPrototypeOf(Epsilon)).call(this, { name: Epsilon.name }));
  }

  _createClass(Epsilon, [{
    key: 'print',
    value: function print() {
      console.log(Epsilon.name);
    }
  }], [{
    key: 'name',
    get: function get() {
      return 'EPSILON';
    }
  }]);

  return Epsilon;
}(_Symbol);

var Top = function (_Reduction) {
  _inherits(Top, _Reduction);

  function Top() {
    _classCallCheck(this, Top);

    return _possibleConstructorReturn(this, (Top.__proto__ || Object.getPrototypeOf(Top)).call(this, { name: Top.name }));
  }

  _createClass(Top, [{
    key: 'print',
    value: function print() {
      console.log(Top.name);
    }
  }], [{
    key: 'name',
    get: function get() {
      return 'TOP';
    }
  }]);

  return Top;
}(Reduction);

var Rule = function () {
  function Rule(_ref4) {
    var rhs = _ref4.rhs,
        lhs = _ref4.lhs,
        _ref4$timeout = _ref4.timeout,
        timeout = _ref4$timeout === undefined ? 0 : _ref4$timeout;

    _classCallCheck(this, Rule);

    this.lhs = lhs;
    this.rhs = rhs || [];
    this.timeout = timeout;
    (0, _assert2.default)(this.lhs, 'Rule requires a left hand side');
    (0, _assert2.default)(this.rhs instanceof Array, 'Right is always an array');
    (0, _assert2.default)(this.lhs instanceof Reduction, 'Left is always reduction');
    this.rhs.forEach(function (sym) {
      return (0, _assert2.default)(sym instanceof Token || sym instanceof Reduction || sym instanceof Epsilon);
    });

    if (lhs instanceof Top) {
      (0, _assert2.default)(rhs.length === 1, 'Omega rule has one token on right side');
    }

    this.id = next_id++;
  }

  _createClass(Rule, [{
    key: 'contains',
    value: function contains(token) {
      return this.rhs.filter(function (s) {
        return s.id === token.id;
      }).length > 0;
    }
  }, {
    key: 'print',
    value: function print() {
      console.log('Rule(' + this.lhs.name + ' -> ' + this.rhs.map(function (_ref5) {
        var name = _ref5.name;
        return name;
      }).join(' ') + ')');
    }
  }, {
    key: 'get_str',
    value: function get_str() {
      return this.lhs.name + ' -> ' + this.rhs.map(function (_ref6) {
        var name = _ref6.name;
        return name;
      }).join(' ');
    }
  }, {
    key: 'length',
    get: function get() {
      return this.rhs.length;
    }
  }]);

  return Rule;
}();

var Item = function () {
  function Item(_ref7) {
    var rule = _ref7.rule,
        dot = _ref7.dot,
        peek = _ref7.peek;

    _classCallCheck(this, Item);

    this.rule = rule;
    this.dot = dot;
    this.peek = peek;
    (0, _assert2.default)(dot >= 0 && dot <= rule.length, 'dot is within rule');
  }

  _createClass(Item, [{
    key: 'print',
    value: function print() {
      console.log('Rule(' + this.lhs.name + ' -> ' + this.rhs.map(function (_ref8) {
        var name = _ref8.name;
        return name;
      }).join(' ') + '), dot: ' + this.dot + ', peek: ' + this.peek.name);
    }
  }, {
    key: 'get_str',
    value: function get_str() {
      return 'Rule(' + this.lhs.name + ' -> ' + this.rhs.map(function (_ref9) {
        var name = _ref9.name;
        return name;
      }).join(' ') + '), dot: ' + this.dot + ', peek: ' + this.peek.name;
    }
  }, {
    key: 'get_beta_symbols',
    value: function get_beta_symbols() {
      return this.rule.rhs.slice(this.dot);
    }
  }, {
    key: 'get_next_item',
    value: function get_next_item() {
      if (!this.is_complete) {
        var rule = this.rule,
            dot = this.dot,
            peek = this.peek;

        return new Item({ rule: rule, dot: dot + 1, peek: peek });
      }
    }
  }, {
    key: 'rhs',
    get: function get() {
      return this.rule.rhs;
    }
  }, {
    key: 'lhs',
    get: function get() {
      return this.rule.lhs;
    }
  }, {
    key: 'is_complete',
    get: function get() {
      return this.rule.length === this.dot;
    }
  }, {
    key: 'corner_symbol',
    get: function get() {
      return this.rule.rhs[this.dot];
    }
  }]);

  return Item;
}();

var next_state_id = 1;
var state_cache = {};

var State = function () {
  function State(_ref10) {
    var items = _ref10.items,
        items_id = _ref10.items_id;

    _classCallCheck(this, State);

    this.id = next_state_id++;
    this.items = items;
    this.goto_actions = {};
    this.items_id = items_id;
  }

  _createClass(State, [{
    key: 'add_goto',
    value: function add_goto(symbol, state) {
      this.goto_actions[symbol.id] = this.goto_actions[symbol.id] || [];
      this.goto_actions[symbol.id].push(state.id);
    }
  }], [{
    key: 'get',
    value: function get(_ref11) {
      var items = _ref11.items;

      var items_id = items.map(function (i) {
        return i.rule.id + '_' + i.dot + '_' + i.peek.id;
      }).sort().join('_');

      if (state_cache[items_id]) {
        return state_cache[items_id];
      }

      var state = new State({ items: items, items_id: items_id });
      state_cache[items_id] = state;
      return state;
    }
  }]);

  return State;
}();

var StateCollection = function () {
  function StateCollection(_ref12) {
    var states = _ref12.states;

    _classCallCheck(this, StateCollection);

    this.states = states;
  }

  _createClass(StateCollection, [{
    key: 'to_json',
    value: function to_json() {
      return JSON.stringify(this.states);
    }
  }]);

  return StateCollection;
}();

var Grammar = function () {
  _createClass(Grammar, null, [{
    key: 'assert_has_starting_rule',
    value: function assert_has_starting_rule(_ref13) {
      var rules = _ref13.rules;

      (0, _assert2.default)(rules.filter(function (r) {
        return r.lhs instanceof Top;
      }).length === 1);
    }
  }, {
    key: 'assert_all_tokens_used',
    value: function assert_all_tokens_used(_ref14) {
      var rules = _ref14.rules,
          tokens = _ref14.tokens;

      Object.keys(tokens).map(function (n) {
        return tokens[n];
      }).forEach(function (token) {
        var len = rules.filter(function (r) {
          return r.contains(token);
        }).length;
        (0, _assert2.default)(len > 0, 'token \'' + token.name + '\' is used in a rule');
      });
    }
  }, {
    key: 'assert_all_reductions_defined',
    value: function assert_all_reductions_defined(_ref15) {
      var rules = _ref15.rules,
          symbols = _ref15.symbols,
          epsilon = _ref15.epsilon;

      Object.keys(symbols).forEach(function (name) {
        if (name === epsilon) {
          return;
        }
        if (symbols[name] instanceof Reduction) {
          var defs = rules.filter(function (rule) {
            return rule.lhs.name === name;
          });
          (0, _assert2.default)(defs.length > 0, name + ' has a definition');
        }
      });
    }
  }]);

  function Grammar(_ref16) {
    var rules = _ref16.rules,
        tokens = _ref16.tokens,
        symbols = _ref16.symbols,
        epsilon = _ref16.epsilon;

    _classCallCheck(this, Grammar);

    this.rules = rules;
    this.tokens = tokens;
    this.epsilon = epsilon;
    this.symbols = symbols;
    Grammar.assert_has_starting_rule(this);
    Grammar.assert_all_tokens_used(this);
    Grammar.assert_all_reductions_defined(this);
    this.top = rules.filter(function (r) {
      return r.lhs instanceof Top;
    })[0];
    this.break = new Break();
    this.follow_sets = {};
    this.first_sets = {};
    this.gather_empties();
  }

  _createClass(Grammar, [{
    key: 'gather_empties',
    value: function gather_empties() {
      this.empties = this.rules.filter(function (r) {
        return r.rhs.length === 0 || r.rhs[0] instanceof Epsilon;
      }).map(function (r) {
        return r.lhs;
      });
    }
  }, {
    key: 'print',
    value: function print() {
      console.log('tokens =', Object.keys(this.tokens).join(' '));
      this.rules.forEach(function (r) {
        r.print();
      });
    }
  }, {
    key: 'get_str',
    value: function get_str() {
      var str = '';
      str += 'tokens = ' + Object.keys(this.tokens).join(' ');
      str += '  ' + this.rules.map(function (r) {
        return r.get_str();
      }).join('\n  ');
    }
  }, {
    key: 'get_starting_items',
    value: function get_starting_items() {
      var _this6 = this;

      var result = [];
      var follow = this.get_follow_set(this.top.lhs);
      follow.forEach(function (f) {
        result.push(new Item({
          rule: _this6.top,
          dot: 0,
          peek: f
        }));
      });
      return result;
    }
  }, {
    key: 'get_follow_set',
    value: function get_follow_set(symbol) {
      var _this7 = this;

      var result = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : [];
      var taboo = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : [];

      if (taboo.indexOf(symbol.id) !== -1) return;
      taboo.push(symbol.id);
      if (this.follow_sets[symbol.name]) return this.follow_sets[symbol.name];
      if (symbol instanceof Top) {
        result.push(this.break);
        this.get_first_set(symbol).forEach(function (f) {
          return result.push(f);
        });
      } else if (symbol instanceof _Symbol) {
        var by_rhs = this.rules.forEach(function (r) {
          var dot = r.rhs.map(function (_ref17) {
            var id = _ref17.id;
            return id;
          }).indexOf(symbol.id);
          if (dot === -1) {
            return;
          } else if (dot < r.rhs.length - 1) {
            var first = _this7.get_first_set_sequence(r.rhs.slice(dot + 1));
            first.forEach(function (f) {
              return _this7.add_unique(f, result);
            });
          } else {
            _this7.get_follow_set(r.lhs, result, taboo);
          }
        });
      }
      this.follow_sets[symbol.name] = result;
      return result;
    }
  }, {
    key: 'add_unique',
    value: function add_unique(symbol, list) {
      if (!list.filter(function (s) {
        return s.id === symbol.id;
      }).length) {
        list.push(symbol);
      }
    }
  }, {
    key: 'is_empty',
    value: function is_empty(symbol) {
      if (symbol instanceof Epsilon) return true;
      var is_empty = this.empties.filter(function (e) {
        return e.id === symbol.id;
      }).length > 0;
      return is_empty;
    }
  }, {
    key: 'get_first_set_sequence',
    value: function get_first_set_sequence(symbols) {
      var _this8 = this;

      var result = [];
      for (var i = 0; i < symbols.length; ++i) {
        var add = this.get_first_set(symbols[i]);
        var without_break = add.filter(function (s) {
          return s.name !== Break.name;
        });
        without_break.forEach(function (s) {
          return _this8.add_unique(s, result);
        });
        if (without_break.length === add.length) {
          break;
        }
      }
      return result;
    }
  }, {
    key: 'get_first_set',
    value: function get_first_set(symbol) {
      var _this9 = this;

      var result = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : [];
      var taboo = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : [];

      if (taboo.indexOf(symbol.id) !== -1) {
        return result;
      }
      taboo.push(symbol.id);
      if (this.first_sets[symbol.name]) {
        this.first_sets[symbol.name].forEach(function (s) {
          return _this9.add_unique(s, result);
        });
        return result;
      }
      if (symbol instanceof Reduction) {
        var rules = this.rules.filter(function (r) {
          return r.lhs.id === symbol.id;
        });
        rules.forEach(function (rule) {
          for (var i = 0; i < rule.rhs.length; ++i) {
            _this9.get_first_set(rule.rhs[i], result, taboo);
            if (!_this9.is_empty(rule.rhs[i])) {
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
  }, {
    key: 'get_closure',
    value: function get_closure(items) {
      var _this10 = this;

      var todo = items.concat([]);
      var done = [];
      var state_items = [];
      while (todo.length) {
        var item = todo.pop();
        var item_id = item.rule.id + '_' + item.dot + '_' + item.peek.id;
        if (done.indexOf(item_id) !== -1) {
          continue;
        }
        done.push(item_id);
        state_items.push(item);
        if (item.is_complete) {
          continue;
        }
        item.get_beta_symbols().concat(item.peek).forEach(function (peek) {
          _this10.rules.filter(function (_ref18) {
            var lhs = _ref18.lhs;
            return lhs.id === peek.id;
          }).forEach(function (rule) {
            todo.push(new Item({ rule: rule, dot: 0, peek: peek }));
          });
        });
      }

      return State.get({ items: state_items });
    }
  }, {
    key: 'get_goto',
    value: function get_goto(state, symbol) {
      var items = [];
      state.items.forEach(function (item) {
        if (item.corner_symbol && item.corner_symbol.id === symbol.id) {
          var next = item.get_next_item();
          if (next) {
            items.push(next);
          }
        }
      });

      if (items.length) {
        return this.get_closure(items);
      }
    }
  }, {
    key: 'get_state_table',
    value: function get_state_table() {
      var _this11 = this;

      var result = [];
      var start = this.get_starting_items();
      var todo = [this.get_closure(start)];
      var done = [];
      var symbols_array = Object.keys(this.symbols).map(function (k) {
        return _this11.symbols[k];
      });
      var symbols = [this.top.lhs, this.break].concat(symbols_array);

      var _loop = function _loop() {
        var state = todo.pop();
        if (done.indexOf(state.items_id) > -1) {
          return 'continue';
        }

        if (result.filter(function (s) {
          return s.id === state.id;
        }).length > 0) {
          return 'continue';
        }

        result.push(state);
        done.push(state.items_id);
        symbols.forEach(function (s) {
          var goto_ = _this11.get_goto(state, s);
          if (!goto_) return;
          state.add_goto(s, goto_);

          // add to todo if state has not been completed
          if (done.indexOf(goto_.items_id) === -1) {
            todo.push(goto_);
          }
        });
      };

      while (todo.length) {
        var _ret = _loop();

        if (_ret === 'continue') continue;
      }

      return new StateCollection({ states: result });
    }
  }], [{
    key: 'from_str',
    value: function from_str(str) {
      var rules = [];
      var tokens = {};
      var symbols = {};
      var reductions = {};
      var epsilon = null;
      var lines = str.split('\n');
      (0, _assert2.default)(lines[0].substring(0, 6) === '/token', 'first line must declare tokens');

      lines.forEach(function (line) {
        var trimmed = line.trim();
        var parts = line.split(/\s+/);

        if (parts[0] === '/token') {
          parts.shift();
          parts.forEach(function (part) {
            if (part !== '->') {
              tokens[part] = new Token({ name: part });
              symbols[part] = tokens[part];
            }
          });
        } else if (parts[0] === '/top') {
          parts.shift();
          (0, _assert2.default)(parts[0] === '->', '/top has an arrow to the right');
          parts.shift();
          (0, _assert2.default)(parts.length === 1);
          symbols[parts[0]] = symbols[parts[0]] || new Reduction({ name: parts[0] });
          reductions[parts[0]] = symbols[parts[0]];
          rules.push(new Rule({
            lhs: new Top(),
            rhs: [symbols[parts[0]]]
          }));
        } else if (parts[0] === '/epsilon') {
          parts.shift();
          (0, _assert2.default)(parts[0] === '->', '/epsilon has an arrow to the right');
          parts.shift();
          epsilon = parts[0];
        } else if (parts.length && parts[0]) {
          var name = parts.shift();
          (0, _assert2.default)(parts[0] === '->', 'reduction has an arrow to the right');
          parts.shift();

          if (!symbols[name]) {
            symbols[name] = new Reduction({ name: name });
            reductions[name] = symbols[name];
          }

          rules.push(new Rule({
            lhs: symbols[name],
            rhs: parts.map(function (part_name) {
              if (!symbols[part_name]) {
                if (epsilon && part_name === epsilon) {
                  symbols[part_name] = new Epsilon();
                } else {
                  symbols[part_name] = new Reduction({ name: part_name });
                  reductions[part_name] = symbols[part_name];
                }
              }
              return symbols[part_name];
            })
          }));
        }
      });

      return new Grammar({
        rules: rules,
        tokens: tokens,
        epsilon: epsilon,
        symbols: symbols
      });
    }
  }, {
    key: 'from_file',
    value: function from_file(file_path) {
      return this.from_str(_fs2.default.readFileSync(file_path, 'utf8'));
    }
  }]);

  return Grammar;
}();

exports.Symbol = _Symbol;
exports.Token = Token;
exports.Reduction = Reduction;
exports.Item = Item;
exports.Rule = Rule;
exports.Grammar = Grammar;
exports.State = State;
exports.StateCollection = StateCollection;
exports.default = {
  Symbol: _Symbol,
  Token: Token,
  Reduction: Reduction,
  Item: Item,
  Rule: Rule,
  Grammar: Grammar,
  State: State,
  StateCollection: StateCollection
};

/***/ }),
/* 3 */
/***/ (function(module, exports) {

module.exports = require("assert");

/***/ })
/******/ ]);