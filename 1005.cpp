//
// Created by pzz on 2021/12/16.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (k > 0 && nums[i] < 0) {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1) {
            nums[nums.size() - 1] *= -1;
        }
        int sum = 0;
        for (int i: nums)
            sum += i;
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-4, -2, -3};
    int res = solution.largestSumAfterKNegations(nums, 4);
    cout << res;
    return 0;
}