const path = require('path');
const fs = require('fs');
const expect = require('chai').expect;
const parser = require('../');

describe('parse_glsl', function () {
  const src_files = [
    'animated_robot_skin',
    'bees_eye_view',
    'blinking_light',
    'creeper_skin',
    'inner_space',
    'noise_sweep',
    'ska_triangles',
    'space_without_time'
  ].map(function (name) {
    return fs.readFileSync(path.join(__dirname, 'fixtures', name + '.glsl'), 'utf8');
  });

  it ('exists', function () {
    expect(parser).to.be.a('object');
  });

  it('generates ast for animated robot skin', function () {
    const ast = parser.parse_glsl(src_files[0]);
    expect(ast.name).to.eql('translation_unit');
    expect(ast.children.length).to.eql(2);
  });

  it('generates ast for bees eye view', function () {
    const ast = parser.parse_glsl(src_files[1]);
    expect(ast.name).to.eql('translation_unit');
    expect(ast.children.length).to.eql(2);
  });
});
