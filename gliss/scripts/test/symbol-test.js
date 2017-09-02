import fs from 'fs';
import path from 'path';

import {
  Symbol,
  Token,
  Reduction,
  Rule,
  Grammar,
  State,
  StateCollection
} from '../server/grammar';

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
  const p = path.join(__dirname, '..', 'grammar', 'pets.tfr');
  const p_epsilon = path.join(__dirname, '..', 'grammar', 'pets_epsilon.tfr');
  const p_no_top = path.join(__dirname, '..', 'grammar', 'pets_no_top.tfr');
  const p_unused_tokens = path.join(__dirname, '..', 'grammar', 'pets_unused_tokens.tfr');
  const p_no_top_arrow = path.join(__dirname, '..', 'grammar', 'pets_no_top_arrow.tfr');
  const p_glsl_test = path.join(__dirname, '..', 'grammar', 'glsl-test.tfr');

  it('reads correct grammar', () => {
    const res = Grammar.from_file(p);
    expect(res.tokens).to.be.a('object');
  });

  it('reads correct grammar with epsilon', () => {
    const res = Grammar.from_file(p_epsilon);
    expect(res.tokens).to.be.a('object');
  });

  it('throws if provided bad grammar', () => {
    expect(() => Grammar.from_file(p_no_top)).to.throw();
    expect(() => Grammar.from_file(p_unused_tokens)).to.throw();
    expect(() => Grammar.from_file(p_unused_tokens)).to.throw();
    expect(() => Grammar.from_file(p_no_top_arrow)).to.throw();
  });

  it('gets first set', () => {
    const res = Grammar.from_file(p);
    const first = res.get_first_set(res.top.lhs);
    expect(first.map((e) => e.name)).to.eql(['c', 'd']);
    expect(res.get_first_set(res.tokens['a'])).to.eql([res.tokens['a']]);
  });

  it('gets follow set', () => {
    const res = Grammar.from_file(p);
    const follow = res.get_follow_set(res.top.lhs);
    expect(follow.map(({name}) => name)).to.eql(['BREAK', 'c', 'd']);
    const follow_pet = res.get_follow_set(res.symbols['pet']);
    expect(follow_pet.map(({name}) => name)).to.eql(['c', 'd']);
  });

  it('gets starting items', () => {
    const res = Grammar.from_file(p);
    const start = res.get_starting_items();
    expect(start.map(({rule}) => rule.lhs.name)).to.eql(['TOP', 'TOP', 'TOP']);
    expect(start.map(({dot}) => dot)).to.eql([0, 0, 0]);
    expect(start.map(({peek}) => peek.name)).to.eql(['BREAK', 'c', 'd']);
  });

  it('gets closure of starting items', () => {
    const res = Grammar.from_file(p);
    const start = res.get_starting_items();
    const state = res.get_closure(start);
    expect(state instanceof State).to.eql(true);
  });

  it('gets goto of state', () => {
    const res = Grammar.from_file(p);
    const start = res.get_starting_items();
    const state = res.get_closure(start);
    const next = res.get_goto(state, res.tokens['c']);
    expect(next instanceof State).to.eql(true);
  });

  it('gets state table', function () {
    const res = Grammar.from_file(p);
    const state_collection = res.get_state_table();
    expect(state_collection instanceof StateCollection);
    const states = state_collection.states;
    states.forEach((s) => expect(s instanceof State).to.eql(true));
  });
});
