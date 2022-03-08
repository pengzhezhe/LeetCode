//
// Created by pzz on 2022/3/8.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);

        dp[0] = 1;
        //TODO 注意遍历顺序，组合必须先物品，排列必须先背包（仅限一维）
        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]])
                    dp[j] += dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};

int main() {
    return 0;
}