/**
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i] 
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

 

示例 1:

输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
示例 2:

输入: nums = [2,3,0,1,4]
输出: 2
*/

#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

void print_num(std::vector<std::vector<int>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    std::cout << "***********************************" << std::endl;
    for(int i=0, j=0; i<rows; j++) {
        std::cout << std::setw(4) << board[i][j] ;
        if(j == cols-1) {
            std::cout << std::endl;
            j=-1;
            i++;
        }
    }
    std::cout << "-----------------------------------" << std::endl;
}

void print_num(std::vector<int>& board) {
    int rows = board.size();
    std::cout << "***********************************" << std::endl;
    for(int i=0; i<rows; i++) {
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


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n-1; ) {
            cnt++;
            // if(nums[0] == 0) {} 防止不移动

            if(i+nums[i] < n-1) {
                int max_temp = nums[i], step = 0;
                for(int j=1; j<=nums[i]; j++) {
                    std::cout << max_temp << " " << j << " " << nums[i+j] << std::endl;
                    if(max_temp < j+nums[i+j]) {
                        step = j;
                        max_temp = j+nums[i+j];
                    }
                }
                if( step == 0) {
                    i += nums[i];
                    std::cout << "ix:" << nums[i] << std::endl;
                    
                }
                else {
                    i += step;
                    std::cout << "ixxxx:" << step << std::endl;
                }
            } 
            else {
                i += nums[i]; 
            }
            std::cout << "i:" << i << std::endl;
            std::cout << "cnt:" << cnt << std::endl;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    //vector<int> numbers1 = {2,3,1,1,4};
    vector<int> numbers1 = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    sol.jump(numbers1);
    return 0;
}
