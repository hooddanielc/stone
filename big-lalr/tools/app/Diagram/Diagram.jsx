import React, {Component} from 'react';
import s from './Diagram.scss';
import Viz from 'viz.js';

export default class extends Component {
  constructor(props) {
    super(props);
    try {
      this.viz = Viz(this.props.grammar.dot);
    } catch (e) {
      this.viz = "<h1>Error: Graph Viz file is too big :(</h1>";
    }
  }

  render() {
    return (
      <div dangerouslySetInnerHTML={{__html: this.viz}}>
      </div>
    );
  }
}
