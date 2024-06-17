/**
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。



示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：


输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ret;
        int n = matrix.size();
        if (n == 0)
            return ret;
        int m = matrix[0].size();
        int h = n, v = m;

        // ret.push_back(matrix[0][0]);
        for (int i = 0; 2 * i < n && 2 * i < m; i++) {
            std::cout << "-----1" << endl;
            // 上
            int cnt = i;
            while (cnt < m - i) {
                std::cout << "u:" << matrix[i][cnt] << " i" << cnt << std::endl;
                ret.push_back(matrix[i][cnt++]);
            }
            if (--h == 0)
                break;
            std::cout << "------2" << endl;
            // 右
            cnt = i + 1;
            while (cnt < n - i) {
                std::cout << "r:" << matrix[cnt][m - i - 1] << " i" << cnt << std::endl;
                ret.push_back(matrix[cnt++][m - i - 1]);
            }
            if (--v == 0)
                break;
            std::cout << "-------3" << endl;
            // 下
            cnt = m - i - 2;
            while (cnt >= i) {
                std::cout << "d:" << matrix[n - i - 1][cnt] << " i" << cnt << std::endl;
                ret.push_back(matrix[n - i - 1][cnt--]);
            }
            if (--h == 0)
                break;
            std::cout << "--------4" << endl;
            // 左
            cnt = n - i - 2;
            while (cnt >= i + 1) {
                std::cout << "l:" << matrix[cnt][i] << " i" << cnt << std::endl;
                ret.push_back(matrix[cnt--][i]);
            }
            if (--v == 0)
                break;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> numbers1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result1 = sol.spiralOrder(numbers1);
    for (auto &c : result1)
        std::cout << c << " ";
    std::cout << endl;

    vector<vector<int>> numbers2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result2 = sol.spiralOrder(numbers2);
    for (auto &c : result2)
        std::cout << c << " ";
    std::cout << endl;
    return 0;
}