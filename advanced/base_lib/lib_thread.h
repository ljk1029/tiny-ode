/**
 * 文件名: Xxx.c
 * 作者: ljk
 * 创建时间: 2023-12-01
 * 文件描述:
 * 版本: V 1.0.0
 */
#pragma once
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

namespace mythread {
// 锁
std::mutex mtx;
std::condition_variable cv;
bool isDataReady = false;
int sharedData = 0;

// 生产者
void producer(const char *name) {
    while (sharedData < 10) {
        std::this_thread::sleep_for(
            std::chrono::seconds(1)); // 模拟生产数据的耗时操作

        std::lock_guard<std::mutex> lock(mtx);
        sharedData++;
        isDataReady = true;

        std::cout << name << "producer data: " << sharedData << std::endl;

        cv.notify_one(); // 通知消费者线程，数据已准备好
    }
    std::cout << "producer exit" << std::endl;
}

// 消费者
void consumer() {
    static int cnt = 0;
    while (sharedData < 10) {
        if (cnt >= sharedData) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(10)); // 模拟生产数据的耗时操作
        } else {
            std::unique_lock<std::mutex> lock(mtx);

            cv.wait(lock, [] { return isDataReady; }); // 等待数据准备好的通知

            std::cout << "Consumed data: " << sharedData << std::endl;

            cnt = sharedData;
        }
    }
    std::cout << "consumer exit" << std::endl;
}
// 创建
void create_thread() {
    std::thread t1(producer, "thread_");
    std::thread t2(consumer);
    t1.detach();         // 分离式
    if (t2.joinable()) { // 判断线程是否可被合并或分离
        t2.join();       // 等待线程结束
    }
    std::cout << "Shared data: " << sharedData << std::endl;
}

} // namespace mythread
