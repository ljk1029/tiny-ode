// string 用法类
#ifndef STL_STRING_H
#define STL_STRING_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class StringExample {
public:
    // 构造与初始化
    void demo_make() {
        std::string s1 = "Hello";
        std::string s2("World");
        std::string s3(5, 'A');
        std::cout << "构造: " << s1 << ", " << s2 << ", " << s3 << std::endl;
    }

    // 连接与追加
    void demo_concat_append() {
        std::string s = "Hello";
        s += " World";
        s.append("!");
        std::cout << "连接与追加: " << s << std::endl;
    }

    // 长度与判空
    void demo_size_empty() {
        std::string s = "abc";
        std::cout << "长度: " << s.size() << ", 判空: " << (s.empty() ? "true" : "false") << std::endl;
    }

    // 访问与遍历
    void demo_access_iter() {
        std::string s = "abcde";
        std::cout << "访问: " << s[0] << ", " << s.at(1) << std::endl;
        std::cout << "遍历: ";
        for (char c : s) std::cout << c << " ";
        std::cout << std::endl;
    }

    // 比较
    void demo_compare() {
        std::string s1 = "abc";
        std::string s2 = "abd";
        std::cout << "比较: " << (s1 == s2 ? "相等" : (s1 < s2 ? "小于" : "大于")) << std::endl;
    }

    // 查找与替换
    void demo_find_replace() {
        std::string s = "Hello World";
        size_t pos = s.find("World");
        if (pos != std::string::npos) {
            std::cout << "查找到位置: " << pos << std::endl;
            s.replace(pos, 5, "C++");
        }
        std::cout << "替换后: " << s << std::endl;
    }

    // 分割
    void demo_split() {
        std::string text = "a,b,c";
        std::vector<std::string> tokens;
        size_t start = 0, end = 0;
        while ((end = text.find(',', start)) != std::string::npos) {
            tokens.push_back(text.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(text.substr(start));
        std::cout << "分割: ";
        for (const auto& t : tokens) std::cout << t << " ";
        std::cout << std::endl;
    }

    // 字符与数字转换
    void demo_num_convert() {
        std::string num_str = "123";
        int num = std::stoi(num_str);
        std::cout << "字符串转数字: " << num << std::endl;
        num = 456;
        num_str = std::to_string(num);
        std::cout << "数字转字符串: " << num_str << std::endl;
    }

    // 插入、删除、清空
    void demo_insert_erase_clear() {
        std::string s = "abcdef";
        s.insert(3, "XYZ");
        std::cout << "插入: " << s << std::endl;
        s.erase(2, 4);
        std::cout << "删除: " << s << std::endl;
        s.clear();
        std::cout << "清空后判空: " << (s.empty() ? "true" : "false") << std::endl;
    }

    // 反转
    void demo_reverse() {
        std::string s = "abcdef";
        std::reverse(s.begin(), s.end());
        std::cout << "反转: " << s << std::endl;
    }
};

#endif // STL_STRING_H