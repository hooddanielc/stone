import React, {Component} from 'react';
import RulesTable from '../RulesTable';
import ParserTable from '../ParserTable';

export default class extends Component {
  render() {
    const {rules} = this.props.grammar;
    return (
      <div>
        <RulesTable rules={rules} />
        <ParserTable grammar={this.props.grammar} />
      </div>
    );
  }
}
