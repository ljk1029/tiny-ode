//new 和 delete 必须成对使用，new[] 和 delete[] 也必须成对使用

#include <iostream>
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