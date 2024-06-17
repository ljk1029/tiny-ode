/**
有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend]
表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为
xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。
弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。


示例 1：

输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：气球可以用2支箭来爆破:
-在x = 6处射出箭，击破气球[2,8]和[1,6]。
-在x = 11处发射箭，击破气球[10,16]和[7,12]。
示例 2：

输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
解释：每个气球需要射出一支箭，总共需要4支箭。
示例 3：

输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
解释：气球可以用2支箭来爆破:
- 在x = 2处发射箭，击破气球[1,2]和[2,3]。
- 在x = 4处射出箭，击破气球[3,4]和[4,5]。
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

// 使用贪心算法，以结尾排序
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty())
            return 0;

        // 按照气球的结束坐标进行排序
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

        int arrows = 1;            // 初始化箭的数量为 1
        int endPos = points[0][1]; // 初始化箭射出的位置为第一个气球的结束坐标

        // 遍历气球，尽可能地射出一支箭
        for (int i = 1; i < points.size(); ++i) {
            // 如果当前气球的开始坐标大于箭的位置，则需要再射出一支箭
            if (points[i][0] > endPos) {
                ++arrows;
                endPos = points[i][1]; // 更新箭射出的位置为当前气球的结束坐标
            }
        }

        return arrows;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> numbers1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::cout << sol.findMinArrowShots(numbers1);
    return 0;
}