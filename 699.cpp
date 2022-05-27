//
// Created by pzz on 2022/5/26.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        int n = positions.size();
        vector<int> ans(n);
        map<int, int> heightMap;
        heightMap[0] = 0;
        for (int i = 0; i < n; i++) {
            int left = positions[i][0], right = positions[i][0] + positions[i][1] - 1;
            auto lp = heightMap.upper_bound(left), rp = heightMap.upper_bound(right);
            int rHeight = prev(rp)->second;

            int height = 0;
            for (auto it = prev(lp); it != rp; it++) {
                height = max(height, it->second + positions[i][1]);
            }

            heightMap.erase(lp, rp);

            heightMap[left] = height;
            if (rp == heightMap.end() || rp->first != right + 1) {
                heightMap[right + 1] = rHeight;
            }
            ans[i] = i > 0 ? max(ans[i - 1], height) : height;
        }
        return ans;
    }
};

int main() {
    Solution solution = Solution();
    vector<vector<int>> positions = {{100, 100},
                                     {200, 100}
    };
    vector<int> ans = solution.fallingSquares(positions);

    for (auto i: ans)
        cout << i << endl;
    return 0;
}