//
// Created by pzz on 2021/12/14.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result)
                result = count;
            if (count < 0) {
                count = 0;
                continue;
            }
        }
        return result;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, INT_MIN);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = dp[i] > result ? dp[i] : result;
        }
        return result;
    }
};

int main() {
    return 0;
}