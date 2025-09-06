#include <iostream>
#include <csignal>
#include <thread>
#include <atomic>
#include <unistd.h>

class SignalDemo {
public:
    static std::atomic<bool> signal_received;

    // 信号处理函数
    static void handle_signal(int signum) {
        std::cout << "Received signal: " << signum << std::endl;
        signal_received = true;
    }

    // 注册信号
    void demo_register() {
        std::signal(SIGINT, SignalDemo::handle_signal);
        std::cout << "Registered SIGINT handler. Press Ctrl+C to trigger." << std::endl;
        for (int i = 0; i < 5 && !signal_received; ++i) {
            std::cout << "Waiting..." << std::endl;
            sleep(1);
        }
        if (signal_received) std::cout << "Signal handled!" << std::endl;
        else std::cout << "No signal received." << std::endl;
    }

    // 主动发送信号
    void demo_raise() {
        std::signal(SIGUSR1, SignalDemo::handle_signal);
        std::cout << "Send SIGUSR1 to self." << std::endl;
        std::raise(SIGUSR1);
        if (signal_received) std::cout << "SIGUSR1 handled!" << std::endl;
    }

    // 线程与信号交互
    void demo_thread_signal() {
        std::signal(SIGTERM, SignalDemo::handle_signal);
        std::thread t([](){
            std::cout << "Thread running, will send SIGTERM in 2s..." << std::endl;
            sleep(2);
            std::raise(SIGTERM);
        });
        for (int i = 0; i < 5 && !signal_received; ++i) {
            std::cout << "Main waiting..." << std::endl;
            sleep(1);
        }
        t.join();
        if (signal_received) std::cout << "SIGTERM handled in main!" << std::endl;
    }
};

std::atomic<bool> SignalDemo::signal_received{false};

int main() {
    SignalDemo demo;
    std::cout << "[开始执行] 信号注册与处理" << std::endl;
    demo.demo_register();
    std::cout << "[结束执行] 信号注册与处理" << std::endl;

    std::cout << "\n[开始执行] 主动发送信号" << std::endl;
    demo.demo_raise();
    std::cout << "[结束执行] 主动发送信号" << std::endl;

    std::cout << "\n[开始执行] 线程与信号交互" << std::endl;
    demo.demo_thread_signal();
    std::cout << "[结束执行] 线程与信号交互" << std::endl;
    return 0;
}
