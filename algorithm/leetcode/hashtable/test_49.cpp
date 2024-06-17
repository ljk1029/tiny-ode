/**
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。



示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]

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
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (string &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = map.begin(); it != map.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(s);
    print_num(result);
    return 0;
}
