//
// Created by pzz on 2022/3/18.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                dp[i] = max(dp[i], dp[i - 1] + 1);

            result = max(result, dp[i]);
        }

        return result;
    }
};

int main() {
    vector<int> nums{1, 3, 5, 4, 7};
    Solution solution;
    cout << solution.findLengthOfLCIS(nums);
    return 0;
}