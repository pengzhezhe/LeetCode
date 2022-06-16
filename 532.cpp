//
// Created by pzz on 2022/6/16.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> map;

        for (int num: nums) {
            map[num]++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (map.count(nums[i] + k)) {
                if (k == 0 && map[nums[i]] == 1) {
                    continue;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}