//
// Created by pzz on 2022/1/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        vector<int> cost{1, 2};
        dp[0] = 1;

        for (int j = 0; j <= n; j++) {
            for (int i = 0; i < 2; i++) {
                if (j >= cost[i])
                    dp[j] += dp[j - cost[i]];
            }
        }
        return dp[n];
    }
};

int main() {
    return 0;
}