//
// Created by pzz on 2021/9/16.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> searchRange(vector<int> &nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        int start = -1, end = -1;
//
//        while (left <= right) {
//            int mid = (left + right) / 2;
//            if (nums[mid] == target) {
//                if (nums[mid - 1] == target && nums[mid + 1] == target)
//                    right = mid + 1;
//                if (nums[mid - 1] != target) {
//                    start = mid;
//                    left = mid + 1;
//                }
//                if (nums[mid + 1] != target) {
//                    end = mid;
//                    right = mid - 1;
//                }
//            } else if (nums[mid] < target)
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//        return vector<int>{start, end};
//    }
//};

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        int start = -1, end = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;

        }
        return vector<int>{start, end};
    }
};

int main() {
    vector<int> nums{1};
    int target = 1;
    Solution s;
    vector<int> ans = s.searchRange(nums, target);
    for (int an: ans)
        cout << an << endl;
    return 0;
}