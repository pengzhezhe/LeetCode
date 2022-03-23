//
// Created by pzz on 2022/3/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> stack;

        for (int i = 0; i < 2 * nums.size(); i++) {
            while (!stack.empty() && nums[i % nums.size()] > nums[stack.top()]) {
                ans[stack.top()] = nums[i % nums.size()];
                stack.pop();
            }
            stack.push(i % nums.size());
        }
        return ans;
    }
};

int main() {
    return 0;
}