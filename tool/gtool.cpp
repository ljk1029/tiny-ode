
#include "datatool.h"
// 使用data_tool
// 编译加g++ -std=c++17 gtool.cpp -lgtest -lgtest_main -lpthread
using namespace data_tool;



//gtest测试框架
#include <gtest/gtest.h>


// 1、接口测试
TEST(CustomLinkedListTest, EmptyList) {
    CustomLinkedList<int> list;
    EXPECT_EQ(list.GetSize(), 0);

    list.Clear();
    EXPECT_EQ(list.GetSize(), 0);
}

// 2、添加删除测试
TEST(CustomLinkedListTest, AddAndDelete) {
    CustomLinkedList<int> list;
    int data = 42;
    int key = 1;

    EXPECT_TRUE(list.Add(key, data));
    EXPECT_EQ(list.GetSize(), 1);

    EXPECT_FALSE(list.Add(key, data)); // Adding the same key again should fail

    EXPECT_TRUE(list.Delete(key));
    EXPECT_EQ(list.GetSize(), 0);

    EXPECT_FALSE(list.Delete(key)); // Deleting a non-existent key should fail
}

// 3、添加、查找测试
TEST(CustomLinkedListTest, Find) {
    CustomLinkedList<std::string> list;
    std::string data1 = "42";
    std::string data2 = "100";
    int key1 = 1;
    int key2 = 2;

    EXPECT_TRUE(list.Add(key1, data1));
    EXPECT_TRUE(list.Add(key2, data2));

    std::string  foundData1;
    std::string  foundData2;

    EXPECT_TRUE(list.Find(key1, foundData1));
    EXPECT_TRUE(list.Find(key2, foundData2));

    EXPECT_EQ(foundData1, data1);
    EXPECT_EQ(foundData2, data2);
}

//多线程测试
TEST(CustomLinkedListTest, MultipleThreads) {
    CustomLinkedList<std::string> list;
    const int num_threads = 10;
    const int num_adds = 100;

    std::vector<std::thread> threads;

    // 启动多个线程进行添加操作
    for (int i = 0; i < num_threads; i++) {
        threads.emplace_back([&list]() {
            for (int j = 0; j < num_adds; j++) {
                std::string data = "String_" + std::to_string(j);
                list.Add(j, data);
            }
        });
    }

    //list.print();

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    // 验证列表大小是否正确
    EXPECT_EQ(list.GetSize(), num_adds);

    // 启动多个线程进行删除操作
    threads.clear();
    for (int i = 0; i < num_threads; i++) {
        threads.emplace_back([&list, &i]() {
            for (int j = 0; j < num_adds; j++) {
                list.Delete(j);
            }
        });
    }

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    // 验证列表是否为空
    EXPECT_EQ(list.GetSize(), 0);
}

// 内容测试
TEST(CustomLinkedListTest, content) 
{
    CustomLinkedList<std::string> list(10, true);
    const int num_adds = 12;
    for (int i = 0; i < num_adds; i++) {
        std::string data = "String_" + std::to_string(i);
        list.Add(i, data);
    }

    list.print();

    // 验证列表大小是否正确
    EXPECT_EQ(list.GetSize(), 10);

    list.Clear();
    list.print("clear");
    EXPECT_EQ(list.GetSize(), 0);

    for (int i = 0; i < num_adds; i++) {
        std::string data = "String_" + std::to_string(i);
        list.Add(i, data);
    }
    list.print("add");

    EXPECT_EQ(list.GetSize(), 10);

    for (int i = 0; i < num_adds; i++) {
        if(i%2){
            list.Delete(i);
        }
        std::string data = "String_" + std::to_string(i);
        list.Add(i+8, data);
    }

    list.print("change");
}

// Add more test cases as needed

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}