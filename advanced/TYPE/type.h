#ifndef MY_DEMO_H
#define MY_DEMO_H

#include <iostream>
#include "memory.h"
#include "template.h"

// 命名空间
namespace type_demo 
{
    // 内存
    int test_memory(){
        std::cout << "[memory_new()  function]" << std::endl;
        memory_new();
        std::cout << "[memory_news() function]" << std::endl;
        memory_news();
        std::cout << "[smart_ptr()   function]" << std::endl;
        smart_ptr();
        return 0;
    }
    // 模板
    int test_type(){
        std::cout << "[template_max() function]" << std::endl;
        return template_max();
    }
}

#endif 