#include <cxxabi.h>
#include <iostream>

/**
 * 类继承实例测试
 * */ 
template <typename T> class B {
public:
    void print() {
        int status;
        char *demangled = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
        std::cout << "Class B specialized for type " << demangled << std::endl;
        free(demangled);
    }
    void _print() {
        std::cout << "Class B specialized for type " << typeid(T).name()
                  << std::endl;
    }
};

class C {
public:
    void print() { std::cout << "Class C" << std::endl; }
};

class A : public B<C> {};

int main() {
    A a;
    a.print(); // 输出：Class B specialized for type C
    a._print();
    return 0;
}