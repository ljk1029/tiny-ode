
/**
 * 文件名: my_time.cpp
 * 作者: ljk
 * 创建时间: 2023-12-01
 * 文件描述:
 * 版本: V 1.0.0
 */
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>

/*
1、计时器：
    std::chrono::duration: 表示时间间隔的类型，可以通过 std::chrono::duration<Rep, Period> 来创建，其中
    Rep: 是表示时间间隔的值的类型， 
    Period: 是表示时间间隔的单位（如秒、毫秒、微秒等）。 
    std::chrono::steady_clock: 稳定时钟，用于测量经过的时间。 
    std::chrono::high_resolution_clock: 高精度时钟，提供更高精度的时间测量。 
    std::chrono::system_clock: 系统时钟，表示实时时钟。 

2、等待一段时间： 
    std::this_thread::sleep_for: 使当前线程暂停执行一段时间。

3、获取当前时间： 
    std::chrono::system_clock::now(): 获取当前系统时钟的时间点。 
    std::chrono::steady_clock::now(): 获取当前稳定时钟的时间点。 
    std::chrono::high_resolution_clock::now(): 获取当前高精度时钟的时间点。

4、时间转换： 
    std::chrono::duration_cast:将一个时间间隔转换为不同单位的时间间隔。
*/


class TimeDemo {
public:
    // 获取当前时间戳
    void demo_now() {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::cout << "当前时间戳: " << t << std::endl;
    }

    // 格式化输出当前时间
    void demo_format() {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::cout << "格式化时间: " << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S") << std::endl;
    }

    // 计时器
    void demo_timer() {
        auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        auto end = std::chrono::high_resolution_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "计时器: " << ms << " ms" << std::endl;
    }

    // 休眠
    void demo_sleep() {
        std::cout << "休眠1秒..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "休眠结束" << std::endl;
    }

    // chrono各种单位
    void demo_chrono_units() {
        auto now = std::chrono::system_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        auto us = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
        std::cout << "毫秒: " << ms << ", 微秒: " << us << ", 纳秒: " << ns << std::endl;
    }
};

template<typename Func>
void run_task(const std::string& title, Func&& func) {
    std::cout << "[开始执行] " << title << std::endl;
    func();
    std::cout << "[结束执行] " << title << "\n" << std::endl;
}

int main() {
    TimeDemo demo;
    run_task("当前时间戳", [&](){ demo.demo_now(); });
    run_task("格式化时间", [&](){ demo.demo_format(); });
    run_task("计时器", [&](){ demo.demo_timer(); });
    run_task("休眠", [&](){ demo.demo_sleep(); });
    run_task("chrono单位", [&](){ demo.demo_chrono_units(); });
    return 0;
}

