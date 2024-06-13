/**
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

 

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
示例 2：


输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Solution {
public:
    void print(vector<vector<int>>& matrix) {
        int n = matrix.size();
        std::cout << "*******" << std::endl;
        for(int i=0, j=0; i<n; j++) {
            std::cout << std::setw(4) << matrix[i][j] ;
            if(j == n-1) {
                std::cout << std::endl;
                j=-1;
                i++;
            }
        }
        std::cout << "--------" << std::endl;
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        print(matrix);
        for(int i=0; 2*i+1<n; i++) {
            for(int j=i; j<n-i-1; j++) {
                int x=matrix[i][j];
                std::cout << i << ", " << j << std::endl;
                // 左
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = x;
                print(matrix);
            }
            //print(matrix);
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> numbers1 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(numbers1);
    return 0;
}