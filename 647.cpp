//
// Created by pzz on 2022/3/23.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int result = s.size();
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                result = isPalindrome(s.substr(i, j - i + 1)) ? result + 1 : result;
            }
        }
        return result;
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};

class Solution2 {
public:
    int countSubstrings(string s) {
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    result = dp[i][j] ? result + 1 : result;
                }
            }
        }
        return result;
    }
};

int main() {
    string s = "abc";
    Solution2 solution;
    cout << solution.countSubstrings(s);
    return 0;
}