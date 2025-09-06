#include <stdexcept>
#include <iostream>

void func(int a) {
    auto *const i = new int;
    // if (a == 0) throw std::exception("Error!");
    // if (a == 0) throw std::runtime_error("Error!");
    delete i;
}

struct B {
    B() { echo(); }
    virtual ~B() { echo(); }
    virtual void echo() const { std::cout << "B" << std::endl; }
};

struct D : B {
    virtual void echo() const override { std::cout << "D" << std::endl; }
};

int main() {
    D d; // 创建一个 D 对象
    // f(d); // 调用函数 f，传入该对象
    return 0;
}