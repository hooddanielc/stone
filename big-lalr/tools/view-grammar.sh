#!/usr/bin/env bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PROJECT_ROOT="$DIR/../.."
export NVM_DIR="$HOME/.nvm"

if ! test -e $NVM_DIR; then
  echo 'installing nvm'
  export NVM_DIR="$DIR/.nvm"
fi

if ! type "nvm" &> /dev/null; then
  # install local nvm next to biglr
  if [ ! -d "$NVM_DIR" ]; then
    git clone https://github.com/creationix/nvm.git $NVM_DIR --branch v0.33.4
  fi

  [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
fi

LAST_PWD=$PWD
cd $DIR && nvm use
cd $LAST_PWD
node $DIR/dist/server $@
