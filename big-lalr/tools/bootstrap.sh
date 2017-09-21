####################################################
# installs nvm for users that don't have their own #
####################################################

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PROJECT_ROOT="$DIR/../.."
export IB_DIR="$HOME/.ib"
export NVM_DIR="$HOME/.nvm"

if ! test -e $NVM_DIR; then
  echo 'installing nvm'
  export NVM_DIR="$DIR/.nvm"
fi

if ! test -e $IB_DIR; then
  IB_DIR="$DIR/.ib"
fi

if ! type "ib" &> /dev/null; then
  echo "install ib $IB_DIR"
  git clone https://github.com/JasonL9000/ib.git $IB_DIR
  export PATH=$PATH:$IB_DIR
fi

if ! type "nvm" &> /dev/null; then
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

if ! test -e "$PROJECT_ROOT/../out"; then
  # if user does not have this folder, they should build it again
  echo 'Building biglr for first time'
  cd "$PROJECT_ROOT" && ib --cfg osx-release big-lalr/biglr
fi
