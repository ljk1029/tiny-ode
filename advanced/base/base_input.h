#ifndef _IO_INPUT_H_
#define _IO_INPUT_H_
#include <iostream>
#include <string>

namespace my_base {
namespace my_input {

// 输出测试
int ioCout() {
    int number = 10;
    std::string name = "lihua";

    std::cout << "hello &\n";
    std::cout << "heye" << std::endl;
    std::cout << number << "," << name << std::endl;
    return 0;
}

// 输入测试
int ioCin() {
    int number;
    std::string name;

    std::cout << "请输入一个整数:";
    std::cin >> number;
    std::cout << "请输入一个字符串:";
    std::cin.ignore(); //忽略回车
    getline(std::cin, name);

    std::cout << "你输入的整数是: " << number << std::endl;
    std::cout << "你输入的字符串是: " << name << std::endl;
    return 0;
}

// 引用测试
int valueQuote() {
    std::cout << "[引用测试 function]" << std::endl;
    int my_value  = 42;
    int &my_quote = my_value;
    std::cout << "value:   " << my_value << " & " << &my_value << std::endl;
    std::cout << "quote: "   << my_quote << " & " << &my_quote << std::endl;
    return 0;
}

} // namespace my_input
} // namespace my_base

#endif
