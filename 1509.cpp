#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minDifference(vector<int> &nums) {
        int n = nums.size();
        if (n <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        for (int i = 0; i <= 3; i++) {
            int diff = nums[n - 1 - i] - nums[3 - i];
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }
};