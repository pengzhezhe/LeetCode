//
// Created by pzz on 2022/5/23.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    int directions[4][2] = {{-1, 0},
                            {1,  0},
                            {0,  -1},
                            {0,  1}};
    int ans = INT_MIN;
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                backtrace(grid, 0, i, j);
            }
        }
        return ans;
    }

    void backtrace(vector<vector<int>> &grid, int curGold, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            ans = max(ans, curGold);
            return;
        } else if (grid[row][col] == 0) {
            ans = max(ans, curGold);
            return;
        }

        int gold = grid[row][col];
        grid[row][col] = 0;
        for (int i = 0; i < 4; i++) {
            curGold += gold;
            backtrace(grid, curGold, row + directions[i][0], col + directions[i][1]);
            curGold -= gold;
        }
        grid[row][col] = gold;
    }
};

int main() {
    return 0;
}