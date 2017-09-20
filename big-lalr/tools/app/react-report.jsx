import React, {Component} from 'react';
import ReactDOM from 'react-dom';
import './index.scss';
import Explorer from './Explorer';

//import json from '../../test/fixtures/pets.json';

// get data from within html
const json = JSON.parse(document.getElementById('json').innerHTML);
const el = document.createElement('div');
document.body.appendChild(el);

// use history.pushState before launching react app
// so react router works on page load
history.pushState(null, null, "/");
ReactDOM.render(<Explorer grammar={json}/>, el);

window.addEventListener('beforeunload', function(event) {
    var s = "You have unsaved changes. Really leave?";

    event = event || window.event;
    if (event) {
        // This is for IE
        event.returnValue = s;
    }

    // This is for all other browsers
    return s;
});