#include <iostream>
#include "th_mutex.h"


template<typename Func>
void run_task(const std::string& title, Func&& func) {
    std::cout << "[开始执行] " << title << std::endl;
    func();
    std::cout << "[结束执行] " << title << "\n" << std::endl;
}

int main(int argc, char* argv[]) {
    run_task("lock 多线程", [&](){ main_multi_lock(); });
    run_task("wait/notify 线程同步", [&](){ main_wait_lock(); });
    return 0;
}