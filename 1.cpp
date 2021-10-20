#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            if (map.count(target - nums[i]) != 0)
                return {i, map.find(target - nums[i])->second};
            map.insert({nums[i], i});
        }
        return {};
    }
};

int main() {
    return 0;
}