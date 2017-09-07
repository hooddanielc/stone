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

  render_header() {
    const {tokens, reductions} = this.props.grammar;
    const header_cols = ['state']
      .concat(Object.keys(tokens))
      .concat(Object.keys(reductions));
    return (
      <thead>
        <tr>
          {header_cols.map((col, i) => (<td key={`head_row_${i}`}>{col}</td>))}
        </tr>
      </thead>
    );
  }

  render_row(action) {
    const {tokens, reductions} = this.props.grammar;
    const row = [];
    row.push(`s${action.state}`);
    Object.keys(tokens).forEach((t) => {
      if (action.actions && action.actions[t]) {
        row.push(action.actions[t].label);
      } else {
        row.push('');
      }
    });
    Object.keys(reductions).forEach((t) => {
      if (action.transition && action.transition[t]) {
        row.push(action.transition[t].label);
      } else {
        row.push('');
      }
    });

    return (
      <tr key={`${action.state}_state_table_row`}>
        {row.map((r, i) => <td key={`${action.state}_state_table_column_${i}`}>{r}</td>)}
      </tr>
    )
  }

  render_actions() {
    return this.props.grammar.actions.map((a)=>this.render_row(a));
  }

  render() {
    return (
      <div>
        <div>
          <table className="mui-table mui-table--bordered">
            {this.render_header()}
            <tbody>
              {this.render_actions()}
            </tbody>
          </table>
        </div>
      </div>
    );
  }
}