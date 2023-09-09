#include <iostream>
#include <string>

using namespace std;


// 输出
int io_cout()
{
    int number = 10;
    string name = "lixiansheng";

    cout << "huahua &";
    cout << "huaye; " << endl;
    cout << number << "," << name << endl;
    return 0;
}

// 输入
int io_cin()
{
    int number;
    string name;

    cout << "请输入一个整数:";
    cin >> number;
    cout << "请输入一个字符串:";
    cin.ignore(); //忽略回车
    getline(cin, name);

    cout << "你输入的整数是:   " << number << endl;
    cout << "你输入的字符串是: " << name << endl;
    return 0;
}

