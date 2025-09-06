/*
 * 文件名: my_ptr.cpp
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
#include "my_ptr.h"
#include "my_task.h"
#include <vector>
#include <functional>
#include <string>

int main() {
    SmartPtrExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("shared_ptr/unique_ptr演示", [&](){ demo.demo_basic(); });
    scheduler.addTask("weak_ptr演示", [&](){ demo.demo_weak(); });
    scheduler.addTask("智能指针数组演示", [&](){ demo.demo_array(); });
    scheduler.addTask("循环引用问题演示", [&](){ demo.demo_cycle(); });
    scheduler.addTask("get/reset演示", [&](){ demo.demo_get_reset(); });
    scheduler.runAll();
    return 0;
}


