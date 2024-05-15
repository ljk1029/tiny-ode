/*
 * 文件名: debug.h
 * 作者: ljk
 * 创建时间: 2023-09-09
 * 文件描述: 调试例程
 */
#ifndef _IO_DEBUG_H__
#define _IO_DEBUG_H__

#include <iostream>
#include <stdexcept> // 包含标准异常类的头文件
#include <vector>

namespace my_base {
namespace my_debug {

// try 调试
void debugTry() {
    try {
        // 这里包含可能抛出异常的代码
        std::vector<int> v; // 空的向量
        // 抛出一个标准异常 - 越界访问
        std::cout << v.at(10); // 这里将会抛出一个std::out_of_range异常

        // 抛出一个自定义异常
        throw std::runtime_error("除以零错误");
    } catch (std::invalid_argument& e) {
        std::cout << "无效参数异常: " << e.what() << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "范围外异常: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "运行时错误: " << e.what() << std::endl;
    } catch (std::bad_alloc& e) {
        std::cout << "内存分配失败异常" << std::endl;
    } catch (std::exception& e) {
        std::cout << "标准异常: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "未处理的异常" << std::endl;
    }
}

} // namespace my_debug
} // namespace my_base
#endif