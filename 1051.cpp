//
// Created by pzz on 2022/6/13.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int> &heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());

        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (expected[i] != heights[i])
                ans++;
        }

        return ans;
    }
};

int main() {
    return 0;
}