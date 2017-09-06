import process from 'process';
import path from 'path';
import webpack from 'webpack';
import externals from 'webpack-node-externals';

const moduleDir = process.env.PWD || __dirname;
const nodeModulesDir = path.join(moduleDir, 'node_modules');

const REACT_CONFIG = {
  entry: {
    'react-report.js': './app/react-report.jsx',
    'react-report-html.js': './app/index.html'
  },
  output: {
    path: path.join(moduleDir, "/dist"),
    filename: "[name]"
  },
  node: {
    fs: 'empty'
  },
  module: {
    rules: [
      {
        test: /\.jsx?$/,
        loader: 'babel-loader',
        exclude: /node_modules/,
        options: {
          cacheDirectory: true,
          plugins: [
            'babel-plugin-syntax-dynamic-import',
            'babel-plugin-transform-object-rest-spread',
            'babel-plugin-transform-class-properties',
            'babel-plugin-transform-runtime',
          ],
          presets: ['babel-preset-react'],
        },
      },
      {
        test: /\.scss$/,
        use: [
          {
            loader: 'vue-style-loader',
            options: {
              sourceMap: true,
              convertToAbsoluteUrls: true,
            },
          },
          {
            loader: 'css-loader',
            options: {
              modules: true,
              importLoaders: 1,
              localIdentName: '[name]_[local]__[hash:base64:4]',
              sourceMap: true,
            },
          },
          {
            loader: 'resolve-url-loader',
            options: {sourceMap: true},
          },
          {
            loader: 'sass-loader',
            options: {
              sourceMap: true,
              includePaths: [
                nodeModulesDir,
                path.join(nodeModulesDir, 'muicss', 'lib', 'sass'),
              ],
            },
          },
        ],
      },
      {
        test: /\.hbs$/,
        loader: 'handlebars-loader',
      },
      {
        test: /synce/,
        loader: 'imports-loader?webComponents',
      },
      {
        test: /\.(svg|png|jpg|gif)(\?.*)?/,
        loader: 'url-loader',
        options: {limit: 100000},
      },
      {
        test: /\.woff(2)?(\?v=[0-9]\.[0-9]\.[0-9])?$/,
        loader: 'url-loader',
        options: {
          limit: 10000,
          mimetype: 'application/font-woff',
        },
      },
      {
        test: /\.(ttf|eot|svg)(\?v=[0-9]\.[0-9]\.[0-9])?$/,
        loader: 'file-loader',
      },
      {
        test: /\.html$/,
        use: [
          {
            loader: 'file-loader',
            options: {
              name: '[name].[ext]'
            }
          },
          {
            loader: 'extract-loader'
          },
          {
            loader: 'html-loader'
          }
        ]
      }
    ]
  },
  resolve: {
    extensions: ['.js', '.jsx'],
    modules: [nodeModulesDir]
  },
}

const CLI_CONFIG = {
  entry: {
    'server.js': './server/server.js',
    'grammar.js': './server/grammar.js',
    'tfr': './server/tfr.js'
  },

  output: {
    path: path.join(moduleDir, "/dist"),
    filename: "[name]"
  },

  target: 'node',

  module: {
    rules: [
      {
        test: /\.js$/,
        loader: 'babel-loader',
        query: {
          presets: [
            'babel-preset-env',
          ],
          plugins: [
            'transform-decorators-legacy',
            'transform-class-properties',
            'transform-object-rest-spread'
          ]
        }
      },
      {
        test: /\.json$/,
        use: 'json-loader'
      },
      {
        test: /(\.txt|\.tfr)$/,
        use: 'raw-loader'
      }
    ]
  },

  plugins: [
    new webpack.BannerPlugin({
      banner: "#!/usr/bin/env node",
      raw: true,
      test: /(server\.js|tfr)/
    })
  ],

  node: false,

  externals: [externals()],
  resolveLoader: {
    modules: [nodeModulesDir],
  },
  resolve: {
    modules: [nodeModulesDir]
  }
};

export {REACT_CONFIG, CLI_CONFIG};

export default [REACT_CONFIG, CLI_CONFIG];
