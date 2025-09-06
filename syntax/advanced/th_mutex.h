#include <iostream>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <thread>
// unix
#include <unistd.h>
#include <vector>



class LockDemo {
public:
    std::mutex mtx;
    std::condition_variable cv;
    bool is_sata_ready = false;
    int shared_data = 0;
    static constexpr int loop_cnt = 10;

    // 同步 线程函数
    void thread_lock(int n) {
        mtx.lock();
        std::cout << "Hello from the thread:" << n << "\n";
        mtx.unlock();
    }

    // 生产者lock
    void produce_lock() {
        while (shared_data < loop_cnt) {
            std::lock_guard<std::mutex> lock(mtx);
            if (is_sata_ready == false) {
                shared_data++;
                std::cout << "Producer data: " << shared_data << ", lock: " << is_sata_ready << std::endl;
                is_sata_ready = true;
            }
        }
        std::cout << "---produce_lock exit---" << std::endl;
    }

    // 消费者lock
    void consumer_lock() {
        while (shared_data < loop_cnt) {
            std::unique_lock<std::mutex> lock(mtx);
            if (is_sata_ready == true) {
                std::cout << "Consumed data: " << shared_data << ", lock: " << is_sata_ready << std::endl;
                is_sata_ready = false;
            }
        }
        std::cout << "***consumer_lock exit***" << std::endl;
    }

    // 生产者wait
    void producer_wait() {
        while (shared_data < loop_cnt * 2) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::lock_guard<std::mutex> lock(mtx);
            if (is_sata_ready == false)
                shared_data++;
            std::cout << "Producer data: " << shared_data << ", lock: " << is_sata_ready << std::endl;
            is_sata_ready = true;
            cv.notify_all();
        }
        std::cout << "producer_wait exit" << std::endl;
    }

    // 消费者wait
    void consumer_wait() {
        while (shared_data < loop_cnt * 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,
                    [this] {
                        std::cout << "Consumed lock ...: " << is_sata_ready << std::endl;
                        return is_sata_ready;
                    });
            std::cout << "Consumed data: " << shared_data << ", lock: " << is_sata_ready << std::endl;
            is_sata_ready = false;
        }
        std::cout << "consumer_wait exit" << std::endl;
    }

    // 消费者wait_for
    void consumer_waitFor() {
        while (shared_data < loop_cnt * 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait_for(lock, std::chrono::milliseconds(30),
                        [this] { return is_sata_ready; });
            std::cout << "Consumed for data: " << shared_data << ", lock: " << is_sata_ready << std::endl;
            is_sata_ready = false;
        }
        std::cout << "consumer_waitFor exit" << std::endl;
    }
};


// 锁同步线程创建
int main_multi_lock() {
    LockDemo demo;
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(std::thread(&LockDemo::thread_lock, &demo, i + 1));
    }
    for (auto &t : threads) {
        t.join();
    }
    return 0;
}

void main_auto_lock() {
    LockDemo demo;
    std::thread t1(&LockDemo::produce_lock, &demo);
    std::thread t2(&LockDemo::consumer_lock, &demo);
    t1.detach();
    if (t2.joinable()) {
        t2.join();
    }
}

void main_wait_lock() {
    LockDemo demo;
    std::thread t1(&LockDemo::producer_wait, &demo);
    // std::thread t2(&LockDemo::consumer_waitFor, &demo);
    std::thread t3(&LockDemo::consumer_wait, &demo);
    t1.join();
    t3.join();
}