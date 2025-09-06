#include <iostream>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <thread>
// unix
#include <unistd.h>
#include <vector>

/**
 * atomic 原子操作
 * std::atomic_bool：表示一个原子布尔类型的变量，支持原子操作。
 * std::atomic<int>：表示一个原子整数类型的变量，支持原子操作。
 * std::atomic<T*>：表示一个原子指针类型的变量，支持原子操作。
 * std::atomic_flag：表示一个原子标志，通常用于实现轻量级的锁。
 * std::atomic_thread_fence：用于在多线程环境中创建内存屏障，确保特定的内存操作顺序。
 * std::atomic_compare_exchange_strong 和 std::atomic_compare_exchange_weak：用于实现原子比较并交换操作。
 * std::atomic_fetch_add、std::atomic_fetch_sub、std::atomic_fetch_and、std::atomic_fetch_or、std::atomic_fetch_xor：用于实现原子算术和位操作。
 */


class AtomicDemo {
public:
    std::atomic_bool data_ready{false};
    std::atomic<int> shared_data{0};

    // 生产者线程
    void atomic_producer() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        shared_data.store(100);
        std::cout << "Producer: Data produced.\n";
        data_ready.store(true);
    }

    // 消费者线程
    void atomic_consumer() {
        while (!data_ready.load()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        std::cout << "Consumer: Data consumed: " << shared_data.load() << "\n";
    }

    // 原子整数加法
    void atomic_int_add() {
        std::atomic<int> value(0);
        value.fetch_add(10);
        std::cout << "atomic_int_add: " << value.load() << std::endl;
    }

    // 原子指针
    void atomic_ptr_demo() {
        int x = 5;
        std::atomic<int*> ptr(&x);
        int y = 10;
        ptr.store(&y);
        std::cout << "atomic_ptr_demo: *ptr = " << *ptr.load() << std::endl;
    }

    // atomic_flag 用法
    void atomic_flag_demo() {
        static std::atomic_flag flag = ATOMIC_FLAG_INIT;
        if (!flag.test_and_set()) {
            std::cout << "atomic_flag_demo: first set" << std::endl;
        } else {
            std::cout << "atomic_flag_demo: already set" << std::endl;
        }
        flag.clear();
    }

    // atomic_compare_exchange 用法
    void atomic_compare_exchange_demo() {
        std::atomic<int> value(100);
        int expected = 100;
        if (value.compare_exchange_strong(expected, 200)) {
            std::cout << "atomic_compare_exchange: success, value = " << value.load() << std::endl;
        } else {
            std::cout << "atomic_compare_exchange: failed, expected = " << expected << std::endl;
        }
    }

    // atomic_fetch_and/or/xor
    void atomic_fetch_bitops_demo() {
        std::atomic<int> value(0b1010);
        value.fetch_and(0b1100);
        std::cout << "atomic_fetch_and: " << value.load() << std::endl;
        value.fetch_or(0b0011);
        std::cout << "atomic_fetch_or: " << value.load() << std::endl;
        value.fetch_xor(0b1111);
        std::cout << "atomic_fetch_xor: " << value.load() << std::endl;
    }

    // atomic_thread_fence 用法
    void atomic_thread_fence_demo() {
        std::atomic<int> value(0);
        value.store(1);
        std::atomic_thread_fence(std::memory_order_seq_cst);
        std::cout << "atomic_thread_fence: " << value.load() << std::endl;
    }
};

// atomic 生产者消费者
int main_atomic() {
    AtomicDemo demo;
    std::thread t1(&AtomicDemo::atomic_producer, &demo);
    std::thread t2(&AtomicDemo::atomic_consumer, &demo);
    t1.join();
    t2.join();
    return 0;
}
