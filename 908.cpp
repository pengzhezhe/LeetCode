//
// Created by pzz on 2022/4/30.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = nums[n - 1];
        return max - min <= 2 * k ? 0 : max - min - 2 * k;
    }
};

int main() {
    return 0;
}