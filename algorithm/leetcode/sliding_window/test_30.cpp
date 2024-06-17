/**
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab"
都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。 返回所有串联子串在 s 中的开始索引。你可以以
任意顺序 返回答案。



示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
输出顺序无关紧要。返回 [9,0] 也是可以的。
示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
所以我们返回一个空数组。
示例 3：

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
    std::vector<int> result;
    if (words.empty() || s.empty()) {
        return result;
    }

    int word_length = words[0].length();
    int word_count = words.size();
    int total_length = word_length * word_count;

    if (s.length() < total_length) {
        return result;
    }

    // 单词映射 个数
    std::unordered_map<std::string, int> word_count_map;
    for (const auto &word : words) {
        ++word_count_map[word];
    }

    // 迭代滑动窗口 查找
    for (int i = 0; i <= s.length() - total_length; ++i) {
        std::unordered_map<std::string, int> seen_words;
        int j = 0;
        // 单词比较
        while (j < word_count) {
            std::string word = s.substr(i + j * word_length, word_length);
            if (word_count_map.find(word) != word_count_map.end()) {
                ++seen_words[word];
                // 被查找单词多于预定单词个数
                if (seen_words[word] > word_count_map[word]) {
                    break;
                }
            } else {
                break;
            }
            ++j;
        }
        // 如果所有单词的浏览次数都正确，请添加起始索引
        if (j == word_count) {
            result.push_back(i);
        }
    }

    return result;
}

// 窗口滑动
class Solution {
public:
    vector<int> findSubstring(string &s, vector<string> &words) {
        vector<int> res;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + m * n <= ls; ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (string &word : words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }

            // 窗口滑动n为步进
            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    // 添加下个步进 字符串
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    // 去掉上个步进 字符串
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};

int main() {
    std::string s1 = "barfoothefoobarman";
    std::vector<std::string> words1 = {"foo", "bar"};
    std::vector<int> result1 = findSubstring(s1, words1);
    for (int idx : result1) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    std::string s2 = "wordgoodgoodgoodbestword";
    std::vector<std::string> words2 = {"word", "good", "best", "word"};
    std::vector<int> result2 = findSubstring(s2, words2);
    for (int idx : result2) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    std::string s3 = "barfoofoobarthefoobarman";
    std::vector<std::string> words3 = {"bar", "foo", "the"};
    std::vector<int> result3 = findSubstring(s3, words3);
    for (int idx : result3) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    Solution sol;
    std::vector<int> result4 = sol.findSubstring(s3, words3);
    for (int idx : result3) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    return 0;
}
