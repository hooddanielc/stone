####################################################
# installs nvm for users that don't have their own #
####################################################

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
export NVM_DIR="$HOME/.nvm"

if ! test -e $NVM_DIR; then
  echo 'install nvm next to biglr'
  export NVM_DIR="$DIR/.nvm"
fi

if ! type "nvm" > /dev/null; then
  # install local nvm next to biglr
  if [ ! -d "$NVM_DIR" ]; then
    git clone https://github.com/creationix/nvm.git $NVM_DIR --branch v0.33.4
  fi

  [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
fi

if ! test -e "$DIR/dist/react-report.js" || ! test -e "$DIR/dist/server.js"; then
  # build the gui app
  cd $DIR
  nvm install
  npm install
  npm run build
fi

node --version