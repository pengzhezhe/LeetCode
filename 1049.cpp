//
// Created by pzz on 2022/1/5.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }

        vector<vector<int>> dp(stones.size(), vector<int>(sum / 2 + 1, 0));

        for (int j = stones[0]; j <= sum / 2; j++) {
            dp[0][j] = stones[0];
        }

        for (int i = 1; i < stones.size(); i++) {
            for (int j = 0; j <= sum / 2; j++) {
                if (j < stones[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp[stones.size() - 1][sum / 2];
    }
};

class Solution2 {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }

        vector<int> dp(sum / 2 + 1, 0);

        for (int i = 0; i < stones.size(); i++) {
            for (int j = sum / 2; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp[sum / 2];
    }
};


int main() {

}