//
// Created by pzz on 2022/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = scores.size();
        vector<vector<int>> mp(n, vector<int>(2));

        for (int i = 0; i < n; i++) {
            mp[i] = {ages[i], scores[i]};
        }

        sort(mp.begin(), mp.end());

        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (mp[j][1] <= mp[i][1])
                    dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += mp[i][1];
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main() {
    return 0;
}