#ifndef MY_DEMO_H
#define MY_DEMO_H

#include <iostream>
#include "input.h"


namespace io_demo 
{
    int myVariable = 42;

    // 输出
    int test_cout()
    {
        std::cout << "[io_cout() function]" << std::endl;
        return io_cout();
    }
    // 输入
    int test_cin()
    {
        std::cout << "[io_cin() function]" << std::endl;
        return io_cin();
    }
    // 字符串
    int test_string()
    {
        std::cout << "[io_string() function]" << std::endl;
        return io_string();
    }
    // 字符串
    int test_strings()
    {
        std::cout << "[io_strings() function]" << std::endl;
        return io_string();
    }
}



#endif 