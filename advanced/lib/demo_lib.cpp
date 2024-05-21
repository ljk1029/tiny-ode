#include "lib_chrono.h"
#include "lib_file.h"
#include "lib_thread.h"
#include <iostream>
#include "../run_print.h"

using namespace my_base;

// 目录文件测试
void filesystemDirTest(my_base::TestRunner &test_runner) {
    if( test_runner.getRunStatus("filesys") ){
        my_base::my_file::PathConst new_path = {"mydir/mk_b"};
        std::cout << "getPath:" << my_base::my_file::getPath() << std::endl;
        if (my_base::my_file::createDir(my_base::my_file::dir_path)) {
            std::cout << "createDir:" << my_base::my_file::dir_path << std::endl;
        }
        if (my_base::my_file::createDirs(my_base::my_file::dirs_path)) {
            std::cout << "createDirs:" << my_base::my_file::dirs_path << std::endl;
        }
        if (my_base::my_file::isExist(my_base::my_file::dir_path)) {
            std::cout << "isExist" << std::endl;
        }
        if (!my_base::my_file::isFile(my_base::my_file::dir_path)) {
            std::cout << "noFile" << std::endl;
        }
        if (my_base::my_file::isDir(my_base::my_file::dir_path)) {
            std::cout << "isDir" << std::endl;
        }
        if (my_base::my_file::isExist(my_base::my_file::dir_path)) {
            my_base::my_file::reName(my_base::my_file::dirs_path, new_path);
            my_base::my_file::iteratorDir(my_base::my_file::dir_path);
            my_base::my_file::reMove(my_base::my_file::dir_path);
        }
        if (!my_base::my_file::isExist(my_base::my_file::dir_path)) {
            std::cout << "noExist " << my_base::my_file::dir_path << std::endl;
        }
    }
}

// 读写文件测试
void fileRWTest(my_base::TestRunner &test_runner) {
    std::cout << "start..." << std::endl;
    if( test_runner.getRunStatus("filerw") ){
        const char *file{"file.txt"};
        test_runner.funcPrint("fileWrite()",  [&file](){
            my_base::my_file::fileWrite(file);
        });
        test_runner.funcPrint("fileRead()",  [&file](){
            my_base::my_file::fileRead(file);
        });
        test_runner.funcPrint("fileAppend()",  [&file](){
            my_base::my_file::fileAppend(file);
            my_base::my_file::fileRead(file);
        });
    }
}

// 线程测试
void threadTest(my_base::TestRunner &test_runner) { 
    if( test_runner.getRunStatus("thread") ){
        my_base::my_thread::createThread(); 
    }
}

// 时间测试
void timeTest(my_base::TestRunner &test_runner) {
    if( test_runner.getRunStatus("time") ){
        my_base::my_chrono::sleepS(2);
        my_base::my_chrono::getTime();
        my_base::my_chrono::countTime([] { my_base::my_chrono::sleepS(1); });
    }
}

int mainLibTest(int argc, char *argv[]) {
    my_base::TestRunner test_runner(argc, argv);
    filesystemDirTest(test_runner);
    fileRWTest(test_runner);
    threadTest(test_runner);
    timeTest(test_runner);
    return 0;
}

// 测试用例
int main(int argc, char *argv[]) {
    mainLibTest(argc, argv);
    return 0;
}