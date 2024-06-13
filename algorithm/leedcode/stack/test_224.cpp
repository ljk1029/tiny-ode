/**
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。

 

示例 1：

输入：s = "1 + 1"
输出：2
示例 2：

输入：s = " 2-1 + 2 "
输出：3
示例 3：

输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23
 
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <unordered_map>
#include "../common.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int num = 0; // 当前数字
        int result = 0; // 当前结果
        int sign = 1; // 当前符号，1表示正号，-1表示负号
        std::stack<int> stack;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // 构建当前数字
            } else if (c == '+') {
                result += sign * num; // 更新结果
                num = 0; // 重置当前数字
                sign = 1; // 更新符号
            } else if (c == '-') {
                result += sign * num; // 更新结果
                num = 0; // 重置当前数字
                sign = -1; // 更新符号
            } else if (c == '(') {
                // 将当前结果和符号入栈，重置结果和符号
                stack.push(result);
                stack.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                // 计算当前括号内的结果，并与栈顶结果相加
                result += sign * num;
                num = 0;
                result *= stack.top(); // 栈顶符号
                stack.pop();
                result += stack.top(); // 栈顶结果
                stack.pop();
            } else if (c == ' ') {
                continue; // 跳过空格字符
            }
        }

        // 处理最后一个数字
        result += sign * num;

        return result;
    }
};

int main() {
    Solution sol;
    string s = "1 + 1";
    std::cout << sol.calculate(s) << std::endl;

    return 0;
}

