#include "base_input.h"
#include "base_math.h"
#include "base_memory.h"
#include "base_string.h"
#include "base_debug.h"
#include "../run_print.h"
#include <functional>

// using namespace std;
// using namespace io_demo;


void baseDebugTest(std::function<void(const std::string&, std::function<void()>)> callback) {
    callback("debugTry()", my_base::my_debug::debugTry);
}

void baseInputTest(my_base::TestRunner &test_runner) {
    if( test_runner.getRunStatus("input") ){
        test_runner.funcPrint("ioCout()",     my_base::my_input::ioCout);
        test_runner.funcPrint("ioCin()",      my_base::my_input::ioCin);
        test_runner.funcPrint("valueQuote()", my_base::my_input::valueQuote);
    }
}

void baseMathTest(my_base::TestRunner &test_runner) {
    
}

void baseMemoryTest(my_base::TestRunner &test_runner) {
    if( test_runner.getRunStatus("mem") ){
        test_runner.funcPrint("memoryNew()",  my_base::my_mem::memoryNew);
        test_runner.funcPrint("memoryNews()", my_base::my_mem::memoryNews);
        test_runner.funcPrint("smartPtr()",   my_base::my_mem::smartPtr);
        test_runner.funcPrint("smartPtrs()",  my_base::my_mem::smartPtrs);
    }
}

void baseStringTest(my_base::TestRunner &test_runner) {
    if( test_runner.getRunStatus("str") ){
        test_runner.funcPrint("stlString()",  my_base::my_string::stlString);
        test_runner.funcPrint("stlStrings()", my_base::my_string::stlStrings);
        test_runner.funcPrint("stlArray()",   my_base::my_string::stlArray);
    }
}

int mainBaseTest(int argc, char *argv[]) {
    my_base::TestRunner test_runner(argc, argv);
    if( test_runner.getRunStatus("debug") ){
        // 显式指定 funcPrint 的重载版本
        using FuncSignature = void (my_base::TestRunner::*)(const std::string&, std::function<void()>);
        auto funcPrintBound = std::bind(static_cast<FuncSignature>(&my_base::TestRunner::funcPrint),
                                        &test_runner, std::placeholders::_1, std::placeholders::_2);
        baseDebugTest(funcPrintBound);
    }
    
    baseInputTest(test_runner);
    baseMemoryTest(test_runner);
    baseStringTest(test_runner);
    return 0;
}

// 测试用例
int main(int argc, char *argv[]) {
    mainBaseTest(argc, argv);
    return 0;
}
