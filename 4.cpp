//
// Created by pzz on 2022/4/23.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int left = 0, right = 0, n = 0;
        vector<int> nums(n1 + n2);

        while (left < n1 && right < n2) {
            if (left < n1 && nums1[left] < nums2[right]) {
                nums[n] = nums1[left];
                n++;
                left++;
            } else {
                nums[n] = nums2[right];
                n++;
                right++;
            }
        }
        if (left == n1) {
            while (right < n2) {
                nums[n] = nums2[right];
                n++;
                right++;
            }
        } else if (right == n2) {
            while (left < n1) {
                nums[n] = nums1[left];
                n++;
                left++;
            }
        }

        if (nums.size() % 2 == 1) {
            return nums[nums.size() / 2];
        } else {
            return (double) (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
        }
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}