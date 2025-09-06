#include <unistd.h>
#ifndef THREAD_DEMO_H
#define THREAD_DEMO_H
#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <future>
#include <atomic>
#include <mutex>


// 进程ID、线程ID
#define GET_PID() std::cout << "Process ID: " << getpid() << std::endl
#define GET_TID() std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl
#define FUNC_NAME() std::cout << "\n[" << __func__ << " test]" << std::endl

class ThreadDemo {
public:
    // 简单线程创建
    void demo_simple() {
        GET_PID();
        GET_TID();
        FUNC_NAME();
        std::thread t([](){ 
            std::cout << "Hello from thread!" << std::endl; 
            GET_TID();
        });
        t.join();
    }

    // 带参数线程
    void demo_with_args(int x) {
        std::thread t([x](){ std::cout << "Thread arg: " << x << std::endl; });
        t.join();
    }

    // 多线程并发
    void demo_multi_threads() {
        std::vector<std::thread> threads;
        for (int i = 0; i < 5; ++i) {
            threads.emplace_back([i](){ std::cout << "Thread " << i << std::endl; });
        }
        for (auto& t : threads) t.join();
    }

    // 线程成员函数
    void member_func(int id) {
        std::cout << "Thread member_func: " << id << std::endl;
    }
    void demo_member_func() {
        std::thread t(&ThreadDemo::member_func, this, 42);
        t.join();
    }

    // 线程返回值 future
    void demo_return_value() {
        auto func = [](){ return 123; };
        std::packaged_task<int()> task(func);
        std::future<int> result = task.get_future();
        std::thread t(std::move(task));
        t.join();
        std::cout << "Thread return value: " << result.get() << std::endl;
    }

    // 只执行一次（线程安全）
    void demo_once_flag() {
        std::once_flag onceFlag;
        auto initialize = [](){
            std::cout << "Initialize function called once" << std::endl;
        };
        std::vector<std::thread> threads;
        for (int i = 0; i < 5; ++i) {
            threads.emplace_back([i, &onceFlag, &initialize](){
                std::cout << "Hello from the process: " << i << std::endl;
                std::call_once(onceFlag, initialize);
                std::cout << "Hello from the process after: " << i << std::endl;
            });
        }
        for (auto& t : threads) t.join();
    }
};

#endif // THREAD_DEMO_H
