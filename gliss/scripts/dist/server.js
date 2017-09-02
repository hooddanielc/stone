#!/usr/bin/env node
/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId]) {
/******/ 			return installedModules[moduleId].exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			i: moduleId,
/******/ 			l: false,
/******/ 			exports: {}
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.l = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// define getter function for harmony exports
/******/ 	__webpack_require__.d = function(exports, name, getter) {
/******/ 		if(!__webpack_require__.o(exports, name)) {
/******/ 			Object.defineProperty(exports, name, {
/******/ 				configurable: false,
/******/ 				enumerable: true,
/******/ 				get: getter
/******/ 			});
/******/ 		}
/******/ 	};
/******/
/******/ 	// getDefaultExport function for compatibility with non-harmony modules
/******/ 	__webpack_require__.n = function(module) {
/******/ 		var getter = module && module.__esModule ?
/******/ 			function getDefault() { return module['default']; } :
/******/ 			function getModuleExports() { return module; };
/******/ 		__webpack_require__.d(getter, 'a', getter);
/******/ 		return getter;
/******/ 	};
/******/
/******/ 	// Object.prototype.hasOwnProperty.call
/******/ 	__webpack_require__.o = function(object, property) { return Object.prototype.hasOwnProperty.call(object, property); };
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(__webpack_require__.s = 5);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ (function(module, exports) {

module.exports = require("path");

/***/ }),
/* 1 */,
/* 2 */,
/* 3 */,
/* 4 */
/***/ (function(module, exports) {

module.exports = require("webpack");

/***/ }),
/* 5 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


var _path = __webpack_require__(0);

var _path2 = _interopRequireDefault(_path);

var _browserSync = __webpack_require__(6);

var _browserSync2 = _interopRequireDefault(_browserSync);

var _webpack = __webpack_require__(4);

var _webpack2 = _interopRequireDefault(_webpack);

var _webpackConfig = __webpack_require__(7);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var bs = _browserSync2.default.create('Dev Server');

var init_bs = function init_bs() {
  bs.init({
    server: _path2.default.resolve(__dirname, '..', 'dist')
  });
};

bs.notify('Initializing...');
var compiler = (0, _webpack2.default)(_webpackConfig.REACT_CONFIG);
var watching = compiler.watch({}, function (err, stats) {
  if (err) {
    console.log(err);
  }

  if (!bs.active) {
    init_bs();
  }

  if (stats && typeof stats.toString === 'function') {
    console.log(stats.toString({ colors: true }));
  }

  bs.notify('Build Complete... Reloading');
  bs.reload();
});

process.on('exit', function () {
  if (bs.active) {
    bs.exit();
  }
});

/***/ }),
/* 6 */
/***/ (function(module, exports) {

module.exports = require("browser-sync");

/***/ }),
/* 7 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.CLI_CONFIG = exports.REACT_CONFIG = undefined;

var _process = __webpack_require__(8);

var _process2 = _interopRequireDefault(_process);

var _path = __webpack_require__(0);

var _path2 = _interopRequireDefault(_path);

var _webpack = __webpack_require__(4);

var _webpack2 = _interopRequireDefault(_webpack);

var _webpackNodeExternals = __webpack_require__(9);

var _webpackNodeExternals2 = _interopRequireDefault(_webpackNodeExternals);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var moduleDir = _process2.default.env.PWD || __dirname;
var nodeModulesDir = _path2.default.join(moduleDir, 'node_modules');

var REACT_CONFIG = {
  entry: {
    'react-report.js': './app/react-report.jsx',
    'react-report-html.js': './app/index.html'
  },
  output: {
    path: _path2.default.join(moduleDir, "/dist"),
    filename: "[name]"
  },
  node: {
    fs: 'empty'
  },
  module: {
    rules: [{
      test: /\.jsx?$/,
      loader: 'babel-loader',
      exclude: /node_modules/,
      options: {
        cacheDirectory: true,
        plugins: ['babel-plugin-syntax-dynamic-import', 'babel-plugin-transform-object-rest-spread', 'babel-plugin-transform-class-properties', 'babel-plugin-transform-runtime'],
        presets: ['babel-preset-react']
      }
    }, {
      test: /\.scss$/,
      use: [{
        loader: 'vue-style-loader',
        options: {
          sourceMap: true,
          convertToAbsoluteUrls: true
        }
      }, {
        loader: 'css-loader',
        options: {
          modules: true,
          importLoaders: 1,
          localIdentName: '[name]_[local]__[hash:base64:4]',
          sourceMap: true
        }
      }, {
        loader: 'resolve-url-loader',
        options: { sourceMap: true }
      }, {
        loader: 'sass-loader',
        options: {
          sourceMap: true,
          includePaths: [nodeModulesDir, _path2.default.join(nodeModulesDir, 'muicss', 'lib', 'sass')]
        }
      }]
    }, {
      test: /\.hbs$/,
      loader: 'handlebars-loader'
    }, {
      test: /synce/,
      loader: 'imports-loader?webComponents'
    }, {
      test: /\.(svg|png|jpg|gif)(\?.*)?/,
      loader: 'url-loader',
      options: { limit: 100000 }
    }, {
      test: /\.woff(2)?(\?v=[0-9]\.[0-9]\.[0-9])?$/,
      loader: 'url-loader',
      options: {
        limit: 10000,
        mimetype: 'application/font-woff'
      }
    }, {
      test: /\.(ttf|eot|svg)(\?v=[0-9]\.[0-9]\.[0-9])?$/,
      loader: 'file-loader'
    }, {
      test: /\.html$/,
      use: [{
        loader: 'file-loader',
        options: {
          name: '[name].[ext]'
        }
      }, {
        loader: 'extract-loader'
      }, {
        loader: 'html-loader'
      }]
    }]
  },
  resolve: {
    extensions: ['.js', '.jsx'],
    modules: [nodeModulesDir]
  }
};

var CLI_CONFIG = {
  entry: {
    'server.js': './server/server.js',
    'grammar.js': './server/grammar.js',
    'tfr': './server/tfr.js'
  },

  output: {
    path: _path2.default.join(moduleDir, "/dist"),
    filename: "[name]"
  },

  target: 'node',

  module: {
    rules: [{
      test: /\.js$/,
      loader: 'babel-loader',
      query: {
        presets: ['babel-preset-env'],
        plugins: ['transform-decorators-legacy', 'transform-class-properties', 'transform-object-rest-spread']
      }
    }, {
      test: /\.json$/,
      use: 'json-loader'
    }, {
      test: /(\.txt|\.tfr)$/,
      use: 'raw-loader'
    }]
  },

  plugins: [new _webpack2.default.BannerPlugin({
    banner: "#!/usr/bin/env node",
    raw: true,
    test: /(server\.js|tfr)/
  })],

  node: false,

  externals: [(0, _webpackNodeExternals2.default)()],
  resolveLoader: {
    modules: [nodeModulesDir]
  },
  resolve: {
    modules: [nodeModulesDir]
  }
};

exports.REACT_CONFIG = REACT_CONFIG;
exports.CLI_CONFIG = CLI_CONFIG;
exports.default = [REACT_CONFIG, CLI_CONFIG];

/***/ }),
/* 8 */
/***/ (function(module, exports) {

module.exports = require("process");

/***/ }),
/* 9 */
/***/ (function(module, exports) {

module.exports = require("webpack-node-externals");

/***/ })
/******/ ]);