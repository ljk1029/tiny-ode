#include <iostream>
#include "map.h"
#include "set.h"
#include "list.h"
#include "vector.h"
#include <functional>

using CallbackFunc = std::function<int()>;

// 测试回调
int test_func(const std::string& title, CallbackFunc callback)
{
    std::cout << "------" << "[" << title << " test]" 
        << "------" << std::endl;
    int ret = callback();
    std::cout << "----------[test end]--------\n";
    return ret;
}

void test_vector()
{
    test_func("verctor_make",  stl_vector::verctor_make);
    test_func("verctor_at",    stl_vector::verctor_at);
    test_func("verctor_erase", stl_vector::verctor_erase);
    test_func("verctor_iterator", stl_vector::verctor_iterator);
}

void test_map()
{
    test_func("map_make",     stl_map::map_make);
    test_func("map_iterator", stl_map::map_iterator);
    test_func("map_find",  stl_map::map_find);
    test_func("map_erase", stl_map::map_erase);
}

void test_list()
{
    test_func("list_make",     stl_list::list_make);
    test_func("list_iterator", stl_list::list_iterator);
    test_func("list_remove",   stl_list::list_remove);
}

void test_set()
{
    test_func("set",   stl_set::set_all);
}

// 测试用例
int main()
{
    test_vector();
    test_map();
    test_list();
    test_set();

    return 0;
}


