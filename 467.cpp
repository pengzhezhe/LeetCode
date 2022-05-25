//
// Created by pzz on 2022/5/25.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int n = p.size(), len = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && (p[i] - p[i - 1] + 26) % 26 == 1)
                len++;
            else
                len = 1;

            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], len);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main() {
    return 0;
}