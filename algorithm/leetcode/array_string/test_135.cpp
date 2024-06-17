/**
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。



示例 1：

输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
示例 2：

输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。

*/
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        std::vector<int> candies(n, 1); // 初始化每个孩子的糖果数为1

        // 从左到右遍历，确保评分更高的孩子获得更多的糖果
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 从右到左遍历，再次确保评分更高的孩子获得更多的糖果
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
        }

        // 计算总共需要的糖果数
        int totalCandies = 0;
        for (int num : candies) {
            totalCandies += num;
        }

        return totalCandies;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1, 2, 2, 0};
    std::cout << sol.candy(gas) << std::endl;
    return 0;
}