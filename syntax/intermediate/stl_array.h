// array 用法类
#ifndef STL_ARRAY_H
#define STL_ARRAY_H
#include <iostream>
#include <array>
#include <algorithm>

class ArrayExample {
public:
    // 构造与赋值
    void demo_make() {
        std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
        std::array<int, 5> arr2;
        arr2.fill(7);
        std::cout << "构造: ";
        printArray(arr1);
        std::cout << "赋值fill: ";
        printArray(arr2);
    }

    // 访问与遍历
    void demo_access_iter() {
        std::array<int, 4> arr = {10, 20, 30, 40};
        std::cout << "访问: " << arr[0] << ", " << arr.at(1) << std::endl;
        std::cout << "front: " << arr.front() << ", back: " << arr.back() << std::endl;
        std::cout << "遍历: ";
        for (int x : arr) std::cout << x << " ";
        std::cout << std::endl;
    }

    // 容量与判空
    void demo_size_empty() {
        std::array<int, 0> arr0;
        std::array<int, 3> arr = {1, 2, 3};
        std::cout << "size: " << arr.size() << ", 判空: " << (arr.empty() ? "true" : "false") << std::endl;
    }

    // 交换
    void demo_swap() {
        std::array<int, 3> arr1 = {1, 2, 3};
        std::array<int, 3> arr2 = {4, 5, 6};
        arr1.swap(arr2);
        std::cout << "swap后arr1: ";
        printArray(arr1);
        std::cout << "swap后arr2: ";
        printArray(arr2);
    }

    // 排序与反转
    void demo_sort_reverse() {
        std::array<int, 5> arr = {5, 2, 4, 1, 3};
        std::sort(arr.begin(), arr.end());
        std::cout << "排序: ";
        printArray(arr);
        std::reverse(arr.begin(), arr.end());
        std::cout << "反转: ";
        printArray(arr);
    }

    // 打印
    void printArray(const std::array<int, 5>& arr) {
        for (int x : arr) std::cout << x << " ";
        std::cout << std::endl;
    }
    void printArray(const std::array<int, 3>& arr) {
        for (int x : arr) std::cout << x << " ";
        std::cout << std::endl;
    }
    void printArray(const std::array<int, 4>& arr) {
        for (int x : arr) std::cout << x << " ";
        std::cout << std::endl;
    }
};

#endif // STL_ARRAY_H
