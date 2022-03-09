//
// Created by pzz on 2022/3/8.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums = generateNumSquares(n);
        vector<int> dp(n + 1, n);

        dp[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j <= n; j++) {
                if (dp[j - nums[i]] != n)
                    dp[j] = min(dp[j], dp[j - nums[i]] + 1);
            }
        }
        return dp[n] ;
    }

    vector<int> generateNumSquares(int n) {
        vector<int> result;
        for (int i = 1;; i++) {
            if (i * i > n)
                break;
            result.push_back(i * i);
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.numSquares(5);
    return 0;
}