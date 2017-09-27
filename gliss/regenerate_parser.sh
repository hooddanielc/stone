DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
CUR_PWD=$PWD
cd $DIR
cd ..
ib --cfg release big-lalr/biglr
../out/release/big-lalr/biglr -r $DIR/docs/glsl.biglr -f
cp $DIR/docs/glsl.h $DIR/glsl-lang.h
cd $CUR_PWD
