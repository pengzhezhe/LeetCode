//
// Created by pzz on 2021/12/14.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        int minPrice = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                result += prices[i] - minPrice;
                minPrice = prices[i];
            }
        }
        return result;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return dp[prices.size() - 1][1];
    }
};

int main() {
    Solution solution;
    vector<int> prices{1, 1, 0};
    int result = solution.maxProfit(prices);
    cout << result;
    return 0;
}