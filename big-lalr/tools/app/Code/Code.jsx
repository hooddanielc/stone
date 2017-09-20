import React, {Component} from 'react';
import HighlightedCode from '../HighlightedCode';

import s from './Code.scss';
import hljs from 'highlight.js';


import {
  BrowserRouter as Router,
  Route,
  Link
} from 'react-router-dom';

export default class extends Component {

  constructor(props) {
    super(props);
    this.files = this.initFileList();
  }

  initFileList() {
    const files = [
      {path: 'tokens.h', src: this.props.grammar.cpp.tokens},
      {path: 'ast.h', src: this.props.grammar.cpp.ast_base}
    ];

    const {reductions} = this.props.grammar.cpp;

    Object.keys(reductions).forEach((key) => {
      files.push({path: `reductions/${key}.h`, src: reductions[key].join('\n\n')});
    });

    return files;
  }

  renderSelectedFile() {
    const SelectedCode = (file) => {
      return () => {
        return <HighlightedCode src={file.src}/>;
      }
    }

    let selected = '';
    return this.files.map(({path, src}) => {
      const actualPath = `/code/${path}`;
      return <Route key={actualPath} path={actualPath} component={SelectedCode({path, src})}/>
    }).concat([
      <Route key="/code" exact path="/code" component={SelectedCode(this.files[0])}/>
    ]);
  }

  renderSidebar() {
    return (
      <div className={s.Files}>
        <ul>
          {this.files.map(({path}) => {
            let selected = '';
            if (window.location.pathname === '/code') {
              if (path === 'tokens.h') {
                selected = s.Selected;
              }
            } else if (`/code/${path}` === window.location.pathname) {
              selected = s.Selected;
            }
            console.log();
            return (
              <li className={selected} key={path}>
                <p>
                  <Link to={`/code/${path}`}>{path}</Link>
                </p>  
              </li>
            );
          })}
        </ul>
      </div>
    )
  }

  render() {
    return (
      <div className={s.Code}>
        {this.renderSidebar()}
        {this.renderSelectedFile()}
      </div>
    );
  }
}
