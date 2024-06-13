/**
 * 
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include "../common.h"

using namespace std;

class Solution {

};

int main() {
    Solution sol;
    vector<int> numbers1 = {2,3,1,1,4};
    vector<vector<int>> result1 = sol.romanToInt(numbers1) << std::endl;
    print_dbg(result1);
    return 0;
}

