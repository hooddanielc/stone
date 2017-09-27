DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
CUR_PWD=$PWD
cd $DIR
cd ..
ib --cfg release big-lalr/biglr
../out/release/big-lalr/biglr -r gliss/docs/glsl.biglr -s
cd $CUR_PWD
