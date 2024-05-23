#include "common.h"
#include "../run_print.h"

using namespace my_base;

// 时间测试
void timeTest(my_base::TestRunner &test_runner) {
    my_base::print("time module test");
    prints("time module test");
    if (test_runner.getRunStatus("time")) {
        my_time::sleep_S(2);
        my_time::sleepMs(50);
        my_time::sleepUs(50);
        my_time::getTime();
        my_time::countTime([] { std::cout << "hello callback\n"; });
    }
}

// 文件测试
void fileTest(my_base::TestRunner &test_runner) {
    // 目录测试
    if (test_runner.getRunStatus("dir")) {
        my_base::print("dir module test");
        my_file::ConstPath cur_directory{"mydir"};  // 顶层目录
        my_file::ConstPath sub_directory{"mydir/dir1"};  // 子目录
        my_file::ConstPath new_directory = {"mydir/mk1"};// 新建目录

        my_file::getPath();
        my_file::createDir(cur_directory);
        my_file::createDirs(sub_directory);
        my_file::isExist(cur_directory);
        my_file::isFile(cur_directory);
        my_file::isDir(cur_directory);
        if (my_file::isExist(cur_directory)) {
            std::cout << "重命名目录测试" << sub_directory << "->" << new_directory << std::endl;
            my_file::reName(sub_directory, new_directory);
            std::cout << "目录迭代测试" << std::endl;
            my_file::iteratorDir(cur_directory);
            std::cout << "目录删除测试" << std::endl;
            my_file::reMove(cur_directory);
        }
        my_file::isExist(cur_directory);
    }
    // 读写测试
    if (test_runner.getRunStatus("rw")) {
        my_base::print("file module test");
        const char *file{"file.txt"};
        my_file::fileWrite(file);
        my_file::fileRead(file);
        my_file::fileAppend(file);
        my_file::fileRead(file);
    }
}

// 线程测试
void threadTest(my_base::TestRunner &test_runner) {
    if (test_runner.getRunStatus("thr")) {
        my_base::print("thread module test");
        my_thread::createThread();
    }
    if (test_runner.getRunStatus("thread")) {
        my_base::print("threadEx module test");
        #ifdef MY_MODULES_TEST
        thread_main(0, nullptr);
        #endif
    }
}




#ifdef MY_MODULES_TEST
int main(int argc, char *argv[]) {
    my_base::TestRunner test_runner(argc, argv);
    threadTest(test_runner);
    timeTest(test_runner);
    fileTest(test_runner);
    return 0;
}
#endif