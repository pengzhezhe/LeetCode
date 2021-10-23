//
// Created by pzz on 2021/9/16.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        int start = -1, end = -1;

        if (nums.empty())
            return vector<int>{-1, -1};

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] >= target) {
                right = mid - 1;
                start = mid;
            } else
                left = mid + 1;
        }

        if (start == -1)
            return vector<int>{-1, -1};

        if (nums[start] != target)
            return vector<int>{-1, -1};

        left = start;
        right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] <= target) {
                left = mid + 1;
                end = mid;
            } else
                right = mid - 1;
        }

        return vector<int>{start, end};
    }
};

int main() {
    vector<int> nums{2, 2};
    int target = 3;
    Solution s;
    vector<int> ans = s.searchRange(nums, target);
    for (int an: ans)
        cout << an << endl;
    return 0;
}