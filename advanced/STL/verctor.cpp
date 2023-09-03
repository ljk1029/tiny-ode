#include <iostream>
#include <vector>
#include <list>
#include <map>

#include "verctor.h"




// 测试用户
int main(int argc, char* argv[]) 
{
    // 使用 vector 存储整数
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用 list 存储字符串
    std::list<std::string> strList = {"apple", "banana", "orange"};

    // 使用 map 存储键值对
    std::map<std::string, int> ageMap;
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;

    // 遍历容器
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (const std::string& fruit : strList) {
        std::cout << fruit << " ";
    }
    std::cout << std::endl;

    for (const auto& entry : ageMap) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    return 0;
}