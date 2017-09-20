import React, {Component} from 'react';

import {
  BrowserRouter as Router,
  Route,
  Link
} from 'react-router-dom';

import Appbar from 'muicss/lib/react/appbar';
import Panel from 'muicss/lib/react/panel';
import Button from 'muicss/lib/react/button';
import Diagram from '../Diagram';
import RulesTable from '../RulesTable';
import ParserTable from '../ParserTable';
import Code from '../Code';
import s from './Explorer.scss';

class App extends Component {
  static get defaultProps() {
    return {
      section: 'Home'
    };
  }

  constructor(props) {
    super(props);
    console.log(this);
  }

  getButtonColor(path) {
    if (window.location.pathname === path) {
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
          <p>Everything Went Horribly Right</p>
        </Panel>
      </div>
    );
  }

  renderCode() {
    return (
      <Code grammar={this.props.grammar} />
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
          <Link className={s.HeaderLink} to="/">
            <Button color={this.getButtonColor("/")}>Stats</Button>
          </Link>
          <Link className={s.HeaderLink} to="/parse-table">
            <Button color={this.getButtonColor("/parse-table")}>Parse Table</Button>
          </Link>
          <Link className={s.HeaderLink} to="/diagram">
            <Button color={this.getButtonColor("/diagram")}>Diagram</Button>
          </Link>
          <Link className={s.HeaderLink} to="/code">
            <Button color={this.getButtonColor("/code")}>Code</Button>
          </Link>
        </div>
      </Appbar>
    );
  }

  render() {
    return (
      <div>
        {this.renderHeader()}
        <Route exact path="/" component={this.renderHome.bind(this)}/>
        <Route path="/parse-table" component={this.renderParseTable.bind(this)}/>
        <Route path="/diagram" component={this.renderDiagram.bind(this)}/>
        <Route path="/code" component={this.renderCode.bind(this)}/>
      </div>
    );
  }
}

export default (props) => <Router><App {...props}/></Router>;
