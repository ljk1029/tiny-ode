#include <cxxabi.h>
#include <iostream>

/**
 * 类继承实例测试
 *
 * */
template <typename T> class B {
public:
    void print() {
        int status;
        char *demangled = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
        std::cout << "Class B specialized for type " << demangled << std::endl;
        free(demangled);
    }

    void _print() { std::cout << "Class B specialized for type " << typeid(T).name() << std::endl; }
};

class C {
public:
    void print() { std::cout << "Class C" << std::endl; }
};

class A : public B<C> {};

// 测试类
int main(int argc, char *argv[]) {
    A aObj;
    aObj.print(); // 输出：Class B specialized for type C
    aObj._print();

    B<C> bObj;
    bObj.print();
    bObj._print();

    C cObj;
    cObj.print();
    return 0;
}