import bisect
from collections import defaultdict


def sort():
    # 有序列表
    a = [1, 3, 5, 7, 9]

    # 查找元素 6 的插入位置
    index = bisect.bisect_left(a, 6)
    print("元素 6 应该插入的位置索引:", index)

    # 查找元素 3 的插入位置
    index = bisect.bisect_left(a, 3)
    print("元素 3 应该插入的位置索引:", index)

    # 查找元素 10 的插入位置
    index = bisect.bisect_left(a, 10)
    print("元素 10 应该插入的位置索引:", index)

    index = bisect.bisect_left(a, 0)
    print("元素 6 应该插入的位置索引:", index)

def sum_map():
    words = ["word", "good", "best", "word"]
    all_len = sum(map(len, words))
    print(all_len)
    from collections import Counter
    words = Counter(words)
    print(words)


def minWindow(s: str, t: str) -> str:
    n, m = len(s), len(t)
    if n < m or n==0:
        return ""
    
    target_map = defaultdict(int)
    for c in t:
        target_map[c] += 1
    
    required_chars = m
    left = 0
    right = 0
    min_len = float('inf')
    min_start = 0

    while right < n:
        if target_map[s[right]] > 0:
            required_chars -= 1
        target_map[s[right]] -= 1
        right += 1

        while required_chars == 0:
            if right-left < min_len:
                min_len = right-left
                min_start = left

            if target_map[s[left]] == 0:
                required_chars += 1
            target_map[s[left]] += 1
            left += 1
    return "" if min_len==float('inf') else s[min_start:min_start+min_len]

if __name__ == '__main__' :
    #sort()
    #sum_map()

    s = "ADOBECODEBANC"
    t = "ABC"
   # print(minWindow(s, t))  # Output: "BANC"
    for i in range(3, -1, -1):
        print(i)
    for i in range(1, 5):
        print(i)