#include <iostream>
#include "th_atomic.h"


template<typename Func>
void run_task(const std::string& title, Func&& func) {
    std::cout << "[开始执行] " << title << std::endl;
    func();
    std::cout << "[结束执行] " << title << "\n" << std::endl;
}

int main(int argc, char* argv[]) {
    AtomicDemo demo;
    run_task("atomic producer/consumer", [&](){ main_atomic(); });
    run_task("atomic_int_add", [&](){ demo.atomic_int_add(); });
    run_task("atomic_ptr_demo", [&](){ demo.atomic_ptr_demo(); });
    run_task("atomic_flag_demo", [&](){ demo.atomic_flag_demo(); });
    run_task("atomic_compare_exchange_demo", [&](){ demo.atomic_compare_exchange_demo(); });
    run_task("atomic_fetch_bitops_demo", [&](){ demo.atomic_fetch_bitops_demo(); });
    run_task("atomic_thread_fence_demo", [&](){ demo.atomic_thread_fence_demo(); });
    return 0;
}