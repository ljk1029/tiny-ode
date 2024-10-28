lib_path=../src/openssl-1.1.0l/build
lib_name=openssl
exe_name=demo_$lib_name
out_path=../build


# curl
function build_part() {
    rm $out_path/$exe_name.o 
    if [ ! -d "$out_path" ]; then
        mkdir $out_path
    fi
    gcc $exe_name.c -I . -g -o $exe_name.o -L ./ -l$lib_name 
    mv $exe_name.o $out_path
}

# lib
function build_lib_ssl() {
    cd $lib_path
    echo "build lib$exe_name"
}

# ssl
function build_ssl() {
    echo "build $exe_name"
    build_part
}

function run_ssl() {
    echo "run $exe_name"
    cp ssl.conf $out_path
    $out_path/$exe_name.o  
}

#usage
function usage() {
    echo "[I] Usage: [sh $0 cmd]"
    echo 'l  build ' $exe_name
    echo 'b  build ' $exe_name
	echo 'r  run   ' $exe_name
}


# main
if [ $# = 0 ]; then
    usage
else
    if [ $1 == 'b' ]; then
        build_ssl
    elif [ $1 == 'r' ];then
        run_ssl
    elif [ $1 == 'l' ];then
        build_lib_ssl
    fi
fi
