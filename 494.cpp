//
// Created by pzz on 2022/1/5.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (auto n: nums)
            sum += n;

        if ((target + sum) % 2 != 0)
            return 0;

        if (abs(target) > sum)
            return 0;

        int bagSize = (target + sum) / 2;

        //从0至i的物品中选择物品装满容积为j的背包共有dp[i][j]种方法
        vector<vector<int>> dp(nums.size(), vector<int>(bagSize + 1, 0));

        dp[0][0] = 1;

        for (int j = 0; j <= bagSize; j++)
            if (nums[0] == j)
                dp[0][j] += 1;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= bagSize; j++) {
                if (j >= nums[i])
                    dp[i][j] += dp[i - 1][j - nums[i]];
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[nums.size() - 1][bagSize];
    }
};

class Solution2 {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (auto n: nums)
            sum += n;

        if ((target + sum) % 2 != 0)
            return 0;

        if (abs(target) > sum)
            return 0;

        int bagSize = (target + sum) / 2;

        vector<int> dp(bagSize + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[bagSize];
    }
};

int main() {
    vector<int> nums{0, 0, 0, 0, 0, 0, 0, 0, 1};
    int target = 1;
    Solution solution;
    cout << solution.findTargetSumWays(nums, target);
    return 0;
}