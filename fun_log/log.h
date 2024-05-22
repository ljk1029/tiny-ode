#ifndef _LOG_TOOL_H__
#define _LOG_TOOL_H__

#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/types.h>
#include <thread>
#include <unistd.h>

namespace log_tool {
// 日志路径
constexpr const char *log_file{"./log.txt"};
const unsigned int log_switch{3U};
enum class LogLevel : unsigned int { kDebug = 1, kInfo = 2, kWarn = 3, kError = 4 };

// 打印颜色
/*
const char buffer_red[8]    = {'\033', '[', '1', ';', '3', '1', 'm'}; // 红色
const char buffer_yellow[8] = {'\033', '[', '1', ';', '3', '3', 'm'}; // 黄色
const char buffer_end[5]    = {'\033', '[', '0', 'm'};
*/
// 打印颜色，注意数组大小要加一来包含空终止符 '\0'
const char buffer_red[] = "\033[1;31m";    // 红色
const char buffer_yellow[] = "\033[1;33m"; // 黄色
const char buffer_end[] = "\033[0m";       // 重置颜色

// 设置控制颜色
int log_colour_set() {
    std::puts(buffer_yellow);
    std::puts("set console yellow");
    std::puts(buffer_end);

    std::puts(buffer_red);
    std::cout << "set console red" << std::endl;
    std::puts(buffer_end);
    return 0;
}

// 多参数日志
template <typename... Args> int log(int level, const Args &... args) {
    // 获取当前时间
    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::tm tm_now = *std::localtime(&time_now);

    // 获取线程号
    std::stringstream ss_thread;
    ss_thread << std::this_thread::get_id();
    std::string thread_id = ss_thread.str();

    // 获取进程号
    pid_t process_id = getpid();

    // 打印日志
    if (log_switch & 0x01U) {
        // 输出日期、线程号和进程号到终端
        std::cout << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S") << " ";
        std::cout << "Process ID: " << process_id << " ";
        std::cout << "Thread: " << thread_id << " ";
        std::cout << "Level_" << level << ": ";
        (std::cout << ... << args);
        std::cout << std::endl;
    }

    // 写入日志
    if (log_switch & 0x02U) {
        // 打开日志文件
        if (!std::filesystem::exists(log_file)) {
            std::cout << "日志路径不存在" << std::endl;
        }

        // 打开文件
        std::ofstream file(log_file, std::ios::app);

        // 写入文件
        if (file.is_open()) {
            // 输出日期、线程号和进程号到日志文件
            file << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S") << " ";
            file << "Process ID: " << process_id << " ";
            file << "Thread: " << thread_id << " ";
            file << "Level_" << level << ": ";
            (file << ... << args);
            file << std::endl; // 写入换行符
        } else {
            std::cerr << "无法打开日志文件" << std::endl;
        }

        file.close();
        // 关闭文件
    }
    return 0;
}

} // namespace log_tool

#endif