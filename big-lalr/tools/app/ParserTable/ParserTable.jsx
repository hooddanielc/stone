import React, {Component} from 'react';
import RulesTable from '../RulesTable';
import Form from 'muicss/lib/react/form';
import Input from 'muicss/lib/react/input';
import Button from 'muicss/lib/react/button';
import s from './ParserTable.scss';

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

  static get defaultProps() {
    return {
      offset: 0,
      limit: 20
    };
  }

  constructor(props) {
    super(props);
    this.offset = props.offset;
    this.state = {
      offset: props.offset,
      dirtyoffset: props.offset,
      limit: props.limit
    };
  }

  render_header() {
    const {tokens, reductions} = this.props.grammar;
    const header_cols = ['state']
      .concat(Object.keys(tokens).map((k) => k))
      .concat(Object.keys(reductions).map((k) => k));
    return (
      <thead>
        <tr>
          {header_cols.map((col, i) => (<td key={`head_row_${i}`}>{col}</td>))}
        </tr>
      </thead>
    );
  }

  showAction(action) {
    const {rules} = this.props.grammar;
    if (action.type === 'reduce') {
      console.log('reduce', rules.filter(({id}) => id === action.rule)[0]);
    } else if (action.type === 'shift') {
      console.log('shift', action);
    }
  }

  showTransition(transition) {
    console.log('show transition', transition);
  }

  render_row(action) {
    const {tokens, reductions} = this.props.grammar;
    const row = [];
    row.push(`s${action.state}`);
    Object.keys(tokens).forEach((t) => {
      if (action.actions && action.actions[t]) {
        row.push(
          <button onClick={() => this.showAction(action.actions[t])}>
            {action.actions[t].label}
          </button>
        );
      } else {
        row.push('');
      }
    });
    Object.keys(reductions).forEach((t) => {
      if (action.transition && action.transition[t]) {
        row.push(
          <button onClick={() => this.showTransition(action.transition[t])}>
            {action.transition[t].label}
          </button>
        );
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
    const result = [];
    const {actions} = this.props.grammar;
    const {limit, offset} = this.state;
    for (let i = offset; i < offset + limit; ++i) {
      if (!actions[i]) break;
      result.push(this.render_row(actions[i]));
    }

    if (!result.length) {
      return <p>End</p>;
    }

    return result;
  }

  submitForm(e) {
    e.preventDefault();
    if (isNaN(this.state.dirtyoffset)) {
      this.setState({ error: 'offset must be a number' });
      return;
    }
    this.setState({
      offset: parseInt(this.state.dirtyoffset)
    });
  }

  onInputChange(name) {
    return (e) => {
      const newState = {};
      newState['dirty' + name] = e.target.value;
      this.setState(newState);
    };
  }

  nextPage(e) {
    e.preventDefault();
    let {offset, limit} = this.state;
    offset += limit;
    this.setState({offset, dirtyoffset: offset});
  }

  prevPage(e) {
    e.preventDefault();
    let {offset, limit} = this.state;
    offset -= limit;
    this.setState({offset, dirtyoffset: offset});
  }

  render() {
    return (
      <div>
        <Form className={s.Controls} inline={true} onSubmit={this.submitForm.bind(this)}>
          <span>offset</span>
          &nbsp;
          <input type="text"
            className={s.CenterInput}
            size={5}
            value={this.state.dirtyoffset}
            onChange={this.onInputChange('offset')}
          />
          &nbsp;
          <span>of</span>
          &nbsp;
          <b>{this.props.grammar.actions.length}</b>
          &nbsp;
          <button>submit</button>
          <span>or</span>
          <button onClick={this.prevPage.bind(this)}>prev</button>
          <button onClick={this.nextPage.bind(this)}>next</button>
        </Form>
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