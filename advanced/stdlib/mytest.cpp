#include <functional>
#include <iostream>
#include "myfile.h"
#include "mythread.h"


using CallbackFunc = std::function<void()>;

// 测试回调
void test_func(const std::string& title, CallbackFunc callback)
{
    std::cout << "------" << "[" \
        << title << ":test]" 
        << "------" << std::endl;
    callback();
    std::cout << "----------end---------\n\n";
}


// 目录文件测试
void test_dir()
{
    myfile::Path new_path = {"mydir/mkB"};

    std::cout << "getPath:" << myfile::getPath() << std::endl;
    if(myfile::createDir(myfile::dir_path))
    {
        std::cout << "createDir:"<< myfile::dir_path << std::endl;
    }

    if(myfile::createDirs(myfile::dirs_path))
    {
        std::cout << "createDirs:"<< myfile::dirs_path << std::endl;
    }

    if(myfile::isExist(myfile::dir_path))
    {
        std::cout << "isExist" << std::endl;
    }

    if(!myfile::isFile(myfile::dir_path))
    {
        std::cout << "noFile" << std::endl;
    }

    if(myfile::isDir(myfile::dir_path))
    {
        std::cout << "isDir" << std::endl;
    }

    if(myfile::isExist(myfile::dir_path))
    {
        myfile::reName(myfile::dirs_path, new_path);
        myfile::iteratorDir(myfile::dir_path);
        myfile::reMove(myfile::dir_path);
    }

    if(!myfile::isExist(myfile::dir_path))
    {
        std::cout << "noExist " << myfile::dir_path << std::endl;
    }
}

// 读写文件测试
void test_file()
{
    const char* file{"file.txt"};
    myfile::writeFile(file);
    myfile::readFile(file);
    myfile::appFile(file);
    myfile::readFile(file);
}

// 线程测试
void test_thread()
{
    mythread::demo_thread();
}



int main()
{
    test_func("dir",  test_dir);
    test_func("file", test_file);
    test_func("thread", test_thread);

    return 0;
}