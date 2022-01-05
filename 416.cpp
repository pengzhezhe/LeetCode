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
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
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

int main() {
    return 0;
}