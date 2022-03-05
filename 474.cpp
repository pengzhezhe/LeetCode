//
// Created by pzz on 2022/3/4.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        vector<vector<int>> counter(strs.size(), vector<int>(2, 0));

        for (int i = 0; i < strs.size(); i++)
            counter[i] = zeroOneCount(strs[i]);

        for (int j = counter[0][0]; j <= m; j++) {
            for (int k = counter[0][1]; k <= n; k++) {
                dp[0][j][k] = 1;
            }
        }

        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j >= counter[i][0] && k >= counter[i][1])
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - counter[i][0]][k - counter[i][1]] + 1);
                    else
                        dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }

        return dp[strs.size() - 1][m][n];
    }

    vector<int> zeroOneCount(string &str) {
        vector<int> result(2, 0);
        for (char c: str) {
            result[c - '0']++;
        }
        return result;
    }
};

class Solution2 {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> counter(strs.size(), vector<int>(2, 0));

        for (int i = 0; i < strs.size(); i++)
            counter[i] = zeroOneCount(strs[i]);
        for (int i = 0; i < strs.size(); i++) {
            for (int j = m; j >= counter[i][0]; j--) {
                for (int k = n; k >= counter[i][1]; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - counter[i][0]][k - counter[i][1]] + 1);
                }
            }
        }
        return dp[m][n];
    }

    vector<int> zeroOneCount(string &str) {
        vector<int> result(2, 0);
        for (char c: str) {
            result[c - '0']++;
        }
        return result;
    }
};

int main() {
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;

    Solution2 solution;
    cout << solution.findMaxForm(strs, m, n);
    return 0;
}