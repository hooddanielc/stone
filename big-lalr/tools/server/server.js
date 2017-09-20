import path from 'path';
import browserSync from 'browser-sync';
import webpack from 'webpack';
import fallback from 'connect-history-api-fallback';
import {REACT_CONFIG} from '../webpack.config.babel';

const bs = browserSync.create('Dev Server');

const init_bs = () => {
  bs.init({
    server: {
      baseDir: path.resolve(__dirname, '..', 'dist'),
      middleware: [fallback()]
    }
  });
}

bs.notify('Initializing...');
const compiler = webpack(REACT_CONFIG);
const watching = compiler.watch({}, (err, stats) => {
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

process.on('exit', () => {
  if (bs.active) {
    bs.exit();
  }
});