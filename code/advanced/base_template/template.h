#ifndef _TYPE_TEMPLATE_H__
#define _TYPE_TEMPLATE_H__
#include <iostream>

namespace my_base {
namespace my_type {
/**
 * 下列typename 和 class一样
 */
// 定义一个函数模板，用于比较两个值的大小
// 通用比较函数模板
template <typename T> int templateMax(const T &a, const T &b) {
    std::cout << a << " compare " << b << std::endl;
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}

// 字符串专用比较函数模板
template <> int templateMax(const std::string &a, const std::string &b) {
    std::cout << a << " compare " << b << std::endl;
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}

// 递归终止函数
void templatePrint() {
    // 换行
    std::cout << std::endl;
}

// 变参模板函数，用于打印不定数量参数
template <typename T, typename... Args> void templatePrint(const T &first_arg, const Args &...args) {
    std::cout << first_arg << ", "; // 打印当前参数
    templatePrint(args...);         // 递归调用，打印剩余的参数
}

} // namespace my_type
} // namespace my_base

#endif