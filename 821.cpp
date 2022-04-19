//
// Created by pzz on 2022/4/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n);
        for (int i = 0, idx = -n; i < n; i++) {
            if (s[i] == c)
                idx = i;
            ans[i] = i - idx;
        }

        for (int i = n - 1, idx = 2 * n; i >= 0; i--) {
            if (s[i] == c)
                idx = i;
            ans[i] = min(idx - i, ans[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}