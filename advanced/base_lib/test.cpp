#include "lib_chrono.h"
#include "lib_file.h"
#include "lib_thread.h"
#include <functional>
#include <iostream>

using CallbackFunc = std::function<void()>;

// 测试回调
void func_print(const std::string &title, CallbackFunc callback) {
    std::cout << "======"
              << "[" << title << " test]"
              << "=====" << std::endl;
    callback();
    std::cout << "--------[test end]--------\n\n";
}

// 目录文件测试
void test_dir() {
    myfile::Path_Const new_path = {"mydir/mkB"};

    std::cout << "getPath:" << myfile::getPath() << std::endl;
    if (myfile::createDir(myfile::dir_path)) {
        std::cout << "createDir:" << myfile::dir_path << std::endl;
    }

    if (myfile::createDirs(myfile::dirs_path)) {
        std::cout << "createDirs:" << myfile::dirs_path << std::endl;
    }

    if (myfile::isExist(myfile::dir_path)) {
        std::cout << "isExist" << std::endl;
    }

    if (!myfile::isFile(myfile::dir_path)) {
        std::cout << "noFile" << std::endl;
    }

    if (myfile::isDir(myfile::dir_path)) {
        std::cout << "isDir" << std::endl;
    }

    if (myfile::isExist(myfile::dir_path)) {
        myfile::reName(myfile::dirs_path, new_path);
        myfile::iteratorDir(myfile::dir_path);
        myfile::reMove(myfile::dir_path);
    }

    if (!myfile::isExist(myfile::dir_path)) {
        std::cout << "noExist " << myfile::dir_path << std::endl;
    }
}

// 读写文件测试
void test_file() {
    const char *file{"file.txt"};
    myfile::writeFile(file);
    myfile::readFile(file);
    myfile::appFile(file);
    myfile::readFile(file);
}

// 线程测试
void test_thread() { mythread::create_thread(); }

// 时间测试
void test_time() {
    mychrono::sleep_s(2);
    mychrono::get_time();
    mychrono::count_time([] { mychrono::sleep_s(1); });
}

int main_test(int argc, char *argv[]) {
    func_print("dir", test_dir);
    func_print("file", test_file);
    func_print("thread", test_thread);
    func_print("time", test_time);
    return 0;
}

// 测试用例
int main(int argc, char *argv[]) {
    main_test(argc, argv);
    return 0;
}