#include "template.h"

// 模板
int test_type(){
    std::cout << "[template_print() function]" << std::endl;
    my_type::template_print(1, 2.2, "hello", 'c');
    std::cout << "[template_max() function]" << std::endl;
    return my_type::template_max();
}

int main_test(int argc, char* argv[])
{
    test_type();
    return 0;
}

// 测试用例
int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}

