//
// Created by pzz on 2021/12/4.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;

    void backtracing(vector<int> &nums, int start) {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false)
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracing(nums, i + 1);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        used.insert(used.begin(), nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracing(nums, 0);
        return result;
    }
};

int main() {
    return 0;
}