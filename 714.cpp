//
// Created by pzz on 2021/12/30.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int result = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            else if (prices[i] >= minPrice && prices[i] <= minPrice + fee)
                continue;
            else {
                result += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
            };
        }
        return result;
    }
};

int main() {
    return 0;
}