
#!/bin/bash


build_test() {
    echo "build test"
    rm test.o
    gcc test.c md5.c sha1.c sha256.c sha512.c -g -o  test.o
}

run_test() {
    echo "run test"
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
    ./test.o 
}

if [ $# = 0 ]; then
    echo "no thing"
else
    if [ $1 == 'b' ]; then
        build_test
    elif [ $1 == 'r' ];then
        run_test
    elif [ $1 == 'run' ];then
        run_test
    fi
fi

