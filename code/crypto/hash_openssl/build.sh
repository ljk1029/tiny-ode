
#!/bin/bash


build_test() {
    echo "build test"
    rm test.o
    gcc test.c mem_clr.c ./md5/md5_dgst.c ./md5/md5_one.c ./sha/sha1_one.c ./sha/sha1dgst.c ./sha/sha256.c ./sha/sha512.c -I ./sha/ -I ./md5/ -g -o  test.o
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

