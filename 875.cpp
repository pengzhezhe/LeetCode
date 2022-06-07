//
// Created by pzz on 2022/6/7.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int maxSpeed = 1;
        for (int pile: piles)
            maxSpeed = max(maxSpeed, pile);

        int left = 1, right = maxSpeed;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(piles, h, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }

    bool check(vector<int> &piles, int h, int k) {
        int res = 0;
        for (int pile: piles)
            res += ceil(pile * 1.0 / k);
        return res <= h;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << solution.minEatingSpeed(piles, h);
    return 0;
}