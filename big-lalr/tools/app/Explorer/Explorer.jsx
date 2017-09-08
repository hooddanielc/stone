import React, {Component} from 'react';
import Appbar from 'muicss/lib/react/appbar';
import Panel from 'muicss/lib/react/panel';
import Button from 'muicss/lib/react/button';
import Diagram from '../Diagram';
import RulesTable from '../RulesTable';
import ParserTable from '../ParserTable';
import s from './Explorer.scss';

export default class extends Component {
  static get defaultProps() {
    return {
      section: 'Home'
    };
  }

  constructor(props) {
    super(props);
    console.log(props);
    this.state = {
      section: props.section
    };
  }

  getButtonColor(name) {
    const {section} = this.state;
    if (section === name) {
      return;
    }

    return 'accent';
  }

  renderHome() {
    return (
      <div className={s.ContentWrapper}>
        <h1>Stats</h1>
        <h2>Rules</h2>
        <Panel>
          <RulesTable rules={this.props.grammar.rules} />
        </Panel>
      </div>
    );
  }

  renderDiagram() {
    return (
      <div className={s.ContentWrapper}>
        <h1>Diagram</h1>
        <Panel>
          <Diagram grammar={this.props.grammar} />
        </Panel>
      </div>
    );
  }

  renderMissing() {
    return (
      <div className={s.ContentWrapper}>
        <h2>404: Not Found</h2>
        <Panel>
          <p>Whoops! Something went wrong.</p>
        </Panel>
      </div>
    );
  }

  renderSection(section) {
    if (!this['render' + section]) {
      return this.renderMissing();
    } else {
      return this['render' + section]();
    }
  }

  changeSection(section) {
    return () => this.setState({ section });
  }

  renderParseTable() {
    return (
      <div className={s.ContentWrapper}>
        <h2>Action Table</h2>
        <Panel>
          <ParserTable grammar={this.props.grammar} />
        </Panel>
      </div>
    );
  }

  renderHeader() {
    return (
      <Appbar>
        <div className={s.HeaderWrapper}>
          <Button color={this.getButtonColor('Home')} onClick={this.changeSection('Home')}>Stats</Button>
          <Button color={this.getButtonColor('ParseTable')} onClick={this.changeSection('ParseTable')}>Parse Table</Button>
          <Button color={this.getButtonColor('Diagram')} onClick={this.changeSection('Diagram')}>Diagram</Button>
        </div>
      </Appbar>
    );
  }

  render() {
    return (
      <div>
        {this.renderHeader()}
        {this.renderSection(this.state.section)}
      </div>
    );
  }
}
