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

int main() {
    Solution solution;
    vector<int> prices{1, 1, 0};
    int result = solution.maxProfit(prices);
    cout << result;
    return 0;
}