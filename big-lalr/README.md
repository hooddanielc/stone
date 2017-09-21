Big LALR
========

> My LALR parser generator is too slow, and my grammar is too big. Not even NodeJS is fast enough!

Is it? Big LALR is a parser generator written in C++. Big LALR utilizes all platform resources to yield huge goto and action tables in a fraction of the time it would take most dynamically typed languages to produce.

## How To Use

`biglr -h`

Generate parser next to grammar file

`biglr --rules pets.biglr`

View generated tools/documentation in a web app

`biglr --rules pets.biglr -s`

## Example Rules

`pets.biglr`

```
/token c a t d o g c a n a r y
/top -> pets
pets -> pets pet
pets -> nothing
pet -> c a t
pet -> d o g
pet -> c a n a r y
nothing ->
```

_/token_ should list all tokens
_/top_ is the starting rule, commonly known as omega.
_reduction_name -> token sequence_ is an example rule.
_nothing ->_ Rule without right side (epsilon) is aloud.

## Building

- Install [clang](https://clang.llvm.org/)
- Install [ib](https://github.com/JasonL9000/ib)
- build generator `ib --cfg release big-lalr/biglr`
- launch biglr `../out/release/big-lalr/biglr -r big-lalr/test/fixtures/pets.biglr`

## Run Tests

`ib --test_all big-lalr`