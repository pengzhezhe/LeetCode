//
// Created by pzz on 2021/9/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int left = 1, right = x / 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x / mid == mid)
                return mid;
            else if (x / mid > mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
};

int main() {
    int x = 2147483647;
    Solution solution;
    cout << solution.mySqrt(x);
}