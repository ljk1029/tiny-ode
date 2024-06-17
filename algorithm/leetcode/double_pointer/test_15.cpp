/**
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足
nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。





示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::vector<std::vector<int>> ret;
        int n = nums.size();
        int left, right, temp;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }

            left = i + 1;
            right = n - 1;

            while (left < right) {
                temp = nums[i] + nums[left] + nums[right];
                if (temp == 0) {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    ++left;
                    --right;
                } else if (temp < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> numbers1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = sol.threeSum(numbers1);
    for (auto &c : result1) {
        for (auto &num : c) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> numbers2 = {-1, -2, 2, -1};
    vector<vector<int>> result2 = sol.threeSum(numbers2);
    for (auto &c : result2) {
        for (auto &num : c) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}