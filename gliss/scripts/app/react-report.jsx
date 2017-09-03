import React, {Component} from 'react';
import ReactDOM from 'react-dom';
import { Item } from '../server/grammar';
import './index.scss';
import json from '../grammar/pets-preprocessed_4/grammar.json';
import ParserTable from './ParserTable';
const el = document.createElement('div');
document.body.appendChild(el);
ReactDOM.render(<ParserTable grammar={json}/>, el);
