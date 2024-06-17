/* 题目描述

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的
子数组
 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。



示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    Solution() {}

public:
    void inputArray() {
        int numCount;

        cout << "请输入目标值: ";
        cin >> target;

        cout << "请输入数组的个数: ";
        cin >> numCount;
        cout << "请输入数组元素: ";
        for (int i = 0; i < numCount; ++i) {
            int num;
            cin >> num;
            nums.push_back(num);
        }
    }

    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        int result = ans == INT_MAX ? 0 : ans;
        cout << "最小子数组长度为: " << result << endl;
        return result;
    }

    int sum() {
        inputArray();
        return minSubArrayLen(target, nums);
    }

private:
    vector<int> nums;
    int target;
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    sol.minSubArrayLen(7, nums);
    nums.assign({1, 4, 4});
    sol.minSubArrayLen(4, nums);
    nums.assign({1, 1, 1, 1, 1, 1, 1, 1});
    sol.minSubArrayLen(11, nums);
    return 0;
}
