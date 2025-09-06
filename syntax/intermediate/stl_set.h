#ifndef STL_SET_H
#define STL_SET_H

#include <iostream>
#include <set>
#include <algorithm>
#include <string>

class SetExample {
public:
    // 构造与插入
    void demo_make() {
        std::set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.emplace(4);
        printSet(s, "插入");
    }

    // 遍历
    void demo_iterator() {
        std::set<int> s = {1, 2, 3, 4};
        std::cout << "iterator set: ";
        for (auto it = s.begin(); it != s.end(); ++it) std::cout << *it << " ";
        std::cout << std::endl;
    }

    // 查找
    void demo_find() {
        std::set<int> s = {1, 2, 3};
        auto it = s.find(2);
        if (it != s.end()) std::cout << "find: " << *it << std::endl;
        else std::cout << "not found" << std::endl;
    }

    // 删除
    void demo_erase() {
        std::set<int> s = {1, 2, 3};
        s.erase(2);
        printSet(s, "erase");
    }

    // 容量与判空
    void demo_size_empty() {
        std::set<int> s = {1, 2};
        std::cout << "size: " << s.size() << std::endl;
        std::cout << "empty: " << (s.empty() ? "true" : "false") << std::endl;
    }

    // swap
    void demo_swap() {
        std::set<int> s1 = {1, 2};
        std::set<int> s2 = {3};
        s1.swap(s2);
        printSet(s1, "swap后s1");
        printSet(s2, "swap后s2");
    }

    // count、lower_bound、upper_bound
    void demo_count_bounds() {
        std::set<int> s = {1, 2, 3};
        std::cout << "count(2): " << s.count(2) << std::endl;
        auto lb = s.lower_bound(2);
        if (lb != s.end()) std::cout << "lower_bound(2): " << *lb << std::endl;
        auto ub = s.upper_bound(2);
        if (ub != s.end()) std::cout << "upper_bound(2): " << *ub << std::endl;
    }

    // multiset用法
    void demo_multiset() {
        std::multiset<int> ms;
        ms.insert(1);
        ms.insert(1);
        ms.insert(2);
        std::cout << "multiset遍历: ";
        for (auto x : ms) std::cout << x << " ";
        std::cout << std::endl;
    }

    // 打印
    void printSet(const std::set<int>& s, const std::string& title) {
        std::cout << "(" << title << ") ";
        for (int x : s) std::cout << x << " ";
        std::cout << std::endl;
    }
};

#endif // STL_SET_H