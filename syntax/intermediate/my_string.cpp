#include "stl_string.h"
#include "stl_array.h"
#include "../basic/my_task.h"

void test_string_func() {
    StringExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("构造与初始化", [&](){ demo.demo_make(); });
    scheduler.addTask("连接与追加", [&](){ demo.demo_concat_append(); });
    scheduler.addTask("长度与判空", [&](){ demo.demo_size_empty(); });
    scheduler.addTask("访问与遍历", [&](){ demo.demo_access_iter(); });
    scheduler.addTask("比较", [&](){ demo.demo_compare(); });
    scheduler.addTask("查找与替换", [&](){ demo.demo_find_replace(); });
    scheduler.addTask("分割", [&](){ demo.demo_split(); });
    scheduler.addTask("字符与数字转换", [&](){ demo.demo_num_convert(); });
    scheduler.addTask("插入/删除/清空", [&](){ demo.demo_insert_erase_clear(); });
    scheduler.addTask("反转", [&](){ demo.demo_reverse(); });
    scheduler.runAll();
}

void test_array_func() {
    ArrayExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("构造与赋值", [&](){ demo.demo_make(); });
    scheduler.addTask("访问与遍历", [&](){ demo.demo_access_iter(); });
    scheduler.addTask("容量与判空", [&](){ demo.demo_size_empty(); });
    scheduler.addTask("交换", [&](){ demo.demo_swap(); });
    scheduler.addTask("排序与反转", [&](){ demo.demo_sort_reverse(); });
    scheduler.runAll();
}

int main() {
    std::cout << "===== STL String 用例 =====\n";
    test_string_func();
    std::cout << "\n===== STL Array 用例 =====\n";
    test_array_func();
    return 0;
}
