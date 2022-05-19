//
// Created by pzz on 2022/5/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }

public:
    double largestTriangleArea(vector<vector<int>> &points) {
        int n = points.size();
        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ans = max(ans, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0],
                                                points[k][1]));
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}