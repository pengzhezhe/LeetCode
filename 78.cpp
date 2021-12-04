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
    vector<int> childSet;

    void backtracing(vector<int> &nums, int start) {
        result.push_back(childSet);

        for (int i = start; i < nums.size(); i++) {
            childSet.push_back(nums[i]);
            backtracing(nums, i + 1);
            childSet.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        backtracing(nums, 0);
        return result;
    }
};

int main() {
    return 0;
}