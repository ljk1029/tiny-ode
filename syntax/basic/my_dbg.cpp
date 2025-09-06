/*
 * 文件名: my_debug.cpp
 * 作者: ljk
 * 创建时间: 2023-09-09
 * 文件描述: 调试例程
 */
#include "my_dbg.h"
#include "my_task.h"


int main() {
    DebugExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("try/catch调试", [&](){ demo.demo_try(); });
    scheduler.addTask("断言演示", [&](){ demo.demo_assert(); });
    scheduler.addTask("日志宏演示", [&](){ demo.demo_log(); });
    scheduler.addTask("自定义异常演示", [&](){ demo.demo_custom_exception(); });
    scheduler.addTask("标准异常演示", [&](){ demo.demo_std_exception(); });
    scheduler.runAll();
    return 0;
}

