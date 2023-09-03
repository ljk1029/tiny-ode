#ifndef MY_VERCTOR_H
#define MY_VERCTOR_H

// 包含必要的标准库头文件
#include <iostream>
#include <string>

// 使用命名空间
using namespace std;

// 类的声明
class MyClass {
public:
    MyClass();          // 构造函数声明
    ~MyClass();         // 析构函数声明

    void SomeFunction(int param1, const string& param2); // 函数原型

    // 其他成员变量和函数声明
private:
    int myPrivateVariable;
};

// 全局常量声明
const int MY_CONSTANT = 42;

#endif // MY_HEADER_H
