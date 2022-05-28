//
// Created by pzz on 2022/5/28.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int count = 0;
        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')')
                count--;
            if (count > 0)
                ans.push_back(s[i]);
            if (s[i] == '(')
                count++;
        }
        return ans;
    }
};

int main() {
    return 0;
}