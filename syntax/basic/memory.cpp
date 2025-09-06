/*
 * 文件名: memory.cpp
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
#include <iostream>
#include <memory>
#include <cstdlib>
#include "my_task.h"
#include <vector>
#include <functional>
#include <string>

class MemoryExample {
public:
    // new/delete演示
    void demo_new_delete() {
        int* p = new int(10);
        std::cout << "new int: " << *p << std::endl;
        delete p;
        p = nullptr;
    }

    // new[]/delete[]演示
    void demo_new_array() {
        int* arr = new int[5];
        for (int i = 0; i < 5; ++i) arr[i] = i * 2;
        for (int i = 0; i < 5; ++i) std::cout << arr[i] << " ";
        std::cout << std::endl;
        delete[] arr;
        arr = nullptr;
    }

    // malloc/free演示
    void demo_malloc_free() {
        int* p = (int*)malloc(sizeof(int) * 3);
        for (int i = 0; i < 3; ++i) p[i] = i + 1;
        for (int i = 0; i < 3; ++i) std::cout << p[i] << " ";
        std::cout << std::endl;
        free(p);
        p = nullptr;
    }

    // 野指针演示
    void demo_dangling() {
        int* p = new int(5);
        delete p;
        // p 变成野指针，访问会出错
        // std::cout << *p << std::endl; // 注释掉，演示时可取消注释
        p = nullptr;
        std::cout << "野指针已置空" << std::endl;
    }

    // 内存泄漏演示
    void demo_leak() {
        int* p = new int(123);
        // 没有delete，内存泄漏
        std::cout << "内存泄漏演示: " << *p << " (未释放)" << std::endl;
        // delete p; // 正确做法
    }

    // RAII思想演示
    void demo_raii() {
        std::vector<int> v = {1,2,3};
        std::cout << "RAII自动释放: " << v.size() << std::endl;
    }

    // 指针初始化演示
    void demo_init() {
        int* p = nullptr;
        if (!p) std::cout << "指针初始化为nullptr" << std::endl;
    }
};


int main() {
    MemoryExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("new/delete演示", [&](){ demo.demo_new_delete(); });
    scheduler.addTask("new[]/delete[]演示", [&](){ demo.demo_new_array(); });
    scheduler.addTask("malloc/free演示", [&](){ demo.demo_malloc_free(); });
    scheduler.addTask("野指针演示", [&](){ demo.demo_dangling(); });
    scheduler.addTask("内存泄漏演示", [&](){ demo.demo_leak(); });
    scheduler.addTask("RAII思想演示", [&](){ demo.demo_raii(); });
    scheduler.addTask("指针初始化演示", [&](){ demo.demo_init(); });
    scheduler.runAll();
    return 0;
}
