/**
给定一个字符串 s ，请你找出其中不含有重复字符的 最长
子串的长度。



示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if (n == 0)
        return 0;

    unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        if (charIndexMap.find(s[right]) != charIndexMap.end() && charIndexMap[s[right]] >= left) {
            left = charIndexMap[s[right]] + 1;
        }

        charIndexMap[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
        cout << "len:" << maxLength << endl;
    }

    return maxLength;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 输出: 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;    // 输出: 1
    cout << lengthOfLongestSubstring("pwwkew") << endl;   // 输出: 3
    cout << lengthOfLongestSubstring(" ") << endl;        // 输出: 3
    return 0;
}
