#ifndef MY_DEMO_H
#define MY_DEMO_H

#include <iostream>
#include "input.h"
#include "string.h"

// 命名空间
namespace io_demo 
{
    int my_variable = 42;

    // 输出
    int test_cout(){
        std::cout << "[io_cout() function]" << std::endl;
        return io_cout();
    }
    // 输入
    int test_cin(){
        std::cout << "[io_cin() function]" << std::endl;
        return io_cin();
    }
    // 字符串
    int test_string(){
        std::cout << "[stl_string() function]" << std::endl;
        return stl_string();
    }
    // 字符串
    int test_strings(){
        std::cout << "[stl_strings() function]" << std::endl;
        return stl_strings();
    }
    // 字符串
    int test_array(){
        std::cout << "[stl_array()   function]" << std::endl;
        return stl_array();
    }
}

#endif 