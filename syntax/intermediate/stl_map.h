
#ifndef STL_MAP_H
#define STL_MAP_H
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

class MapExample {
public:
    // 构造与插入
    void demo_make() {
        std::map<std::string, int> m;
        m["Alice"] = 95;
        m["Bob"] = 87;
        m["Charlie"] = 92;
        m.insert(std::make_pair("David", 88));
        m.emplace("Eve", 90);
        std::cout << "make map: " << m["Alice"] << std::endl;
    }

    // 遍历
    void demo_iterator() {
        std::map<std::string, int> m = {{"Alice", 95}, {"Bob", 87}, {"Charlie", 92}};
        std::cout << "iterator map:" << std::endl;
        for (auto it = m.begin(); it != m.end(); ++it) {
            std::cout << it->first << ": " << it->second << std::endl;
        }
    }

    // 查找与修改
    void demo_find_modify() {
        std::map<std::string, int> m = {{"Alice", 95}, {"Bob", 87}, {"Charlie", 92}};
        auto it = m.find("Bob");
        if (it != m.end()) {
            it->second = 100;
            std::cout << "find & modify: " << it->second << std::endl;
        } else {
            std::cout << "Bob not found." << std::endl;
        }
    }

    // 删除
    void demo_erase() {
        std::map<std::string, int> m = {{"Alice", 95}, {"Bob", 87}, {"Charlie", 92}};
        m.erase("Bob");
        std::cout << "erase:" << std::endl;
        for (const auto &pair : m) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }

    // 容量与判空
    void demo_size_empty() {
        std::map<int, int> m = {{1, 10}, {2, 20}};
        std::cout << "size: " << m.size() << std::endl;
        std::cout << "empty: " << (m.empty() ? "true" : "false") << std::endl;
    }

    // swap
    void demo_swap() {
        std::map<int, int> m1 = {{1, 10}, {2, 20}};
        std::map<int, int> m2 = {{3, 30}};
        m1.swap(m2);
        std::cout << "swap后m1: ";
        for (const auto& kv : m1) std::cout << kv.first << ":" << kv.second << " ";
        std::cout << std::endl;
    }

    // emplace
    void demo_emplace() {
        std::map<int, std::string> m;
        m.emplace(1, "one");
        m.emplace(2, "two");
        for (const auto& kv : m) std::cout << kv.first << ":" << kv.second << " ";
        std::cout << std::endl;
    }

    // count、lower_bound、upper_bound
    void demo_count_bounds() {
        std::map<int, std::string> m = {{1, "a"}, {2, "b"}, {3, "c"}};
        std::cout << "count(2): " << m.count(2) << std::endl;
        auto lb = m.lower_bound(2);
        if (lb != m.end()) std::cout << "lower_bound(2): " << lb->first << std::endl;
        auto ub = m.upper_bound(2);
        if (ub != m.end()) std::cout << "upper_bound(2): " << ub->first << std::endl;
    }

    // multimap用法
    void demo_multimap() {
        std::multimap<std::string, int> mm;
        mm.insert({"a", 1});
        mm.insert({"a", 2});
        mm.insert({"b", 3});
        std::cout << "multimap遍历: ";
        for (const auto& kv : mm) std::cout << kv.first << ":" << kv.second << " ";
        std::cout << std::endl;
    }
};

#endif // STL_MAP_H
