/**
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

 

示例 1：

输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
     总利润为 4 + 3 = 7 。
示例 2：

输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     总利润为 4 。
示例 3：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 
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
    int maxProfit(vector<int>& prices) {
        print_num(prices);
        int n = prices.size();
        if(n <= 1)
            return 0;
        int sum = 0, p = prices[0];

        for(int i=1; i<n; i++) {
            if(prices[i] > p) {
                sum += prices[i] -p;
            }
            p = prices[i];
        }
        print_num(sum);
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> numbers1 = {7,1,5,3,6,4};
    sol.maxProfit(numbers1);
    return 0;
}