import path from 'path';
import browserSync from 'browser-sync';
import fallback from 'connect-history-api-fallback';
import program from 'commander';
import pkg from '../package.json';

program
  .version(pkg.version)
  .option('-d, --docs [file]', 'Serve generated one page app')
  .parse(process.argv);

if (!program.docs) {
  console.log('No doc file provided, showing demo grammar now.');
  program.docs = path.resolve(__dirname, '..', '..', 'test', 'fixtures');
} else {
  program.docs = path.resolve(program.docs);
}

const bs = browserSync.create('Docs Server');

const init_bs = () => {
  bs.notify('Initializing...');

  const index = `/${path.basename(program.docs)}`;

  bs.init({
    startPath: index,
    server: {
      baseDir: path.dirname(program.docs),
      index,
      middleware: [fallback({index})],
      serveStaticOptions: {
        extensions: ["html", "js"]
      }
    }
  });
}

init_bs();

process.on('exit', () => {
  if (bs.active) {
    bs.exit();
  }
});