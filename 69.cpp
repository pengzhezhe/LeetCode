//
// Created by pzz on 2021/9/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int left = 1, right = x / 2;
        while (left <= right) {
            int mid = (left + right) / 2;

            int quotient = x / mid;
            int remainder = x % mid;

            if (quotient == mid) {
                if (remainder == 0)
                    return mid;
                left = mid + 1;
            } else if (x / mid > mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
};

int main() {
    int x = 5;
    Solution solution;
    cout << solution.mySqrt(x);
}