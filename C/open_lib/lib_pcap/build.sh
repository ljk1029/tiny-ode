lib_path=
lib_name=pcap
exe_name=demo_$lib_name
out_path=./build


# pcap
function build_part() {
    rm $out_path/$exe_name.o 
    if [ ! -d "$out_path" ]; then
        mkdir $out_path
    fi
    gcc $exe_name.c -I ./include/ -g -o $exe_name.o -L ./lib/ -l$lib_name 
    mv $exe_name.o $out_path
}

# pcap
function build_lib_pcap() {
    cd $lib_path
    echo "build lib$exe_name"
}

# pcap
function build_pcap() {
    echo "build $exe_name"
    build_part
}

function run_pcap() {
    echo "run $exe_name"
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
        build_pcap
    elif [ $1 == 'r' ];then
        run_pcap
    elif [ $1 == 'l' ];then
        build_lib
    fi
fi
