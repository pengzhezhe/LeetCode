//
// Created by pzz on 2022/1/5.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        vector<int> dp(sum / 2 + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum / 2; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[sum / 2] == sum / 2;
    }
};

class Solution2 {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, 0));

        for (int j = nums[0]; j <= sum / 2; j++) {
            dp[0][j] = nums[0];
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= sum / 2; j++) {
                if (j < nums[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }

        return dp[nums.size() - 1][sum / 2] == sum / 2;
    }
};

int main() {
    return 0;
}