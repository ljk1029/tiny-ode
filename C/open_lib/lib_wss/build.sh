lib_path=
lib_name=websockets
exe_name=demo_$lib_name
out_path=./build


# wss
function build_part() {
    rm $out_path/${exe_name}_s.o 
    rm $out_path/${exe_name}_c.o 
    if [ ! -d "$out_path" ]; then
        mkdir $out_path
    fi
    gcc ${exe_name}_s.c -I ./include/ -I ../openssl/include/ -g -o ${exe_name}_s.o -L ./lib/ -L ../openssl/lib -l$lib_name -lssl -lcrypto
    gcc ${exe_name}_c.c -I ./include/ -I ../openssl/include/ -g -o ${exe_name}_c.o -L ./lib/ -L ../openssl/lib -l$lib_name -lssl -lcrypto
    mv ${exe_name}_s.o $out_path
    mv ${exe_name}_c.o $out_path
}

# wss
function build_lib_wss() {
    cd $lib_path
    echo "build lib$exe_name"
}

# wss
function build_wss() {
    echo "build $exe_name"
    build_part
}

function run_wss_s() {
    echo "run $exe_name"
    $out_path/${exe_name}_s.o  
}

function run_wss_c() {
    echo "run $exe_name"
    $out_path/${exe_name}_c.o  
}

#usage
function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo 'l  build ' $exe_name
    echo 'b  build ' $exe_name
	echo 'r-c  run ' $exe_name
	echo 'r-s  run ' $exe_name
}


# main
if [ $# = 0 ]; then
    usage
else
    if [ $1 == 'b' ]; then
        build_wss
    elif [ $1 == 'r-s' ];then
        run_wss_s
     elif [ $1 == 'r-c' ];then
        run_wss_c
    elif [ $1 == 'l' ];then
        build_lib
    fi
fi
