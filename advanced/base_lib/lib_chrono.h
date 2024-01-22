/**
 * 文件名: Xxx.c
 * 作者: ljk
 * 创建时间: 2023-12-01
 * 文件描述: 
 * 版本: V 1.0.0
 */
#pragma once
#include <chrono>
#include <thread>
#include <iostream>
#include <functional>

/*
1、计时器：
std::chrono::duration: 表示时间间隔的类型，可以通过 std::chrono::duration<Rep, Period> 来创建，其中 Rep 是表示时间间隔的值的类型， Period 是表示时间间隔的单位（如秒、毫秒、微秒等）。
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
std::chrono::duration_cast: 将一个时间间隔转换为不同单位的时间间隔。
*/

namespace mychrono{
using CallbackFuc = std::function<void()>;

// 休眠
void sleep_s(int cnt)
{
    std::cout << "休眠：" << cnt << "S" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(cnt));  
}

// 获取时间
void get_time()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::cout << "当前时间为：" << std::ctime(&now_c) << std::endl;
}

// 回调函数时间测试
void count_time(CallbackFuc callback)
{
    auto start = std::chrono::high_resolution_clock::now();
    // 执行一些代码
    callback();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "执行时间为：" << duration.count() << " 秒" << std::endl;
}

}

