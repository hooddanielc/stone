import React, {Component} from 'react';
import ReactDOM from 'react-dom';
import './index.scss';
import Explorer from './Explorer';

import json from '../../test/fixtures/pets.json';

const el = document.createElement('div');
document.body.appendChild(el);
ReactDOM.render(<Explorer grammar={json}/>, el);
