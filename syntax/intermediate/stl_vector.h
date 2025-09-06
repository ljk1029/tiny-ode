#ifndef STL_VECTOR_H
#define STL_VECTOR_H

#include <iostream>
#include <vector>
#include <algorithm>



class VectorExample {
public:
    // 尺寸与容量相关
    void demo_resize_reserve() {
        std::vector<int> v = {1, 2, 3};
        v.resize(5, 9); // 扩展为5个，新增元素为9
        printVector(v, "resize to 5", '(');
        v.resize(2); // 缩小为2个
        printVector(v, "resize to 2", '(');
        v.reserve(10);
        std::cout << "reserve(10)后 capacity: " << v.capacity() << std::endl;
        v.shrink_to_fit();
        std::cout << "shrink_to_fit后 capacity: " << v.capacity() << std::endl;
    }

    // 赋值与交换
    void demo_assign_swap() {
        std::vector<int> v1 = {1, 2, 3};
        std::vector<int> v2;
        v2.assign(5, 7); // 赋值5个7
        printVector(v2, "assign", '(');
        v1.swap(v2);
        printVector(v1, "swap后v1", '(');
        printVector(v2, "swap后v2", '(');
    }

    // emplace用法
    void demo_emplace() {
        std::vector<int> v;
        v.emplace_back(10);
        v.emplace(v.begin(), 5);
        printVector(v, "emplace", '(');
    }

    // front/back访问
    void demo_front_back() {
        std::vector<int> v = {1, 2, 3};
        std::cout << "front: " << v.front() << ", back: " << v.back() << std::endl;
    }

    // 反转、排序、去重
    void demo_reverse_sort_unique() {
        std::vector<int> v = {3, 1, 2, 2, 4};
        std::reverse(v.begin(), v.end());
        printVector(v, "reverse", '(');
        std::sort(v.begin(), v.end());
        printVector(v, "sort", '(');
        auto last = std::unique(v.begin(), v.end());
        v.erase(last, v.end());
        printVector(v, "unique", '(');
    }

    // 打印
    void printVector(const std::vector<int>& numbers, const std::string& title) {
        std::cout << "(" << title << ")" << std::endl;
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    // 重载打印
    void printVector(const std::vector<int>& numbers, const std::string& title, char bracket) {
        if (bracket == '(' || bracket == ')') {
            std::cout << "(" << title << ")" << std::endl;
        } else if (bracket == '[' || bracket == ']') {
            std::cout << "[" << title << "]" << std::endl;
        } else {
            std::cout << title << std::endl;
        }
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    // 添加删除
    void demo_make() {
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        numbers.push_back(6);
        printVector(numbers, "push_back test", '(');
        numbers.pop_back();
        printVector(numbers, "pop_back test", '(');
    }

    // 访问
    void demo_at() {
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        std::cout << "size: " << numbers.size() << std::endl;
        std::cout << "element: " << numbers[0] << std::endl;
        std::cout << "element: " << numbers.at(1) << std::endl;
        std::cout << "element: " << numbers.back() << std::endl;
    }

    // 删除、插入、清空
    void demo_erase_insert_clear() {
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        numbers.erase(numbers.begin() + 1);
        printVector(numbers, "erase test", '(');
        numbers.insert(numbers.begin() + 2, 10);
        printVector(numbers, "insert test", '(');
        numbers.clear();
        printVector(numbers, "clear test", '(');
        std::cout << "size: " << numbers.size() << std::endl;
        if (numbers.empty()) {
            std::cout << "Vector is empty." << std::endl;
        }
    }

    // 迭代器遍历
    void demo_iterator() {
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        std::cout << "Vector iterator: ";
        for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

#endif // STL_VECTOR_H