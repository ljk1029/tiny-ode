#include <iostream>
#include "run_print.h"

using namespace my_base;

// 回调函数
void callbackFunctionVoid() { std::cout << "Callback function for Void is called." << std::endl; }

int callbackFunctionInt() {
    std::cout << "Callback function for Int is called." << std::endl;
    return 13;
}

// 使用说明
void printUsage() {
    std::cout << "Usage: ./a.out [options]\n"
              << "Options:\n"
              << "  -all             Run all test cases\n"
              << "  -case <name>     Run specific test case\n"
              << "Examples:\n"
              << "  ./a.out -all\n"
              << "  ./a.out -case int\n"
              << "  ./a.out -case void\n";
}

/**
 * 测试用例
 * ./a.out -all
 * ./a.out -case int
 * ./a.out -case void
 */
int main(int argc, char *argv[]) {
    printUsage();
    my_base::TestRunner test_runner(argc, argv);
    my_base::print("print_test:", 11);
    prints("print_test:", 12);

    if (test_runner.getRunStatus("void")) {
        test_runner.funcPrint("CallbackFunction for void", callbackFunctionVoid);
    }
    if (test_runner.getRunStatus("int")) {
        test_runner.funcPrint("CallbackFunction for  int", callbackFunctionInt);
    }
    return 0;
}