#include "my_list.h"

using namespace my_list;

// 链表测试
void testListInit() {
    my_list::LinkedList<int> list;
    list.printList("test1");
    list.clearList();
    list.printList("test1");
}

void testListAdd() {
    my_list::LinkedList<int> list;
    int data = 42;
    int key = 1;

    list.addList(key, data);
    list.printList("test2, Add");

    list.addList(key, data); // Adding the same key again should fail

    list.delList(key);
    list.printList("test2, Del");

    list.delList(key); // Deleting a non-existent key should fail
    list.printList("test2, Del");
}

void testListFind() {
    my_list::LinkedList<std::string> list;
    std::string data1 = "42";
    std::string data2 = "100";
    int key1 = 1;
    int key2 = 2;

    list.addList(key1, data1);
    list.addList(key2, data2);

    std::string foundData1;
    std::string foundData2;

    list.findList(key1, foundData1);
    list.findList(key2, foundData2);

    std::cout << foundData1 << std::endl;
    std::cout << foundData2 << std::endl;
}

void testListThread() {
    my_list::LinkedList<std::string> list;
    std::vector<std::thread> threads;
    const int num_threads = 10;
    const int num_adds = 100;

    // 启动多个线程进行添加操作
    for (int i = 0; i < num_threads; i++) {
        threads.emplace_back([&list]() {
            for (int j = 0; j < num_adds; j++) {
                std::string data = "String_" + std::to_string(j);
                list.addList(j, data);
            }
        });
    }

    // list.print();

    // 等待所有线程完成
    for (auto &thread : threads) {
        thread.join();
    }

    std::cout << list.getListSize() << std::endl;

    // 启动多个线程进行删除操作
    threads.clear();
    for (int i = 0; i < num_threads; i++) {
        threads.emplace_back([&list, &i]() {
            for (int j = 0; j < num_adds; j++) {
                list.delList(j);
            }
        });
    }

    // 等待所有线程完成
    for (auto &thread : threads) {
        thread.join();
    }

    std::cout << list.getListSize() << std::endl;
}

void testListClear() {
    my_list::LinkedList<std::string> list(10, true);
    const int num_adds = 12;
    for (int i = 0; i < num_adds; i++) {
        std::string data = "String_" + std::to_string(i);
        list.addList(i, data);
    }
    list.printList("-");

    list.clearList();
    list.printList("clear");

    for (int i = 0; i < num_adds; i++) {
        std::string data = "String_" + std::to_string(i);
        list.addList(i, data);
    }
    list.printList("add");
    std::cout << list.getListSize() << std::endl;

    for (int i = 0; i < num_adds; i++) {
        if (i % 2) {
            list.delList(i);
        }
        std::string data = "String_" + std::to_string(i);
        list.addList(i + 8, data);
    }
    list.printList("change");
}

using CallbackFunc = std::function<void()>;
// 测试回调
int printFunc(const std::string &title, CallbackFunc callback) {
    std::cout << "======"
              << "[" << title << " test]"
              << "=====" << std::endl;
    callback();
    std::cout << "--------[test end]--------\n\n";
    return 0;
}

// 测试函数入口
int main(int argc, char *argv[]) {
    printFunc("test_list_init  ", testListInit);
    printFunc("test_list_add   ", testListAdd);
    printFunc("test_list_find  ", testListFind);
    printFunc("test_list_thread", testListThread);
    printFunc("test_list_clear ", testListClear);
    return 0;
}
