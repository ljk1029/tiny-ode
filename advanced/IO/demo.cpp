#include <iostream>
#include "demo.h"

using namespace std;
using namespace io_demo;


// 引用测试
int test_quote()
{
    cout << "[引用测试 function]" << endl;
    int &a = io_demo::my_variable;
    cout << "value: " << a << " & " << my_variable << endl;
    cout << "address: " << &a << " & " << &my_variable << endl;
    return 0;
}

int main()
{
    // 标准输入测试
    io_demo::test_cout();
    io_demo::test_cin();
    io_demo::test_string();
    io_demo::test_strings();

    // 引用测试
    test_quote();

    return 0;
}


