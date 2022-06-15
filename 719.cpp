//
// Created by pzz on 2022/6/15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n - 1] - nums[0];
        while (left <= right) {
            int middle = (left + right) >> 1;
            int cnt = 0;
            for (int i = 0, j = 0; j < n; j++) {
                while (i < n && nums[j] - nums[i] > middle)
                    i++;
                cnt += j - i;
            }
            if (cnt >= k)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return left;
    }
};

int main() {
    return 0;
}