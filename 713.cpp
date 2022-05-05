//
// Created by pzz on 2022/5/5.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0;
        int left = 0, right = 0;
        int product = 1;
        while (right < n) {
            product *= nums[right];
            right++;
            while (left < right && product >= k) {
                product /= nums[left];
                left++;
            }

            ans += right - left;
        }
        return ans;
    }
};

int main() {
    return 0;
}