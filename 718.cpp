//
// Created by pzz on 2022/3/18.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;

        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                result = max(result, dp[i][j]);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums1{1, 2, 3, 2, 8};
    vector<int> nums2{5, 6, 1, 4, 7};

    Solution solution;
    cout << solution.findLength(nums1, nums2);
    return 0;
}