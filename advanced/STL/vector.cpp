#include <iostream>
#include <vector>
#include "vector.h"


// 打印
void print(std::vector<int> numbers, std::string title)
{
    std::cout << "(" << title << ")" << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// 重载
void print(std::vector<int> numbers, std::string title, char bracket)
{
    if(bracket == '(' || bracket == ')')
    {
        std::cout << "(" << title << ")" << std::endl;
    }
    else if(bracket == '[' || bracket == ']')
    {
        std::cout << "[" << title << "]" << std::endl;
    }
    else
    {
        std::cout << title << std::endl;
    }
    
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// verctor 添加删除
int stl_verctor_make()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 添加
    numbers.push_back(6);
    print(numbers, "push_back test", '(');

    // 删除
    numbers.pop_back();
    print(numbers, "pop_back test", '(');

    return 0;
}

// vector 访问
int stl_verctor_at() 
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 获取 vector 的大小
    std::cout << "size: " << numbers.size() << std::endl;

    // 访问 vector 中的元素
    std::cout << "element: " << numbers[0] << std::endl;
    std::cout << "element: " << numbers.at(1) << std::endl;
    std::cout << "element: "  << numbers.back() << std::endl;

    return 0;
}

// 删除
int stl_verctor_erase() 
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 删除指定位置的元素,第2个
    numbers.erase(numbers.begin() + 1);
    print(numbers, "erase test", '(');

    // 插入 在第3个元素前面插入10;
    numbers.insert(numbers.begin()+2, 10);
    print(numbers, "insert test", '(');

    // 清空
    numbers.clear();
    print(numbers, "clear test", '(');
    std::cout << "size: " << numbers.size() << std::endl;

    // 检查是否为空
    if (numbers.empty()) 
    {
        std::cout << "Vector is empty." << std::endl;
    }

    return 0;
}

// 遍历
int stl_verctor_iterator() 
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用迭代器遍历 vector
    std::cout << "Vector iterator: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
