//
// Created by pzz on 2022/3/7.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));

        dp[0][0] = 1;

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] += 1;
        }

        for (int i = 1; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (j >= coins[i]) {
                    dp[i][j] += dp[i - 1][j - coins[i]];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[coins.size() - 1][amount];
    }
};

class Solution2 {
public:
    int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};


int main() {
    return 0;
}