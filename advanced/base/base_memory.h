/*
 * 文件名: memory.h
 * 作者: ljk
 * 创建时间: 2023-09-09
 * 文件描述: 内存操作例程
 *
 * new 和 delete 必须成对使用，new[] 和 delete[] 也必须成对使用
 *
 * std::shared_ptr：允许多个智能指针共享同一块内存，使用引用计数来管理资源的释放。
 * std::unique_ptr：
 * 独占所指向的对象的所有权，确保只有一个智能指针可以访问资源。 std::weak_ptr：
 * 用于协助 std::shared_ptr，不会增加引用计数，避免循环引用。
 */
#ifndef _IO_MEMORY_H__
#define _IO_MEMORY_H__

#include <iostream>
#include <memory>

namespace my_base {
namespace my_mem {

// 开辟单维数组
int memoryNew() {
    int *p1 = new int;
    int *p2 = new int(2);  // 初始化2
    int *p3 = new int[10]; // 开辟10个int
    std::cout << "new int:" << *p1 << std::endl;
    std::cout << "new int(2):" << *p2 << std::endl;
    std::cout << "new int[10]:" << *p3 << std::endl;
    delete p1;
    delete p2;
    delete[] p3;
    return 0;
}

// 开辟多维数组
int memoryNews() {
    int n = 3;
    int *arr = new int[n]; // 创建指向 int* 的指针数组

    std::cout << "int[3]:";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    delete[] arr;
    return 0;
}

// 智能指针
int smartPtr() {
    // 使用 std::shared_ptr
    std::shared_ptr<int> shared_ptr1 = std::make_shared<int>(42);
    std::shared_ptr<int> shared_ptr2 = shared_ptr1; // 共享所有权

    std::cout << "shared_ptr:" << *shared_ptr1 << std::endl;
    std::cout << "shared_ptr:" << *shared_ptr2 << std::endl;

    // 使用 std::unique_ptr
    std::unique_ptr<int> unique_ptr = std::make_unique<int>(99);
    // std::unique_ptr<int> unique_ptr2 = unique_ptr; //
    // 试图复制会引发编译错误，因为它是独占所有权的

    std::cout << "unique_ptr:" << *unique_ptr << std::endl;

    // 在作用域结束时，智能指针会自动释放资源，不需要手动调用 delete
    return 0;
}

// 多维智能指针
int smartPtrs() {
    const size_t n = 10;
    std::shared_ptr<int[]> shared_ptr1(new int[n]);

    // 初始化数组
    for (size_t i = 0; i < n; ++i) {
        shared_ptr1.get()[i] = static_cast<int>(i); // 或者 *(shared_ptr1.get() + i)
    }

    // 打印测试
    for (size_t i = 0; i < n; ++i) {
        std::cout << shared_ptr1[i] << " ";
        std::cout << shared_ptr1.get()[i] << " ";
    }
    std::cout << std::endl; // Should
    return 0;
}

} // namespace my_mem
} // namespace my_base

#endif