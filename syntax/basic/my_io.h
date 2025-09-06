#ifndef _MY_IO_H_
#define _MY_IO_H_
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>


class IOExample {
public:
    // 输出测试
    void demo_cout() {
        int number = 18;
        std::string name = "lmy";
        std::cout << "Hello World\n";
        std::cout << "Hello World" << std::endl;
        std::cout << number << "," << name << std::endl;
    }

    // 格式化输出
    void demo_format() {
        double pi = 3.1415926;
        std::cout << "pi = " << pi << std::endl;
        std::cout << "pi(2位小数) = " << std::fixed << std::setprecision(2) << pi << std::endl;
    }

    // 输入测试
    void demo_cin() {
        int number;
        std::string name;
        std::cout << "请输入一个整数: ";
        std::cin >> number;
        std::cout << "请输入一个字符串: ";
        std::cin.ignore(); // 忽略回车
        getline(std::cin, name);
        std::cout << "你输入的整数是: " << number << std::endl;
        std::cout << "你输入的字符串是: " << name << std::endl;
    }

    // 引用测试
    void demo_quote() {
        std::cout << "[引用测试]" << std::endl;
        int my_value = 42;
        int &my_quote = my_value;
        std::cout << "value: " << my_value << " & " << &my_value << std::endl;
        std::cout << "quote: " << my_quote << " & " << &my_quote << std::endl;
    }

    // getline 测试
    void demo_getline() {
        std::string line;
        std::cout << "请输入一个字符串: ";
        std::getline(std::cin, line);
        std::cout << "读取的行是：" << line << std::endl;

        char delimiter = '#'; // 指定分隔符
        std::cout << "请输入文本，使用 '#' 作为分隔符：" << std::endl;
        if (std::getline(std::cin, line, delimiter)) {
            std::cout << "读取的文本是：" << line << std::endl;
        }
    }

    // 文本文件读写
    void demo_fstream() {
        {
            std::ofstream file("example.txt", std::ios::out | std::ios::trunc);
            if (file.is_open()) {
                file << "ASCII 文本数据\n";
                file.close();
            } else {
                std::cerr << "无法打开文件进行写入" << std::endl;
                return;
            }
        }
        {
            std::ifstream file("example.txt", std::ios::in);
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << "读取的文本行：" << line << std::endl;
                }
                file.close();
            } else {
                std::cerr << "无法打开文件进行读取" << std::endl;
                return;
            }
        }
    }

    // 文件追加写入
    void demo_fstream_append() {
        std::ofstream file("example.txt", std::ios::out | std::ios::app);
        if (file.is_open()) {
            file << "追加内容\n";
            file.close();
            std::cout << "已追加内容到 example.txt" << std::endl;
        } else {
            std::cerr << "无法打开文件进行追加写入" << std::endl;
        }
    }

    // 二进制文件读写
    void demo_fstream_bin() {
        {
            int number = 12345;
            std::ofstream file("example.bin", std::ios::out | std::ios::binary | std::ios::trunc);
            if (file.is_open()) {
                file.write(reinterpret_cast<const char*>(&number), sizeof(number));
                file.close();
            } else {
                std::cerr << "无法打开文件进行二进制写入" << std::endl;
                return;
            }
        }
        {
            int number;
            std::ifstream file("example.bin", std::ios::in | std::ios::binary);
            if (file.is_open()) {
                file.read(reinterpret_cast<char*>(&number), sizeof(number));
                std::cout << "读取的二进制数据：" << number << std::endl;
                file.close();
            } else {
                std::cerr << "无法打开文件进行二进制读取" << std::endl;
                return;
            }
        }
    }

    // 错误处理演示
    void demo_error() {
        std::ifstream file("not_exist.txt");
        if (!file.is_open()) {
            std::cerr << "文件打开失败: not_exist.txt" << std::endl;
        }
    }

    // C风格IO演示
    void demo_cstdio() {
        int a = 10;
        printf("C风格输出: a = %d\n", a);
        char str[100];
        printf("请输入字符串: ");
        scanf("%99s", str);
        printf("你输入的是: %s\n", str);
    }

    // 字符串流演示
    void demo_sstream() {
        std::stringstream ss;
        ss << "123 456";
        int x, y;
        ss >> x >> y;
        std::cout << "字符串流解析: x=" << x << ", y=" << y << std::endl;
    }
};

#endif // _MY_IO_H