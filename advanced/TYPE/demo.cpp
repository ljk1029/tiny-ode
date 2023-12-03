
#include "template.h"

// 模板
int test_type(){
    std::cout << "[template_max() function]" << std::endl;
    return my_type::template_max();
}

int main()
{
    test_type();
    return 0;
}


