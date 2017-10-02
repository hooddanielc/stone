#!/usr/bin/env bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PREV_PWD=$(pwd)

if ! type "emcc" &> /dev/null; then
  echo "please install and enable emscripten to compile js"
  exit 1
fi

if ! type "ib" &> /dev/null; then
  echo "please install ib c++ build tool"
  exit 1
fi

cd $DIR/..
mkdir -p gliss/dist
echo 'building to gliss/dist/jsbinding.js'
ib --cfg js_release gliss/jsbinding.js
cp ../out/js_release/gliss/jsbinding.js gliss/dist/jsbinding.js
cp ../out/js_release/gliss/jsbinding.js.mem gliss/dist/jsbinding.js.mem
cd $PREV_PWD