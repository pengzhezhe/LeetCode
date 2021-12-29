//
// Created by pzz on 2021/12/29.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                result++;
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }

        return result;
    }
};

int main() {
    return 0;
}