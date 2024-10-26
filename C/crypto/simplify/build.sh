#!/bin/bash

exe_name=test.o

usage() {
    echo "[I] Usage: [sh $0 X]"
    echo 'b  build'
	echo 'r  run'
}

build_test() {
    echo "build test"
    rm $exe_name 
    gcc test.c md5.c sha256.c  -g -o $exe_name 
}

run_test() {
    echo "run test"
    ./$exe_name  
}

if [ $# = 0 ]; then
    echo "no thing"
else
    if [ $1 == 'b' ]; then
        build_test
    elif [ $1 == 'r' ];then
        run_test
    fi
fi