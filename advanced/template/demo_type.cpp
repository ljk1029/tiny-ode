#include "template.h"
#include "../run_print.h"

// 模板
int typeTest(my_base::TestRunner &test_runner) {
    if( test_runner.getRunStatus("type") ){
        test_runner.funcPrint("templateMax()", my_base::my_type::templateMax);
        my_base::my_type::templatePrint(1, 2.2, "hello", 'c');
    }
    return true;
}

int mainTemplateTest(int argc, char *argv[]) {
    my_base::TestRunner test_runner(argc, argv);
    typeTest(test_runner);
    return 0;
}

// 测试用例
int main(int argc, char *argv[]) {
    mainTemplateTest(argc, argv);
    return 0;
}
