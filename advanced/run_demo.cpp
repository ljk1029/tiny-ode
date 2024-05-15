#include <iostream>
#include "run_print.h"

using namespace my_base;

// 回调函数
void voidCallbackFunction() {
    std::cout << "Void Callback function is called." << std::endl;
}

int intCallbackFunction() {
    std::cout << "Int Callback function is called." << std::endl;
    return 13;
}

/**
 * 测试用例
 * ./a.out -all -case int
*/
int main(int argc, char *argv[]) {
    my_base::TestRunner test_runner(argc, argv);
    my_base::print("test:", 11);
    prints("test:", 12);
    
    if(test_runner.getRunStatus("void")) {
        test_runner.funcPrint("voidCallbackFunction", voidCallbackFunction);
    }
    if(test_runner.getRunStatus("int")) {
        test_runner.funcPrint("intCallbackFunction", intCallbackFunction);
    }
    return 0;
}