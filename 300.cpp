//
// Created by pzz on 2022/3/18.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > result)
                result = dp[i];
        }
        return result;
    }
};

int main() {
    vector<int> nums{1, 3, 6, 7, 9, 4, 10, 5, 6};
    Solution solution;
    cout << solution.lengthOfLIS(nums);
    return 0;
}