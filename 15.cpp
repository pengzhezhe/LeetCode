//
// Created by pzz on 2021/10/22.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1, k = nums.size() - 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int c = 0 - nums[i] - nums[j];

                while (c < nums[k] && j < k) {
                    k--;
                }

                if (j == k)
                    break;

                if (c == nums[k])
                    ans.push_back({nums[i], nums[j], c});
            }

        }
        return ans;
    }
};

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    Solution solution;
    vector<vector<int>> ans = solution.threeSum(nums);
    for (vector<int> v: ans) {
        cout << "[";
        for (int n: v) {
            cout << " " << n << " ";
        }
        cout << "]";
    }
    return 0;
}