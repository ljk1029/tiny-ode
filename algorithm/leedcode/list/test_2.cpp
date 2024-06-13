/**
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1] 
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include "../common.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if(l1 != nullptr && l2 != nullptr) {
                carry = l1->val + l2->val + carry;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1 != nullptr) {
                carry = l1->val + carry;
                l1=l1->next;
            }
            else if(l2 != nullptr) {
                carry = l2->val + carry;
                l2=l2->next;
            }
            ListNode* temp = new ListNode(carry%10);
            temp->next = nullptr;
            if(head == nullptr) {
                head = temp;
                tail = head;
            } 
            else {
                tail->next = temp;
                tail = tail->next;
            }
            carry /= 10;
        }

        if(carry) {
            ListNode* temp = new ListNode(carry%10);
            tail->next = temp;
            tail = tail->next;
        }
        return head;
    }
};

void print_list(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        current = current->next;
        if ( current ) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}


int main() {
    Solution sol;
    ListNode* l1 = new ListNode(7);
    l1 = new ListNode(2, l1);
    l1 = new ListNode(6, l1);
    l1 = new ListNode(9, l1);
    ListNode* l2 = new ListNode(9);
    l2 = new ListNode(2, l2);
    print_list(l1);
    print_list(l2);
    ListNode* result1 = sol.addTwoNumbers(l1, l2);
    print_list(result1);
    return 0;
}

