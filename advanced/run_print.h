#ifndef _MY_PRINT_H__
#define _MY_PRINT_H__

#include <iostream>
#include <functional>
#include <string>
#include <thread>
#include <cstring>
#include <algorithm>

/**
 * print：格式化参数打印， 如 print(a, "123", 54);
 * prtints: 格式化打印带， 比print多了调试信息
 * TestRunner test_runner(argc, argv)： 根据输入选择测试项目
 */
namespace my_base {
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

// 1、打印封装
#if TRUE
// 递归终止函数，当参数列表为空时结束调用
void _print() { std::cout << std::endl; }

// 特殊处理指针类型，其中包括空指针的判断
template <typename T> typename std::enable_if<std::is_pointer<T>::value, void>::type _print(const T &value) {
    if (value) {
        std::cout << value;
    } else {
        std::cout << "nullptr ";
    }
}

// 处理非指针类型
template <typename T> typename std::enable_if<!std::is_pointer<T>::value, void>::type _print(const T &value) {
    std::cout << value;
}

// 变参模板递归展开
template <typename T, typename... Args> void _print(const T &first, const Args &... args) {
    _print(first);
    _print(args...); // 递归调用，知道参数包展开完毕
}

template <typename... Args> void print(const Args &... args) {
    _print(args...);
    std::cout << std::endl;
}
#else
// 递归终止函数，当参数列表为空时结束调用
void print() { std::cout << std::endl; }

// 变参模板递归展开
template <typename T, typename... Args> void print(const T &first, const Args &... args) {
    if (std::is_pointer<T>::value && first == false)
        std::cout << "nullptr";
    else
        std::cout << first;
    print(args...); // 打印换行
}
#endif

// 一个跨平台模板
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
// Include the header required for getting the process ID on Windows
#include <windows.h>
#define GET_PID() static_cast<long>(GetCurrentProcessId())
#elif defined(__unix__) || defined(__unix) || defined(__APPLE__) || defined(__MACH__) || defined(__linux__) ||         \
    defined(__linux)
// For UNIX-based operating systems
#include <unistd.h>
#define GET_PID() static_cast<long>(getpid())
#else
#error "Unsupported platform"
#endif

// 定义一个宏来简化 print 函数调用
#define prints(...)                                                                                                    \
    do {                                                                                                               \
        std::cout << "[" << __FILE__ << ":" << __LINE__ << " " << __func__ << "] pid: " << GET_PID()                   \
                  << ", tid: " << std::this_thread::get_id() << ", ";                                                  \
        print(__VA_ARGS__);                                                                                            \
    } while (0)

// 2、运行测试类
class TestRunner {
#define PRINT_ARGV()                                                                                                   \
    std::cout << "run all:" << (run_in_all ? "yes" : "no") << std::endl;                                               \
    std::cout << "run case:" << run_cases << std::endl;

public:
    TestRunner()
        : run_in_all(false), run_cases(""){PRINT_ARGV()}

          TestRunner(int argc, char *argv[]) {
        run_in_all = cmdOptionExists(argv, argv + argc, "-all");
        run_cases = getCmdOption(argv, argv + argc, "-case");
        PRINT_ARGV()
    }

    // 定义回调函数模板
    template <typename ReturnType> using CallbackFunc = std::function<ReturnType()>;

    // 非void返回类型的泛型函数打印重载
    template <typename ReturnType> ReturnType funcPrint(const std::string &title, CallbackFunc<ReturnType> callback) {
        printFunTitle(title, true);
        ReturnType ret = callback();
        printFunTitle(title, false);
        print("callback ret:", ret);
        return ret;
    }

    // void返回类型的泛型函数打印重载
    void funcPrint(const std::string &title, CallbackFunc<void> callback) {
        printFunTitle(title, true);
        callback();
        printFunTitle(title, false);
    }

    // 获取运行状态
    bool getRunStatus(const std::string &option) { return run_in_all || run_cases.find(option) != std::string::npos; }

    bool getRunStatus(char option) {
        std::string str_option(1, option);
        return getRunStatus(str_option);
    }

private:
    // 参数获取
    std::string getCmdOption(char **begin, char **end, const std::string &option) {
        char **itr = std::find(begin, end, option);
        if (itr != end && ++itr != end) {
            return *itr;
        }
        return "";
    }

    bool cmdOptionExists(char **begin, char **end, const std::string &option) {
        return std::find(begin, end, option) != end;
    }

    // 打印标题
    static void printFunTitle(const std::string &title, bool start_mode) {
        // 总打印长度，计算边框长度
        const int TOTAL_PRINT_LENGTH = 64;
        int border_len = (TOTAL_PRINT_LENGTH - title.length() - 10) / 2;
        if (border_len < 0) {
            border_len = 0;
        }
        std::string border(border_len, start_mode ? '=' : '-');
        std::cout << border;
        std::cout << "[test " << title << (start_mode ? " start]" : "   end]");
        std::cout << border;
        std::cout << (start_mode ? "\n" : "\n\n");
    }

private:
    bool run_in_all;
    std::string run_cases;
};

} // namespace my_base

#endif