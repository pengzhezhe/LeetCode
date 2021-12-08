//
// Created by pzz on 2021/12/8.
//

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;
    void backtracing(vector<int> &nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            if ((i > 0 && nums[i] == nums[i - 1]) && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                path.push_back(nums[i]);
                used[i] = true;
                backtracing(nums);
                used[i] = false;
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        used.insert(used.begin(), nums.size(), false);
        backtracing(nums);
        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution solution;
    vector<vector<int>> result = solution.permuteUnique(nums);
    for (auto v: result) {
        for (auto i: v) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}