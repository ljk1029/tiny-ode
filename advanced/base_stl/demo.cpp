#include "stl_list.h"
#include "stl_map.h"
#include "stl_set.h"
#include "stl_vector.h"
#include <functional>
#include <iostream>

using CallbackFunc = std::function<int()>;

// 测试回调
int func_print(const std::string &title, CallbackFunc callback) {
    std::cout << "======"
              << "[" << title << " test]"
              << "=====" << std::endl;
    int ret = callback();
    std::cout << "--------[test end]--------\n\n";
    return ret;
}

// vector 测试
void test_vector() {
    func_print("verctor_make", stl_vector::verctor_make);
    func_print("verctor_at", stl_vector::verctor_at);
    func_print("verctor_erase", stl_vector::verctor_erase);
    func_print("verctor_iterator", stl_vector::verctor_iterator);
}

// map 测试
void test_map() {
    func_print("map_make", stl_map::map_make);
    func_print("map_iterator", stl_map::map_iterator);
    func_print("map_find", stl_map::map_find);
    func_print("map_erase", stl_map::map_erase);
}

// list 测试
void test_list() {
    func_print("list_make", stl_list::list_make);
    func_print("list_iterator", stl_list::list_iterator);
    func_print("list_remove", stl_list::list_remove);
}

// set 测试
void test_set() { func_print("set", stl_set::set_all); }

int main_test(int argc, char *argv[]) {
    test_vector();
    test_map();
    test_list();
    test_set();
    return 0;
}

// 测试用例
int main(int argc, char *argv[]) {
    main_test(argc, argv);
    return 0;
}
