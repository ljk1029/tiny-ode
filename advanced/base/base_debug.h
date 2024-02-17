/*
 * 文件名: debug.h
 * 作者: ljk
 * 创建时间: 2023-09-09
 * 文件描述: 调试例程
*/
#ifndef _IO_DEBUG_H__
#define _IO_DEBUG_H__
#include <filesystem>
#include <iostream>
#include <stdexcept> // 包含标准异常类的头文件

namespace my_debug{

// try 调试
int debug_try()
{
     try {
          std::filesystem::copy("./case.txt", "./dir/");
     } catch(const std::filesystem::filesystem_error& e) {
          std::cerr << "文件系统错误: " << e.what() << '\n';
          // 处理错误情况
     }
}

}
#endif 