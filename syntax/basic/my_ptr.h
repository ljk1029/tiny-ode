#ifndef MY_PTR_H
#define MY_PTR_H
#include <iostream>
#include <memory>



class SmartPtrExample {
public:
    // shared_ptr/unique_ptr演示
    void demo_basic() {
        std::shared_ptr<int> sp1 = std::make_shared<int>(42);
        std::shared_ptr<int> sp2 = sp1;
        std::cout << "shared_ptr: " << *sp1 << ", use_count: " << sp1.use_count() << std::endl;
        std::cout << "shared_ptr: " << *sp2 << ", use_count: " << sp2.use_count() << std::endl;

        std::unique_ptr<int> up = std::make_unique<int>(99);
        std::cout << "unique_ptr: " << *up << std::endl;
        // up.reset(); // 释放资源
    }

    // weak_ptr演示
    void demo_weak() {
        std::shared_ptr<int> sp = std::make_shared<int>(100);
        std::weak_ptr<int> wp = sp;
        std::cout << "weak_ptr use_count: " << wp.use_count() << std::endl;
        if (auto locked = wp.lock()) {
            std::cout << "weak_ptr lock成功: " << *locked << std::endl;
        } else {
            std::cout << "weak_ptr lock失败" << std::endl;
        }
        sp.reset();
        if (wp.expired()) {
            std::cout << "weak_ptr已失效" << std::endl;
        }
    }

    // 智能指针数组
    void demo_array() {
        const size_t n = 10;
        std::shared_ptr<int[]> sp_arr(new int[n]);
        for (size_t i = 0; i < n; ++i) {
            sp_arr[i] = static_cast<int>(i);
        }
        for (size_t i = 0; i < n; ++i) {
            std::cout << sp_arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // 循环引用问题演示
    struct Node {
        std::shared_ptr<Node> next;
        ~Node() { std::cout << "Node析构" << std::endl; }
    };
    void demo_cycle() {
        auto a = std::make_shared<Node>();
        auto b = std::make_shared<Node>();
        a->next = b;
        b->next = a; // 循环引用，内存不会释放
        std::cout << "循环引用演示: Node不会析构" << std::endl;
    }

    // get/reset演示
    void demo_get_reset() {
        std::unique_ptr<int> up = std::make_unique<int>(123);
        int* raw = up.get();
        std::cout << "unique_ptr get: " << *raw << std::endl;
        up.reset();
        std::cout << "unique_ptr reset后已释放" << std::endl;
    }
};


#endif // MY_PTR_H