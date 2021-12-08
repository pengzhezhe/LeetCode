//
// Created by pzz on 2021/12/8.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

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

        for (int i = 0; i < nums.size(); i++) {
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
    vector<vector<int>> permute(vector<int> &nums) {
        used.insert(used.begin(), nums.size(), false);
        backtracing(nums);
        return result;
    }
};

int main() {
    vector<int> nums = {1};
    Solution solution;
    vector<vector<int>> result = solution.permute(nums);
    for (auto v: result) {
        for (auto i: v) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}