//
// Created by pzz on 2022/3/9.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), false);
        dp[0] = true;

        for (int j = 1; j <= s.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (set.find(s.substr(i, j - i)) != set.end() && dp[i])
                    dp[j] = true;
            }
        }

        return dp[s.size()];
    }
};

int main() {
    return 0;
}