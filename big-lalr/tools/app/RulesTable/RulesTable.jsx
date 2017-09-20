import React, {Component} from 'react';

const Rule = ({rule}) => {
  if (!rule.rhs) {
    return (
      <div>
        {rule.lhs} {`→`} <span>&epsilon;</span>
      </div>
    );
  }

  let {lhs, rhs} = rule;

  if (lhs === 'TOP') {
    lhs = <span>&Omega;</span>
  }

  return (
    <div>
      {lhs} {`→`} «{rhs ? rhs.join(`» «`) : ''}»
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
            <th width="30px">Rule</th>
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
