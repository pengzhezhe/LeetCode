//
// Created by pzz on 2022/6/11.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;
        for (char ch: s) {
            dp1 = ch == '0' ? dp1 + 1 : min(dp0, dp1);
            dp0 = ch == '0' ? dp0 : dp0 + 1;
        }
        return min(dp0, dp1);
    }
};

int main() {
    return 0;
}