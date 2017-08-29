const fs = require('fs');
const path = require('path');
const { Symbol, Token, Reduction, Rule, Grammar } = require('../symbol');
const { expect } = require('chai');

describe('Symbol', () => {
  it('exists', () => {
    expect(Symbol).to.be.a('function');
  });

  it('assign correct properties', () => {
    const sym1 = new Symbol({ name: 'a' });
    const sym2 = new Symbol({ name: 'b' });
    const sym3 = new Symbol({ name: 'a' });
    expect(sym1.id).to.be.above(0);
    expect(sym2.id).to.be.above(0);
    expect(sym2.id).to.not.eql(sym1.id);
    expect(sym3.id).to.eql(sym1.id);
  });

  it('validates name', () => {
    expect(() => new Symbol({ name: 'asdf+asdf' })).to.throw();
    expect(() => new Symbol({ name: 'asdf./asdf' })).to.throw();
    expect(() => new Symbol({ name: 'ADSD*asdf' })).to.throw();
  });

  describe('Token', () => {
    it('assigns props', () => {
      const tok = new Token({ name: 'S' });
      expect(tok.name).to.eql('S');
      expect(tok.id).to.be.above(0);
      expect(() => new Reduction({ name: 'S' })).to.throw()
    });
  });

  describe('Reduction', () => {
    it('assigns props', () => {
      const red = new Reduction({ name: 'R' });
      expect(red.name).to.eql('R');
      expect(red.id).to.be.above(0);
      expect(() => new Token({ name: 'R' })).to.throw()
    });
  });

  describe('Rule', () => {
    it('assigns props', () => {
      const red = new Reduction({ name: 'R' });
      const tok1 = new Token({ name: 'S' });
      const tok2 = new Token({ name: 'E' });
      const rule = new Rule({ lhs: red, rhs: [tok1, tok2] });
      expect(() => new Rule({ rhs: red, lhs: [] })).to.throw();
      expect(() => new Rule({ lhs: red, rhs: tok1 })).to.throw();
      expect(rule.length).to.eql(2);
    });
  });
});

describe('Grammar', () => {
  const p = path.join(__dirname, 'pets.tfr');

  it('reads file', () => {
    const res = Grammar.from_file(p);
  });
});

