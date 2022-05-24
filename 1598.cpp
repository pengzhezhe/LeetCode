//
// Created by pzz on 2022/5/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<string> &logs) {
        int ans = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i][0] != '.')
                ans++;
            else if (logs[i][0] == '.' && logs[i][1] == '.')
                ans = ans > 0 ? ans - 1 : ans;
        }
        return ans;
    }
};

int main() {
    return 0;
}