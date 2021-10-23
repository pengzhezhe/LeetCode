//
// Created by pzz on 2021/10/23.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                for (int k = j + 1, l = nums.size() - 1; k < nums.size(); k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                        continue;

                    int c = target - nums[i] - nums[j] - nums[k];

                    while (nums[l] > c && l > k)
                        l--;

                    if (k == l)
                        break;

                    if (c == nums[l])
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution solution;
    vector<vector<int>> ans = solution.fourSum(nums, target);
    for (vector<int> v: ans) {
        cout << "[";
        for (int n: v) {
            cout << " " << n << " ";
        }
        cout << "]";
    }
    return 0;
}