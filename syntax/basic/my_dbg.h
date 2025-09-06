#ifndef MY_DBG_H
#define MY_DBG_H
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cassert>

#define DEBUG_LOG(msg) \
    std::cout << "[DEBUG] " << __FILE__ << ":" << __LINE__ << " " << msg << std::endl;

class DebugExample {
public:
    // try/catch调试
    void demo_try() {
        try {
            std::vector<int> v;
            std::cout << v.at(10); // 越界访问
            throw std::runtime_error("除以零错误");
        } catch (std::invalid_argument &e) {
            std::cout << "无效参数异常: " << e.what() << std::endl;
        } catch (std::out_of_range &e) {
            std::cout << "范围外异常: " << e.what() << std::endl;
        } catch (const std::runtime_error &e) {
            std::cerr << "运行时错误: " << e.what() << std::endl;
        } catch (std::bad_alloc &e) {
            std::cout << "内存分配失败异常" << std::endl;
        } catch (std::exception &e) {
            std::cout << "标准异常: " << e.what() << std::endl;
        } catch (...) {
            std::cout << "未处理的异常" << std::endl;
        }
    }

    // 断言演示
    void demo_assert() {
        int x = 5;
        assert(x == 5);
        std::cout << "断言通过: x == 5" << std::endl;
        // assert(x == 0); // 取消注释可体验断言失败
    }

    // 日志宏演示
    void demo_log() {
        DEBUG_LOG("日志调试演示");
    }

    // 自定义异常演示
    void demo_custom_exception() {
        class MyException : public std::exception {
            const char* what() const noexcept override {
                return "自定义异常";
            }
        };
        try {
            throw MyException();
        } catch (const std::exception& e) {
            std::cout << "捕获: " << e.what() << std::endl;
        }
    }

    // 标准异常演示
    void demo_std_exception() {
        try {
            throw std::invalid_argument("参数错误");
        } catch (const std::exception& e) {
            std::cout << "捕获标准异常: " << e.what() << std::endl;
        }
    }
};

#endif // MY_DBG_H