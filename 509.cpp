//
// Created by pzz on 2022/1/3.
//

#include <iostream>

class Solution {
public:
    int fib(int n) {
        int dp[31];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    return 0;
}