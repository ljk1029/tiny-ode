/**
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 

示例 1:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
#include "../common.h"

using namespace std;

class MinStack {
stack<int> x_stack;
stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        min_stack.pop();
        x_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};


int main() {
    MinStack sol;
    //sol.MinStack();
    sol.push(2);
    sol.push(0);
    sol.push(3);
    sol.push(0);
    std::cout << sol.getMin() << std::endl;
    sol.pop();
    std::cout << sol.getMin() << std::endl;
    sol.pop();
    std::cout << sol.getMin() << std::endl;
    sol.pop();
    std::cout << sol.getMin() << std::endl;
    return 0;
}

