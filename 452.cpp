//
// Created by pzz on 2021/12/29.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

public:
    int findMinArrowShots(vector<vector<int>> &points) {
        vector<vector<vector<int>>> set;
        sort(points.begin(), points.end(), cmp);

        int result = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1])
                result++;
            else
                points[i][1] = min(points[i - 1][1], points[i][1]);
        }

        return result;
    }
};

int main() {
    return 0;
}
