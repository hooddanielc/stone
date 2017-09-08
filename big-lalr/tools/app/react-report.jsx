import React, {Component} from 'react';
import ReactDOM from 'react-dom';
import './index.scss';
import Explorer from './Explorer';

//import json from '../../test/fixtures/pets.json';
//import json from '../../../gliss/docs/glsl.json';

const json = JSON.parse(document.getElementById('json').innerHTML);

const el = document.createElement('div');
document.body.appendChild(el);
ReactDOM.render(<Explorer grammar={json}/>, el);
