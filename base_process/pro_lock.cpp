#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
/**
 * 1、注意wait执行是会释放所有锁，直到返回值为true才重新获取锁
 * 2、std::lock_guard<std::mutex> lock(mtx); 会获取锁保护作用区，
 *    但特例是和wait一起使用时，不管锁是释放还是使用状态，都会执行到wait
 *    (1) 锁被其他线程占用，返回false(一般全局变量，用来做状态)，wait会阻塞，等待notify_all通知后或者使用wait_for超时，再次返回true，执行后续
 *    (2) 锁被释放，返回true，执行后续
*/


// 锁
std::mutex mtx;
std::condition_variable cv;
bool isDataReady = false;
int sharedData = 0;
constexpr int loop_cnt = 10;

// 生产者lock
void producer_lock(const char* name) {
    while( sharedData < loop_cnt){
        std::lock_guard<std::mutex> lock(mtx);
        if(isDataReady == false){
            sharedData++;
            std::cout << name << "producer data: " << sharedData << ",lock: "<< isDataReady << std::endl;
            isDataReady = true;
            //std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟生产数据的耗时操作
        }
    }
    std::cout << "producer exit" << std::endl;
}

// 消费者lock
void consumer_lock() {
    while( sharedData < loop_cnt ){
        std::unique_lock<std::mutex> lock(mtx);
        if(isDataReady == true){
            std::cout << "Consumed data: " << sharedData << ", lock: "<< isDataReady << std::endl;
            isDataReady = false;
        }else{
            //std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 模拟生产数据的耗时操作
        }
    }
    std::cout << "consumer exit" << std::endl;
}

// 生产者wait
void producer_wait(const char* name) {
    while( sharedData < loop_cnt*2){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(mtx);
        if(isDataReady == false)
            sharedData++;
        std::cout << name << "producer data: " << sharedData  << ", lock: "<< isDataReady << std::endl;
        isDataReady = true;
        //cv.notify_one(); // 通知消费者线程，数据已准备好
        cv.notify_all();
        //cv.native_handle();
    }
    std::cout << "producer exit" << std::endl;
}

// 消费者wait
void consumer_wait() {
    while( sharedData < loop_cnt*2 ){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] {  // 等待时释放所有锁, 一旦条件满足（本例中是isDataReady == true），条件变量会唤醒等待的线程，然后再次尝试获得互斥锁。
            std::cout << "Consumed lock ...: " << isDataReady << std::endl;
            return isDataReady; }); // 等待数据准备好的通知
        std::cout << "Consumed data: " << sharedData  << ", lock: "<< isDataReady << std::endl;
        isDataReady = false;
    }
    std::cout << "consumer exit" << std::endl;
}

// 消费者wait_for
void consumer_wait_for() {
    while( sharedData < loop_cnt*2 ){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait_for(lock, std::chrono::milliseconds(30), [] { return isDataReady; }); // 等待数据准备好的通知或超过固定时间
        std::cout << "Consumed for data: " << sharedData  << ", lock: "<< isDataReady << std::endl;
        isDataReady = false;
    }
    std::cout << "consumer exit" << std::endl;
}

void test_lock(){
    std::thread t1(producer_lock, "thread_");
    std::thread t2(consumer_lock);
    t1.detach(); // 分离式
    if (t2.joinable()) { // 判断线程是否可被合并或分离
        t2.join();       // 等待线程结束
    }
}

void test_wait(){
    std::thread t3(producer_wait, "thread_");
    std::thread t4(consumer_wait_for);
    t3.join();
    t4.join();
}

// 测试
int main() {
    test_wait();
    return 0;
}