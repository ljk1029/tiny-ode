##!/bin/bash

exe_name=my_io
out_path=../../build
CC=g++

# 构建
function build_part() {
    echo "build $exe_name"
    rm $out_path/$exe_name.o 
    $CC  demo.cpp input.cpp  -I . -g -o $exe_name.o 
    if [ ! -d "$out_path" ]; then
        mkdir $out_path
    fi
    mv $exe_name.o $out_path
}

# 构建
function build_demo()
{
    exe_name=my_io
    build_part
}

# 运行
function run_demo() 
{
    exe_name=my_io
    echo "run $exe_name"
    $out_path/$exe_name.o  
}

function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo 'b   build demo'
	echo 'r   run   demo'  
}

# main
if [ $# = 0 ]; then
    usage
else
    if [ $1 == 'b' ]; then
        build_demo
    elif [ $1 == 'r' ];then
        run_demo
    else
        usage
    fi
fi
