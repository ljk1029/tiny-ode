#!/bin/bash

APP_name='app.exe'
build_path=./build


function build(){
    g++ -std=c++17 -o "$output_file.o" "$cpp_file" $dynamic_libs

    if [ ! -d "$build_path" ]; then
        mkdir $build_path
    fi

    mv $output_file.o  $build_path/
}

function run(){
    #export LD_LIBRARY_PATH=~/workspace/apps/test/task/lib
    cd $build_path
    $build_path//$APP_name
}


function usage() {
    echo "用法："
    echo "  $0 -o -f [-e]"
    echo "  -o  r: run"
    echo "      b: build"
    echo "  -f  文件位置+名称"
    echo "  -e  环境变量"
    echo
}

if [ $# -lt 2 ];then
    usage
elif [ $1 == 'b' ];then
   # 根据第二个参数查找cpp文件位置进行编译
    cpp_file="$2"
    output_file="${cpp_file%.cpp}"
    dynamic_libs="${@:3}"
    #g++ -o "$output_file" "{$cpp_file}.o" $dynamic_libs
    build
elif [ $1 == 'r' ];then
    # 根据第二个参数执行程序
    executable="$2"
    additional_args="${@:3}"
    ./"$executable" $additional_args
    #run
else
    usage
fi
