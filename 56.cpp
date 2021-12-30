//
// Created by pzz on 2021/12/30.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[i - 1][1]) {
                intervals[i][0] = intervals[i - 1][0];
                intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
            } else {
                result.push_back(intervals[i - 1]);
            }
        }
        result.push_back(intervals[intervals.size() - 1]);
        return result;
    }
};

int main() {
    return 0;
}