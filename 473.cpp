//
// Created by pzz on 2022/6/1.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int> &matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0)
            return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        vector<int> edges(4);

        return backtrace(matchsticks, edges, totalLen / 4, 0);
    }

    bool backtrace(vector<int> &matchsticks, vector<int> &edges, int len, int index) {
        if (index == matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && backtrace(matchsticks, edges, len, index + 1))
                return true;
            edges[i] -= matchsticks[index];
        }
        return false;
    }
};

int main() {
    return 0;
}