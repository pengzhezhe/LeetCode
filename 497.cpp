//
// Created by pzz on 2022/6/9.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

class Solution {
private:
    vector<vector<int>> rects;
    vector<int> sum;

    int area(vector<int> rect) {
        return (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
    }

public:
    Solution(vector<vector<int>> &rects) : rects(rects) {
        int areaSum = 0;
        sum = vector<int>(rects.size());
        for (int i = 0; i < rects.size(); i++) {
            areaSum += area(rects[i]);
            sum[i] = areaSum;
        }
    }

    vector<int> pick() {
        int val = rand() % sum.back();
        int left = 0, right = sum.size() - 1;
        while (left <= right) {
            int middle = (left + right) >> 1;
            if (sum[middle] > val)
                right = middle - 1;
            else
                left = middle + 1;
        }
        vector<int> curRect = rects[right + 1];
        int x = curRect[0] + rand() % (curRect[2] - curRect[0] + 1);
        int y = curRect[1] + rand() % (curRect[3] - curRect[1] + 1);
        return {x, y};
    }
};

int main() {
    vector<vector<int>> recks = {{-2, -2, 1, 1},
                                 {2,  2,  4, 6}};
    Solution solution = Solution(recks);
    solution.pick(); // 返回 [1, -2]
    solution.pick(); // 返回 [1, -1]
    solution.pick(); // 返回 [-1, -2]
    solution.pick(); // 返回 [-2, -2]
    solution.pick(); // 返回 [0, 0]
    return 0;
}