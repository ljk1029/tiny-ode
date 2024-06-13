/**
实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
*/

#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> hashMap;
    vector<int> nums;

public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (hashMap.find(val) != hashMap.end())
            return false;
        
        nums.push_back(val);
        hashMap[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (hashMap.find(val) == hashMap.end())
            return false;
        
        int index = hashMap[val];
        hashMap[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        hashMap.erase(val);
        return true;
    }

    int getRandom() {
        int randomIdex = rand() % nums.size();
        return nums[randomIdex];
    }
};


int main() {
    RandomizedSet* randomizedSet = new RandomizedSet();
    std::cout << randomizedSet->insert(1) << std::endl; // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    std::cout << randomizedSet->remove(2) << std::endl; // 返回 false ，表示集合中不存在 2 。
    std::cout << randomizedSet->insert(2) << std::endl; // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    std::cout << randomizedSet->getRandom() << std::endl; // getRandom 应随机返回 1 或 2 。
    std::cout << randomizedSet->remove(1) << std::endl; // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    std::cout << randomizedSet->insert(2) << std::endl; // 2 已在集合中，所以返回 false 。
    std::cout << randomizedSet->getRandom() << std::endl; // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
}