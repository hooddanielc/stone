import React, {Component} from 'react';

const Rule = ({rule}) => {
  return (
    <div>
      {rule.lhs.name} {`→`} «{rule.rhs.map(t => t.name).join('» «')}»
    </div>
  )
}

export default class extends Component {
  render() {
    const {rules} = this.props;
    return (
      <table className="mui-table mui-table--bordered">
        <thead>
          <tr>
            <th>Rule</th>
            <th>Syntax</th>
          </tr>
        </thead>
        <tbody>
          {rules.map((rule, idx) => {
            return (
              <tr key={`rule_${idx}`}>
                <td>r{idx}</td>
                <td><Rule rule={rule}/></td>
              </tr>
            );
          })}
        </tbody>
      </table>
    );
  }
}
