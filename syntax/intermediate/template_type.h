#ifndef MY_TEMPLATE_H
#define MY_TEMPLATE_H

#include <iostream>
#include <string>
#include <type_traits>

// 类模板
template <typename T>
class MyTemplate {
public:
    MyTemplate(T value) : value_(value) {}
    T getValue() const { return value_; }
private:
    T value_;
};

// 函数模板
template <typename T>
T template_add(const T& a, const T& b) {
    return a + b;
}

// 函数模板特化
template <>
std::string template_add(const std::string& a, const std::string& b) {
    return a + "-" + b;
}

// 通用比较函数模板
template <typename T>
int template_max(const T &a, const T &b) {
    std::cout << a << " compare " << b << std::endl;
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

// 字符串专用比较函数模板
template <>
int template_max(const std::string &a, const std::string &b) {
    std::cout << a << " compare " << b << std::endl;
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

// 递归终止函数
inline void template_print() { std::cout << std::endl; }
// 变参模板函数，用于打印不定数量参数
template <typename T, typename... Args>
void template_print(const T &first_arg, const Args &...args) {
    std::cout << first_arg << ", ";
    template_print(args...);
}

// 模板默认参数
template <typename T = int>
class DefaultType {
public:
    T value;
    DefaultType(T v) : value(v) {}
};

// 模板别名
template <typename T>
using Ptr = T*;

// 类型萃取 traits
template <typename T>
struct is_string {
    static constexpr bool value = false;
};

template <>
struct is_string<std::string> {
    static constexpr bool value = true;
};

// 封装所有模板用例
class TemplateExample {
public:
    void demo_class_template() {
        MyTemplate<int> a(10);
        MyTemplate<std::string> b("hello");
        std::cout << "MyTemplate<int>: " << a.getValue() << std::endl;
        std::cout << "MyTemplate<string>: " << b.getValue() << std::endl;
    }

    void demo_func_template() {
        std::cout << "template_add<int>: " << template_add(1, 2) << std::endl;
        std::cout << "template_add<string>: " << template_add(std::string("a"), std::string("b")) << std::endl;
    }

    void demo_max() {
        std::cout << "max(3,5): " << template_max(3, 5) << std::endl;
        std::cout << "max('abc','def'): " << template_max(std::string("abc"), std::string("def")) << std::endl;
    }

    void demo_variadic() {
        template_print(1, 2.5, "hello", 'c');
    }

    void demo_default_type() {
        DefaultType<> a(100);
        DefaultType<double> b(3.14);
        std::cout << "DefaultType<int>: " << a.value << std::endl;
        std::cout << "DefaultType<double>: " << b.value << std::endl;
    }

    void demo_alias() {
        Ptr<int> p = nullptr;
        std::cout << "Ptr<int> is int*" << std::endl;
    }

    void demo_traits() {
        std::cout << "is_string<int>: " << is_string<int>::value << std::endl;
        std::cout << "is_string<string>: " << is_string<std::string>::value << std::endl;
    }
};

#endif // MY_TEMPLATE_H