#!/bin/bash -xe
####################################################
# installs nvm for users that don't have their own #
####################################################

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PROJECT_ROOT="$DIR/../.."
export IB_DIR="$HOME/.ib"
export NVM_DIR="$HOME/.nvm"

if ! [ -x "$(command -v nvm)" ]; then
  echo 'warning: bootstrapping with nvm is recommended'
fi

if ! [ -x "$(command -v ib)" ]; then
  if ! [ -f "${IB_DIR}/ib" ]; then
    echo 'error: ib is not installed'
    echo 'MacOSX: brew install ib'
    echo 'Linux: clone http://github.com/jasonl9000/ib'
    echo "Install in ${IB_DIR}"
    git clone https://github.com/JasonL9000/ib.git "${IB_DIR}"
  fi
  export PATH="${PATH}:${IB_DIR}"
fi

if [ ! -x "$(command -v nvm)" ]; then
  # install local nvm next to biglr
  if [ ! -d "${NVM_DIR}" ]; then
    git clone https://github.com/creationix/nvm.git $NVM_DIR --branch v0.33.4
  fi

  [ -s "${NVM_DIR}/nvm.sh" ] && \. "${NVM_DIR}/nvm.sh"
fi

# build the gui app
cd "${DIR}"
nvm install
npm install
npm run build

# build ib
cd "${PROJECT_ROOT}"
ib --cfg osx-release big-lalr/biglr
