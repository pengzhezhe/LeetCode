//
// Created by pzz on 2022/4/26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int n = grid.size();
        int xyArea = 0, yzArea = 0, xzArea = 0;

        for (int i = 0; i < n; i++) {
            int yzHeight = 0, xzHeight = 0;
            for (int j = 0; j < n; j++) {
                xyArea += grid[i][j] > 0 ? 1 : 0;
                yzHeight = max(yzHeight, grid[j][i]);
                xzHeight = max(xzHeight, grid[i][j]);
            }
            yzArea += yzHeight;
            xzArea += xzHeight;
        }
        return xyArea + xzArea + yzArea;
    }
};

int main() {
    return 0;
}