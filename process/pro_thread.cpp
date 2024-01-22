#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// unix
#include <unistd.h>



// 锁
std::mutex mtx;
std::condition_variable cv;
bool isDataReady = false;  //这里做的是起始信号
int sharedData = 0;

// 生产者
void producer(const char* name) {
    while( sharedData < 10){
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟生产数据的耗时操作

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
    while( sharedData < 10 ){
        if(cnt >= sharedData)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 模拟生产数据的耗时操作
        }
        else{
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
    t1.detach(); // 分离式
    if (t2.joinable()) { // 判断线程是否可被合并或分离
        t2.join();       // 等待线程结束
    }
    std::cout << "Shared data: " << sharedData << std::endl;
}

// 不带参数 做为线程函数
void thread_function1() {
    std::cout << "Hello from the thread!\n";
}

// 带参数 做为线程函数
void thread_function(const char* message) {
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Hello from the thread:" << message << "\n";
}

// 类 做为线程函数
class Thread_c {
public:
    void operator()() const {
        std::cout << "Hello from the thread class operator!\n";
    }

    void thread_function() const {
        std::cout << "Hello from the thread member function!\n";
    }
};

// 不带参数
int thread_create_fun1() {
    std::thread t(thread_function1);
    t.join();
    return 0;
}

// 创建线程并使用lambda表达式
int thread_create_fun2() {
    std::thread t([]() {
        std::cout << "Hello from the lambda thread!\n";
    });
    t.join();
    return 0;
}

// 带一个参数
int thread_create_fun3() {
    const char* message = "with parameters!";
    std::thread t(thread_function, message);
    t.join();
    return 0;
}

// 分离式detach
int thread_create_fun4() {
    const char* message = "with detach!";
    std::thread t(thread_function, message);
    t.detach();
    std::cout << "Main thread is done with detach!\n";
    // 延迟，以便看到分离线程的输出
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}

// 类线程函数
int thread_create_fun5() {
    Thread_c hello;
    // 使用函数对象创建线程
    std::thread t1(hello);
    // 使用成员函数创建线程
    std::thread t2(&Thread_c::thread_function, &hello);
    t1.join();
    t2.join();
    return 0;
}

// 获取ID
int thread_create_fun6() {
    std::cout << "Process ID:" << getpid() << ", Thread ID: " << std::this_thread::get_id() << std::endl;
    std::thread t([]() {
        std::thread::id id = std::this_thread::get_id();
        std::cout << "Thread ID: " << id << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(10));
    });
    t.join();
    return 0;
}

// 同步 线程函数
void thread_function2(int n) {
    mtx.lock();
    std::cout << "Hello from the thread:" << n << "\n";
    mtx.unlock();
}

// 锁同步
int thread_create_fun7() {
    int n = 10;
    std::thread threads[n];
    for (int i = 0; i < n; ++i) {
        threads[i] = std::thread(thread_function2, i + 1);
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}

// 线程转移
int thread_create_fun8() {
    const char* message = "with move!";
#if 1
    std::thread t1(thread_function, message);
    std::thread t2 = std::move(t1);
    t2.join();
#else
    std::thread t1(thread_function, "move 1");
    std::thread t2(thread_function, "move 2");
    t2 = std::move(t1);//t1已关联一个线程，再赋值会调用std::terminate()终止程序 线程转移关关联
    t1.join();
    t2.join();
#endif
    return 0;
}

// 测试
int main(int arg, char* argv[]) {
    thread_create_fun1();
    thread_create_fun2();
    thread_create_fun3();
    thread_create_fun4();
    thread_create_fun5();
    thread_create_fun6();
    thread_create_fun7();
    thread_create_fun8();
    return 0;
}