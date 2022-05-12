//
// Created by pzz on 2022/5/12.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string> &strs) {
        int row = strs.size();
        int col = strs[0].size();
        int ans = 0;

        for (int j = 0; j < col; j++) {
            for (int i = 1; i < row; i++) {
                if (strs[i - 1][j] > strs[i][j]) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}