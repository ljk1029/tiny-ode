#!/bin/bash


exe_name=test.o

usage() {
    echo "[I] Usage: [sh $0 X]"
    echo 'b  build'
	echo 'r  run'
}

build_test() {
    echo "build test"
    rm -r ./bin
    gcc test.c  ./aes/aes_cbc.c ./aes/aes_ecb.c ./aes/aes_cfb.c ./aes/aes_ofb.c ./modes/cbc128.c ./modes/cfb128.c ./modes/ofb128.c ./aes/aes_core.c  -g -o  $exe_name
    mkdir bin
    mv $exe_name ./bin/$exe_name
}

run_test() {
    echo "run test"
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
    ./bin/$exe_name
}

if [ $# = 0 ]; then
    echo "no thing"
else
    if [ $1 = 'b' ]; then
        build_test
    elif [ $1 = 'r' ];then
        run_test
    fi
fi

