//
// Created by pzz on 2022/4/27.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> pacific, atlantic, ans;
    int n, m;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        n = heights.size(), m = heights[0].size();
        pacific = atlantic = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, n - 1, j);
        }
        return ans;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<int>> &visited, int i, int j) {
        if (visited[i][j]) return;

        visited[i][j] = 1;

        if (pacific[i][j] && atlantic[i][j])
            ans.push_back({i, j});

        if (i + 1 < n && heights[i + 1][j] >= heights[i][j]) dfs(heights, visited, i + 1, j);
        if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j]) dfs(heights, visited, i - 1, j);
        if (j + 1 < m && heights[i][j + 1] >= heights[i][j]) dfs(heights, visited, i, j + 1);
        if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j]) dfs(heights, visited, i, j - 1);
    }
};

int main() {
    return 0;
}