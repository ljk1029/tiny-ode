#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
/**
 * 1、注意wait执行是会释放所有锁，直到返回值为true才重新获取锁
 * 2、std::lock_guard<std::mutex> lock(mtx); 会获取锁保护作用区，
 *    但特例是和wait一起使用时，不管锁是释放还是使用状态，都会执行到wait
 *    (1)
 * 锁被其他线程占用，返回false(一般全局变量，用来做状态)，wait会阻塞，等待notify_all通知后或者使用wait_for超时，再次返回true，执行后续
 *    (2) 锁被释放，返回true，执行后续
 */

// 锁
std::mutex mtx;
std::condition_variable cv;
static int loop_cnt{0}; // 锁中被打断
static bool is_data_ready{false};
constexpr int loop_exit_cnt = 100;

// 1、锁竞争测试
// 生产者lock
void producer_lock() {
    while (loop_cnt < loop_exit_cnt) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::lock_guard<std::mutex> lock(mtx);
        loop_cnt++;
        std::cout << "Producer data start: " << loop_cnt << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Producer data end  : " << loop_cnt << std::endl;
        loop_cnt++;
    }
    std::cout << "Producer exit" << std::endl;
}

// 消费者lock
void consumer_lock() {
    while (loop_cnt < loop_exit_cnt) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::unique_lock<std::mutex> lock(mtx);
        if (loop_cnt % 2) {
            std::cout << "Consumed data: illegal lock acquisition: " << loop_cnt
                      << std::endl;
            std::exit(1);
        }
        std::cout << "Consumed data: *********\n";
    }
    std::cout << "Consumer exit" << std::endl;
}

// 2、条件等待
// 生产者wait
void producer_wait() {
    while (loop_cnt < loop_exit_cnt) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(mtx);
        if (is_data_ready == false) {
            std::cout << "Producer_wait data: " << loop_cnt << ", no lock\n";
            is_data_ready = true;
            loop_cnt += 10;
        } else {
            // std::cout << "Producer_wait  data: " << loop_cnt << ", lock\n";
        }
        cv.notify_all();
    }
    std::cout << "Producer_wait  exit" << std::endl;
}

// 消费者wait
void consumer_wait() {
    while (loop_cnt < loop_exit_cnt) {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << std::boolalpha << "Consumed_wait lock: " << loop_cnt
                  << ", " << is_data_ready << std::endl;
        // cv.wait_for(lock, std::chrono::milliseconds(30), [] {
        cv.wait(lock, [] {
            std::cout << "Consumed_wait wait: " << loop_cnt << ", "
                      << is_data_ready << std::endl;
            return is_data_ready;
        });
        std::cout << "Consumed_wait data: " << loop_cnt << ", " << is_data_ready
                  << std::endl;
        is_data_ready = false;
    }
    std::cout << std::noboolalpha << "Consumer exit" << std::endl;
}

void test_lock() {
    loop_cnt = 0;
    std::thread t1(producer_lock);
    std::thread t2(consumer_lock);
    t2.join();
    t1.join();
}

void test_wait() {
    loop_cnt = 0;
    std::thread t3(producer_wait);
    std::thread t4(consumer_wait);
    t3.join();
    t4.join();
}

// 测试
int main() {
    test_lock();
    test_wait();
    return 0;
}