import React, {Component} from 'react';
import s from './HighlightedCode.scss';
import hljs from 'highlight.js';

export default class extends Component {
  static get defaultProps() {
    return {
      src: `
        #include <iostream>

        int main(int, char*[]) {
          return 0;
        }
      `
    };
  }

  componentDidMount() {
    hljs.highlightBlock(this.code_el);
  }

  render() {
    return (
      <pre>
        <code ref={(el) => { this.code_el = el; }} className="cpp">
          {this.props.src}
        </code>
      </pre>
    );
  }
}
