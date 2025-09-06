#ifndef STL_LIST_H
#define STL_LIST_H

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

class ListExample {
public:
    // 构造与赋值
    void demo_basic() {
        std::list<int> l1 = {1, 2, 3};
        std::list<int> l2(l1);
        l2.assign(4, 7);
        printList(l2, "assign");
        l1.swap(l2);
        printList(l1, "swap后l1");
        printList(l2, "swap后l2");
    }

    // 插入与删除
    void demo_insert_erase() {
        std::list<int> l = {1, 2, 3};
        l.push_back(4);
        l.push_front(0);
        l.insert(++l.begin(), 99);
        printList(l, "插入");
        l.pop_back();
        l.pop_front();
        l.erase(++l.begin());
        printList(l, "删除");
    }

    // emplace用法
    void demo_emplace() {
        std::list<int> l;
        l.emplace_back(10);
        l.emplace_front(5);
        l.emplace(l.begin(), 1);
        printList(l, "emplace");
    }

    // 访问与遍历
    void demo_access() {
        std::list<int> l = {1, 2, 3};
        std::cout << "front: " << l.front() << ", back: " << l.back() << std::endl;
        std::cout << "遍历: ";
        for (int x : l) std::cout << x << " ";
        std::cout << std::endl;
    }

    // 迭代器遍历
    void demo_iterator() {
        std::list<int> l = {1, 2, 3, 4};
        std::cout << "List iterator: ";
        for (auto it = l.begin(); it != l.end(); ++it) std::cout << *it << " ";
        std::cout << std::endl;
    }

    // 反转、排序、去重
    void demo_reverse_sort_unique() {
        std::list<int> l = {3, 1, 2, 2, 4};
        l.reverse();
        printList(l, "reverse");
        l.sort();
        printList(l, "sort");
        l.unique();
        printList(l, "unique");
    }

    // 合并与拼接
    void demo_merge_splice() {
        std::list<int> l1 = {1, 3, 5};
        std::list<int> l2 = {2, 4, 6};
        l1.merge(l2);
        printList(l1, "merge");
        std::list<int> l3 = {7, 8};
        l1.splice(l1.end(), l3);
        printList(l1, "splice");
    }

    // resize、clear、判空
    void demo_resize_clear_empty() {
        std::list<int> l = {1, 2, 3};
        l.resize(5, 9);
        printList(l, "resize to 5");
        l.resize(2);
        printList(l, "resize to 2");
        l.clear();
        std::cout << "清空后是否为空: " << (l.empty() ? "是" : "否") << std::endl;
    }

    // 打印
    void printList(const std::list<int>& l, const std::string& title) {
        std::cout << "(" << title << ") ";
        for (int x : l) std::cout << x << " ";
        std::cout << std::endl;
    }
};

#endif // STL_LIST_H