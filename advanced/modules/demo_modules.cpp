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

// 文件目录测试
void testDir(my_base::TestRunner &test_runner) {
    my_file::ConstPath dir_path{"mydir"};
    my_file::ConstPath dirs_path{"mydir/dir1"};
    my_file::ConstPath new_path = {"mydir/mk1"};

    if (test_runner.getRunStatus("dir")) {
        my_base::print("dir module test");
        my_file::getPath();
        my_file::createDir(dir_path);
        my_file::createDirs(dirs_path);
        my_file::isExist(dir_path);
        my_file::isFile(dir_path);
        my_file::isDir(dir_path);
        if (my_file::isExist(dir_path)) {
            std::cout << "重命名目录测试" << dirs_path << "->" << new_path << std::endl;
            my_file::reName(dirs_path, new_path);
            std::cout << "目录迭代测试" << std::endl;
            my_file::iteratorDir(dir_path);
            std::cout << "目录删除测试" << std::endl;
            my_file::reMove(dir_path);
        }
        my_file::isExist(dir_path);
    }
}

// 文件读写测试
void testRW(my_base::TestRunner &test_runner) {
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
void testThread(my_base::TestRunner &test_runner) {
    if (test_runner.getRunStatus("thr")) {
        my_base::print("thread module test");
        my_thread::createThread();
    }
}

#ifdef MY_MODULES_TEST
int main(int argc, char *argv[]) {
    my_base::TestRunner test_runner(argc, argv);
    timeTest(test_runner);
    testDir(test_runner);
    testRW(test_runner);
    testThread(test_runner);
    return 0;
}
#endif