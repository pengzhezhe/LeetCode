//
// Created by pzz on 2022/1/3.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);

        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }

        return dp[n];
    }
};

int main() {
    return 0;
}