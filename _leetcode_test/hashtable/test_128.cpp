/**
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。



示例 1：

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：

输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print_num(std::vector<std::vector<int>> &board) {
    int rows = board.size();
    int cols = board[0].size();
    std::cout << "***********************************" << std::endl;
    for (int i = 0, j = 0; i < rows; j++) {
        std::cout << std::setw(4) << board[i][j];
        if (j == cols - 1) {
            std::cout << std::endl;
            j = -1;
            i++;
        }
    }
    std::cout << "-----------------------------------" << std::endl;
}

void print_num(std::vector<int> &board) {
    int rows = board.size();
    std::cout << "***********************************" << std::endl;
    for (int i = 0; i < rows; i++) {
        std::cout << std::setw(4) << board[i];
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

void print_num(int board) {
    std::cout << "***********************************" << std::endl;
    std::cout << std::setw(4) << board;
    std::cout << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

void print_num(std::vector<std::vector<std::string>> &board) {
    std::cout << "***********************************" << std::endl;
    for (auto r : board) {
        for (auto c : r) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}

void print_num(std::vector<std::string> &board) {
    std::cout << "***********************************" << std::endl;
    for (auto r : board) {
        std::cout << r << " ";
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> m;
        int result = 0;
        for (int n : nums) {
            if (m.find(n) != m.end())
                continue;
            int left = m.find(n - 1) == m.end() ? 0 : m[n - 1];
            int right = m.find(n + 1) == m.end() ? 0 : m[n + 1];
            int len = left + right + 1;
            m[n] = 1;
            m[n - left] = m[n + right] = len;
            result = max(result, len);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> s = {100, 4, 200, 1, 3, 2};
    std::cout << sol.longestConsecutive(s) << std::endl;
    return 0;
}
