//
// Created by pzz on 2022/5/9.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans(n + 1, 0);
        int low = 0, high = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I')
                ans[i] = low++;
            else
                ans[i] = high--;
        }
        ans[n] = low;
        return ans;
    }
};

int main() {
    return 0;
}