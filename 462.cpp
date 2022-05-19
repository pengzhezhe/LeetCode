//
// Created by pzz on 2022/5/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), middle = nums[n / 2];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(nums[i] - middle);
        }
        return ans;
    }
};

int main() {
    return 0;
}