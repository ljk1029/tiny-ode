#ifndef _STL_STRING_H__
#define _STL_STRING_H__

#include <array>
#include <iostream>
#include <string>

namespace my_base {
namespace my_string {

// 字符串 属于stl，自动释放
int stlString() {
    // 初始化
    std::string str1 = "Hello, World!";
    std::string str2("C++ String");
    std::string str3(5, 'A'); // 创建一个包含5个'A'字符的字符串
    std::cout << "初始化:" << std::endl;
    std::cout << "str1:" << str1 << std::endl;
    std::cout << "str1:" << str1 << std::endl;
    std::cout << "str2:" << str2 << std::endl;
    std::cout << "str3:" << str3 << std::endl;

    // 字符串连接
    std::string result = str1 + " " + str2;
    std::cout << "字符串连接:str1 + str2" << std::endl;
    std::cout << result << std::endl;

    // 字符串长度
    int length = str1.length();
    std::cout << "字符长度:str1" << std::endl;
    std::cout << length << std::endl;

    // 字符串比较
    std::cout << "字符比较:str1[0]" << str1[0] << "str2[0]" << str2[0] << std::endl;
    if (str1 == str2) {
        std::cout << "str1 == str2" << std::endl;
    } else if (str1 < str2) {
        std::cout << "str1 < str2" << std::endl;
    } else {
        std::cout << "str1 > str2" << std::endl;
    }

    // 字符串查找替换
    std::cout << "字符查找:str1 \"World\" " << std::endl;
    size_t found = str1.find("World"); // 查找子字符串
    if (found != std::string::npos) {
        std::cout << "字符查找到: " << found << std::endl;
    }

    //  起始位置，替换掉的字符长度和替换为字符串
    str1.replace(found, 5, "Universe"); // 替换子字符串
    std::cout << "字符替换为: " << str1 << std::endl;
    return 0;
}

// 字符串
int stlStrings() {
    // 字符串分割
    std::string text = "apple,banana,cherry";
    size_t pos = 0;
    std::cout << "字符串分割: " << text << "," << std::endl;
    while ((pos = text.find(',')) != std::string::npos) {
        std::string token = text.substr(0, pos);
        std::cout << token << std::endl;
        text.erase(0, pos + 1);
    }
    std::cout << text << std::endl; // 最后一个部分

    // 字符数字转换
    std::string numStr = "42";
    int num = stoi(numStr);
    std::cout << "字符变数字: " << numStr << "to" << num << std::endl;
    num = 123;
    numStr = std::to_string(num);
    std::cout << "数字变字符: " << num << "to" << numStr << std::endl;

    // 遍历
    for (char c : numStr) {
        std::cout << "遍历: " << c << std::endl;
    }
    return 0;
}

// 数组测试
int stlArray() {
    // 初始化
    std::array<int, 5> my_array1;
    std::array<int, 5> my_array2 = {0, 1, 2};

    // 大小
    for (int i = 0; i < my_array1.size(); i++) {
        std::cout << "idx:" << my_array1[i] << "  size:" << my_array1.size() << std::endl;
    }

    // 或使用范围-based for 循环
    for (const auto &element : my_array2) {
        std::cout << element << std::endl;
    }
    return 0;
}

} // namespace my_string
} // namespace my_base

#endif