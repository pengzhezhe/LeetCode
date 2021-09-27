//
// Created by pzz on 2021/9/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num / 2;

        if (num == 1)
            return true;

        while (left <= right) {
            int mid = (left + right) / 2;

            int quotient = num / mid;
            int remainder = num % mid;

            if (quotient == mid) {
                if (remainder == 0)
                    return true;
                left = mid + 1;
            } else if (quotient < mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};

int main() {
    int num = 9;
    Solution solution;
    cout << solution.isPerfectSquare(num);
    return 0;
}