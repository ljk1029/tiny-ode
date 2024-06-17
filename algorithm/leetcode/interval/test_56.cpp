/**
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回
一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。



示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/
#include <iostream>
#include <iomanip>
#include <vector>
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
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> ret;
        if (intervals.empty())
            return ret;

        sort(intervals.begin(), intervals.end()); // 先按区间起始位置进行排序

        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= ret.back()[1]) {
                // 当前区间与前一个区间重叠，更新前一个区间的结束位置
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            } else {
                // 当前区间与前一个区间不重叠，直接加入到结果中
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> numbers1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result1 = sol.merge(numbers1);
    print_num(result1);
    return 0;
}