#include <iostream>
#include "string.h"
#include "math.h"
#include "input.h"
#include "memory.h"
#include <functional>

//using namespace std;
//using namespace io_demo;

using CallbackFunc = std::function<int()>;

// 测试回调
int test_func(const std::string& title, CallbackFunc callback)
{
    std::cout << "------" << "[" << title << " test]" 
        << "------" << std::endl;
    int ret = callback();
    std::cout << "----------[test end]--------\n";
    return ret;
}

void test_memory()
{
    test_func("memory_new",  my_mem::memory_new);
    test_func("memory_news", my_mem::memory_news);
    test_func("smart_ptr",  my_mem::smart_ptr);
}

int main(int argc, char* argv[])
{
    // 标准输入测试
    test_func("io_cin",  my_input::io_cin);
    test_func("io_cout", my_input::io_cout);

    // 引用测试
    test_func("test_quote", my_input::test_quote);

    // 字符串测试
    test_func("stl_string", my_string::stl_string);
    test_func("stl_string", my_string::stl_strings);
    test_func("stl_array",  my_string::stl_array);

    // 指针内存测试
    test_memory();

    return 0;
}


