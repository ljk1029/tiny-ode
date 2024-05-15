#include <iostream>
#include <functional>
#include <string>
#include <thread>
#include <cstring>
#include <algorithm>





    // 打印标题
static void printTitle(const std::string &title, bool start_mode) {
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


// 定义回调函数模板
template <typename ReturnType, typename... Args>
using CallbackFunc = std::function<ReturnType(Args...)>;

// 非void返回类型的泛型函数打印重载
template <typename ReturnType, typename... Args>
ReturnType funcPrint(const std::string &title, CallbackFunc<ReturnType, Args...> callback, Args... args) {
    printTitle(title, true);
    ReturnType ret = callback(args...); // 传递参数给回调函数
    printTitle(title, false);
    std::cout<<"callback ret:"<< ret<< std::endl;
    return ret;
}

// void返回类型的泛型函数打印重载
template <typename... Args>
void funcPrint(const std::string &title, CallbackFunc<void, Args...> callback, Args... args) {
    printTitle(title, true);
    callback(args...); // 传递参数给回调函数
    printTitle(title, false);
}

void printsss(std::string a)
{
    std::cout << a << std::endl;
}
   
int main() {
    funcPrint("123", printsss, std::string("hllo"));
}
   