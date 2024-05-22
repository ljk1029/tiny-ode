#include "template.h"
#include "../run_print.h"

// 模板
int typeTest(my_base::TestRunner &test_runner) {
    if (test_runner.getRunStatus("type")) {
        test_runner.funcPrint("templateMax()", [] {
            int a = my_base::my_type::templateMax(1, 1);
            int b = my_base::my_type::templateMax(2.1, 2.0);
            int c = my_base::my_type::templateMax(std::string("apple"), std::string("banana"));
            my_base::my_type::templatePrint("templateMax result:", a, b, c);
        });
        test_runner.funcPrint("templatePrint()", [] { my_base::my_type::templatePrint(1, 2.2, "hello", 'c'); });
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
