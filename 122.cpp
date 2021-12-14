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
        int buy = INT_MAX;
        bool sold = true;

        if (prices.size() <= 1)
            return result;

        for (int i = 0; i < prices.size(); i++) {
            if (sold && i + 1 < prices.size() && prices[i + 1] > prices[i]) {
                buy = prices[i];
                sold = false;
            } else if ((!sold && i + 1 < prices.size() && prices[i] > buy && prices[i] >= prices[i + 1]) || (!sold && i == prices.size() - 1)) {
                result += prices[i] - buy;
                sold = true;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> prices{1, 1,0};
    int result = solution.maxProfit(prices);
    cout << result;
    return 0;
}