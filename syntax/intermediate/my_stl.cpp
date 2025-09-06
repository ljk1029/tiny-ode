// STL用例测试
#include "../basic/my_task.h"
#include "stl_vector.h"
#include "stl_map.h"
#include "stl_list.h"
#include "stl_set.h"


void test_vector_func() {
    VectorExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("添加/删除", [&](){ demo.demo_make(); });
    scheduler.addTask("访问", [&](){ demo.demo_at(); });
    scheduler.addTask("删除/插入/清空", [&](){ demo.demo_erase_insert_clear(); });
    scheduler.addTask("迭代器遍历", [&](){ demo.demo_iterator(); });
    scheduler.addTask("尺寸与容量", [&](){ demo.demo_resize_reserve(); });
    scheduler.addTask("赋值与交换", [&](){ demo.demo_assign_swap(); });
    scheduler.addTask("emplace用法", [&](){ demo.demo_emplace(); });
    scheduler.addTask("front/back访问", [&](){ demo.demo_front_back(); });
    scheduler.addTask("反转/排序/去重", [&](){ demo.demo_reverse_sort_unique(); });
    scheduler.runAll();
}

void test_map_func(){
    MapExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("构造与插入", [&](){ demo.demo_make(); });
    scheduler.addTask("遍历", [&](){ demo.demo_iterator(); });
    scheduler.addTask("查找与修改", [&](){ demo.demo_find_modify(); });
    scheduler.addTask("删除", [&](){ demo.demo_erase(); });
    scheduler.addTask("容量与判空", [&](){ demo.demo_size_empty(); });
    scheduler.addTask("swap", [&](){ demo.demo_swap(); });
    scheduler.addTask("emplace用法", [&](){ demo.demo_emplace(); });
    scheduler.addTask("count/lower_bound/upper_bound", [&](){ demo.demo_count_bounds(); });
    scheduler.addTask("multimap用法", [&](){ demo.demo_multimap(); });
    scheduler.runAll();
}
   
void test_list_func(){
    ListExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("构造与赋值", [&](){ demo.demo_basic(); });
    scheduler.addTask("插入与删除", [&](){ demo.demo_insert_erase(); });
    scheduler.addTask("emplace用法", [&](){ demo.demo_emplace(); });
    scheduler.addTask("访问与遍历", [&](){ demo.demo_access(); });
    scheduler.addTask("迭代器遍历", [&](){ demo.demo_iterator(); });
    scheduler.addTask("反转/排序/去重", [&](){ demo.demo_reverse_sort_unique(); });
    scheduler.addTask("合并与拼接", [&](){ demo.demo_merge_splice(); });
    scheduler.addTask("resize/clear/判空", [&](){ demo.demo_resize_clear_empty(); });
    scheduler.runAll();
}

void test_set_func(){
    SetExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("构造与插入", [&](){ demo.demo_make(); });
    scheduler.addTask("遍历", [&](){ demo.demo_iterator(); });
    scheduler.addTask("查找", [&](){ demo.demo_find(); });
    scheduler.addTask("删除", [&](){ demo.demo_erase(); });
    scheduler.addTask("容量与判空", [&](){ demo.demo_size_empty(); });
    scheduler.addTask("swap", [&](){ demo.demo_swap(); });
    scheduler.addTask("count/lower_bound/upper_bound", [&](){ demo.demo_count_bounds(); });
    scheduler.addTask("multiset用法", [&](){ demo.demo_multiset(); });
    scheduler.runAll();
}


int main() {
    std::cout << "\n===== STL Vector 用例 =====\n";
    test_vector_func();
    std::cout << "\n===== STL Map 用例 =====\n";
    test_map_func();
    std::cout << "\n===== STL List 用例 =====\n";
    test_list_func();
    std::cout << "\n===== STL Set 用例 =====\n";
    test_set_func();
    return 0;
}
