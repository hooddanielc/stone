import React, {Component} from 'react';
import RulesTable from '../RulesTable';

const Item = ({item}) => {
  const {rule, dot, peek} = item;

  const token_list = rule.rhs.map(({name}, i) => {
    if (dot === i) {
      return (
        <span>
          <span>.</span> <span>«{name}»</span>
        </span>
      )
    }

    return (
      <span>
        «{name}»
      </span>
    );
  });

  return (
    <div>
      {rule.lhs.name} {`→`} {token_list}, «{peek.name}»
    </div>
  );
}

export default class extends Component {
  constructor(props) {
    super(props);
    const {
      states,
      rules,
      tokens,
      symbols
    } = props.grammar;
    this.states = states;
    this.rules = rules;
    this.tokens = Object.keys(tokens).map(k=>tokens[k]);
    this.symbols = Object.keys(symbols).map(k=>symbols[k]);
    this.reductions = this.symbols.filter(s=>!s.terminal);
    this.init_table();
  }

  init_table() {
    console.log(this.tokens);
    console.log('initialize table');
  }

  render_header() {
    const header_cols = ['state']
      .concat(this.tokens.map(t=>t.name))
      .concat(this.reductions.map(t=>t.name))
      .concat(['Items']);
    return (
      <thead>
        <tr>
          {header_cols.map((col, i) => (<td key={`head_row_${i}`}>{col}</td>))}
        </tr>
      </thead>
    );
  }

  render_row(idx) {
    if (!this.states[idx]) return;
    const {goto_actions, items} = this.states[idx];
    const row = [];
    row.push(`s${idx}`);
    this.tokens.forEach((t) => {
      if (goto_actions[t.id]) {
        row.push(`s${goto_actions[t.id][0]}`);
      } else {
        row.push('');
      }
    });
    this.reductions.forEach((t) => {
      if (goto_actions[t.id]) {
        row.push(`s${t.id}`);
      } else {
        row.push('');
      }
    });

    row.push(items.map((i, id) => <Item key={`s${idx}_item_${id}`} item={i}/>));

    return (
      <tr key={`${idx}_state_table_row`}>
        {row.map((r, i) => <td key={`state_row_${idx}_${i}`}>{r}</td>)}
      </tr>
    )
  }

  render() {
    return (
      <div>
        <div>
          <RulesTable rules={this.props.grammar.rules} />
        </div>
        <div>
          <table className="mui-table mui-table--bordered">
            {this.render_header()}
            <tbody>
              {this.states.map((s, i)=>this.render_row(i))}
            </tbody>
          </table>
        </div>
      </div>
    );
  }
}