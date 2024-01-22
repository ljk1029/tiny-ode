#include <iostream>
#include "base_string.h"
#include "base_math.h"
#include "base_input.h"
#include "base_memory.h"
#include <functional>

//using namespace std;
//using namespace io_demo;

using CallbackFunc = std::function<int()>;

// 测试回调
int func_print(const std::string& title, CallbackFunc callback)
{
    std::cout << "======" << "[" << title << " test]" << "=====" << std::endl;
    int ret = callback();
    std::cout << "--------[test end]--------\n\n";
    return ret;
}

int main_test(int argc, char* argv[])
{
    // 标准输入测试
    func_print("io_cin",  my_input::io_cin);
    func_print("io_cout", my_input::io_cout);

    // 引用测试
    func_print("test_quote", my_input::fun_quote);

    // 字符串测试
    func_print("stl_string", my_string::stl_string);
    func_print("stl_string", my_string::stl_strings);
    func_print("stl_array",  my_string::stl_array);

    // 指针内存测试
    func_print("memory_new",  my_mem::memory_new);
    func_print("memory_news", my_mem::memory_news);
    func_print("smart_ptr",   my_mem::smart_ptr);
    func_print("smart_ptrs",  my_mem::smart_ptrs);
    return 0;
}

// 测试用例
int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}


