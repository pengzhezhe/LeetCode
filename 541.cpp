//
// Created by pzz on 2021/10/23.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};

int main() {
    string s = "abcdefg";
    int k = 2;

    Solution solution;
    cout << solution.reverseStr(s, k);
    return 0;
}