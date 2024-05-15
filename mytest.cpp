#include <iostream>
#include <functional>
#include <string>

// Template definition for the callback function
template <typename ReturnType>
using CallbackFunc = std::function<ReturnType()>;

// Generic func_print overload for non-void return types
int func_print(const std::string &title, CallbackFunc<int> callback) {
    std::cout << "======"
              << "[" << title << " test]"
              << "=====" << std::endl;
    int ret = callback();
    std::cout << "--------[test end]--------\n\n";
    return ret;
}

// Specialization for void return type
void func_print(const std::string &title, CallbackFunc<void> callback) {
    std::cout << "======"
              << "[" << title << " test]"
              << "=====" << std::endl;
    callback();
    std::cout << "--------[test end]--------\n\n";
}

// Callback functions
void voidCallbackFunction() {
    std::cout << "Void Callback function is called." << std::endl;
}

int intCallbackFunction() {
    std::cout << "Int Callback function is called." << std::endl;
    return 42;
}

#include <iostream>
#include <string>

// 调整这个值来设置总的打印长度
const int TOTAL_PRINT_LENGTH = 40;

void printTitle(const std::string& title, bool startMode) {
    std::cout << title.length() << "\n";
    // 计算边框长度
    int borderLength = (TOTAL_PRINT_LENGTH - title.length() - 10) / 2; // 10是"[test "和" start]"的额外字符长度
    if(borderLength < 0) {
        borderLength = 0; // 防止负数
    }

    std::string border(borderLength, startMode ? '=' : '-');
    std::cout << border;

    if (startMode) {
        std::cout << "[test " << title << " start]";
    } else {
        std::cout << "[test " << title << " end  ]";
    }

    std::cout << border << std::endl;
}


#include "print.h"

int main() {
    my_print::funcPrint<void>("voidCallbackFunction", voidCallbackFunction);
    my_print::funcPrint<int>("intCallbackFunction",  intCallbackFunction);
    printTitle("My Super Long Function Name That Will Break Borders", true); // 测试超长标题
    printTitle("Short Title", true);
    printTitle("Short    Tit   le", false);

    return 0;
}

// Main function
int main_test() {
    //int intValue = func_print("My Callback", intCallbackFunction);
    //std::cout << "Returned value: " << intValue << std::endl;

   // func_print("Void Callback", voidCallbackFunction);

    return 0;
}