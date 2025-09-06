/*
 * 文件名: my_io.h
 * 作者: ljk
 * 创建时间: 2023-09-09
 * 文件描述: 调试例程
 */
#include "my_io.h"
#include "my_task.h"


int main() {
    IOExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("输出测试", [&](){ demo.demo_cout(); });
    scheduler.addTask("格式化输出", [&](){ demo.demo_format(); });
    // 如需交互输入可取消注释
    // scheduler.addTask("输入测试", [&](){ demo.demo_cin(); });
    // scheduler.addTask("getline测试", [&](){ demo.demo_getline(); });
    scheduler.addTask("引用测试", [&](){ demo.demo_quote(); });
    scheduler.addTask("文本文件读写", [&](){ demo.demo_fstream(); });
    scheduler.addTask("文件追加写入", [&](){ demo.demo_fstream_append(); });
    scheduler.addTask("二进制文件读写", [&](){ demo.demo_fstream_bin(); });
    scheduler.addTask("错误处理演示", [&](){ demo.demo_error(); });
    scheduler.addTask("C风格IO演示", [&](){ demo.demo_cstdio(); });
    scheduler.addTask("字符串流演示", [&](){ demo.demo_sstream(); });
    scheduler.runAll();
    return 0;
}


