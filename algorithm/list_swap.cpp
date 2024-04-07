/**
 * 文件名: Xxx.c
 * 作者: ljk
 * 创建时间: 2023-08-03
 * 文件描述: 链表n个节点反转
 * 版本: V 1.0.0
 */
#include <iostream>
#include <vector>

using namespace std;

// 链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int value, ListNode *ptr) : val(value), next(ptr) {}
};

// 打印声明
void listPrint(ListNode *list);

// 2节点交换
ListNode *swapListFun(ListNode *list, int n) {
    ListNode *head = list;
    if (head == NULL || head->next == NULL) {
        return head;
    }

    head = head->next;
#if 0
    list->next = swapListFun(head->next, n);
    head->next = list;
#elif 1

    ListNode *next = list, *prev = NULL;
    while (next) {
        if (next->next == NULL) {
            break;
        }
        printf("%p %p\n", next, next->next);
        ListNode *last = next->next->next;
        ListNode *second = next->next;
        second->next = next;
        next->next = last;

        if (prev) {
            prev->next = second;
        }
        prev = next;
        next = last;
    }

#endif

    return head;
}

ListNode *swapListFun_n(ListNode *list, int n) {
    ListNode *head = list;
    if (head == NULL || head->next == NULL) {
        return head;
    }

    head = head->next;
    list->next = swapListFun(head->next, n);
    head->next = list;

    return head;
}

// 链表打印
void listPrint(ListNode *list) {
    std::cout << std::endl;
    while (list) {
        std::cout << list->val << "addr:" << list << std::endl;
        list = list->next;
    }
}

int main(int argc, char *argv[]) {
    // int a;
    // cin >> a;

    ListNode *head = nullptr;
    for (int i = 0; i < 7; i++) {
        head = new ListNode(i, head);
    }

    listPrint(head);
    head = swapListFun(head, 2);
    listPrint(head);

    cout << "Hello World!" << endl;
}