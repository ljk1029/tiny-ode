/*
 * 文件名: memory.cpp
 * 作者: ljk
 * 创建时间: 2023-09-09
 * 文件描述: 内存操作例程
 * 
 * new 和 delete 必须成对使用，new[] 和 delete[] 也必须成对使用
 * 
 * std::shared_ptr：允许多个智能指针共享同一块内存，使用引用计数来管理资源的释放。
 * std::unique_ptr： 独占所指向的对象的所有权，确保只有一个智能指针可以访问资源。
 * std::weak_ptr：  用于协助 std::shared_ptr，不会增加引用计数，避免循环引用。
*/
#include <iostream>
#include <memory>
#include "memory.h"



// 开辟单维数组
int memory_new()
{
    int *p1 = new int;
    int *p2 = new int(2);  // 初始化2
    int *p3 = new int[10]; // 开辟10个int

    delete p1;
    delete p2;
    delete[] p3;
    return 0;
}

// 开辟多维数组
int memory_news()
{
    // 创建一个二维整数数组
    int* arr = new int[3]; // 创建指向 int* 的指针数组

    delete[] arr; // 释放指针数组
    return 0;
}

// 智能指针
int smart_ptr() 
{
    // 使用 std::shared_ptr
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(42);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1; // 共享所有权

    std::cout << "shared_ptr:" << *sharedPtr1 << std::endl;
    std::cout << "shared_ptr:" << *sharedPtr2 << std::endl;

    // 使用 std::unique_ptr
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(99);
    // std::unique_ptr<int> uniquePtr2 = uniquePtr; // 试图复制会引发编译错误，因为它是独占所有权的

    std::cout << "unique_ptr:" << *uniquePtr << std::endl;

    // 在作用域结束时，智能指针会自动释放资源，不需要手动调用 delete
    return 0;
}  