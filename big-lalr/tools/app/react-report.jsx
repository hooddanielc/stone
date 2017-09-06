import React, {Component} from 'react';
import ReactDOM from 'react-dom';
import './index.scss';
import Explorer from './Explorer';

const el = document.createElement('div');
document.body.appendChild(el);
ReactDOM.render(<Explorer/>, el);
