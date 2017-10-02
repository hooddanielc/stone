// annoyance?
// https://github.com/kripken/emscripten/issues/2537
const process = require('process');
const oldCwd = process.cwd();
process.chdir(__dirname);
const Module = require('./jsbinding.js');
process.chdir(oldCwd);

module.exports = {
  parse_glsl: function (src) {
    return JSON.parse(Module.parse_glsl(src));
  }
}
