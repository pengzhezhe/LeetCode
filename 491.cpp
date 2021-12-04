//
// Created by pzz on 2021/12/4.
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

    void backtracing(vector<int> &nums, int start) {
        if (path.size() >= 2)
            result.push_back(path);

        unordered_set<int> set;
        for (int i = start; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back() || set.find(nums[i]) != set.end()) {
                continue;
            }
            set.insert(nums[i]);
            path.push_back(nums[i]);
            backtracing(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        backtracing(nums, 0);
        return result;
    }
};

int main() {
    vector<int> nums{4, 6, 7, 7};
    Solution solution;
    return 0;
}
