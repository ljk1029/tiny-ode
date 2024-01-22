#!/bin/bash

APP_name='gtest.exe'
build_path=./build


function build(){
    g++ gtest_main.cc gtest-all.cc -o $APP_name -I ../ -lpthread 
}

function run(){
    ./$APP_name
}

# 用法
function usage() {
    echo "用法："
    echo "  $0 -o -f [-e]"
    echo "  -o  r: run"
    echo "      b: build"
    echo "  -f  文件位置+名称"
    echo "  -e  环境变量"
    echo
}

# main
if [ $# -eq 1 ];then
    if [ $1 == 'b' ];then
        build
        return 1
    elif [ $1 == 'r' ];then
        run
        exit
    fi
fi

usage