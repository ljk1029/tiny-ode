#ifndef _IO_INPUT_H_
#define _IO_INPUT_H_
#include <iostream>
#include <string>

namespace my_input{
// 输出
int io_cout()
{
    int number = 10;
    std::string name = "lixiang";

    std::cout << "hehua &";
    std::cout << "heye; " << std::endl;
    std::cout << number << "," << name << std::endl;
    return 0;
}

// 输入
int io_cin()
{
    int number;
    std::string name;

    std::cout << "请输入一个整数:";
    std::cin  >> number;
    std::cout << "请输入一个字符串:";
    std::cin.ignore(); //忽略回车
    getline(std::cin, name);

    std::cout << "你输入的整数是:   " << number << std::endl;
    std::cout << "你输入的字符串是: " << name   << std::endl;
    return 0;
}

int my_variable = 42;

// 引用测试
int test_quote(){
    std::cout << "[引用测试 function]" << std::endl;
    int &a = my_variable;
    std::cout << "value:   " << a  << " & " << my_variable  << std::endl;
    std::cout << "address: " << &a << " & " << &my_variable << std::endl;
    return 0;
}

}

#endif 



