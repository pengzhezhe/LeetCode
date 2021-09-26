//
// Created by pzz on 2021/9/26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> sortedSquares(vector<int> &nums) {
//        for (int i = 0; i < nums.size(); ++i) {
//            nums[i] *= nums[i];
//        }
//        sort(nums.begin(), nums.end());
//
//        return nums;
//    }
//};

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size() - 1;
        vector<int> ans(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] * nums[left] >= nums[right] * nums[right]) {
                ans[n--] = nums[left] * nums[left];
                left++;
            } else {
                ans[n--] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{-4, -1, 0, 3, 10};

    Solution solution;
    vector<int> n = solution.sortedSquares(nums);

    for (int i = 0; i < n.size(); ++i) {
        cout << n[i] << endl;
    }
}