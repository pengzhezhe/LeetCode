//
// Created by pzz on 2022/3/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ans(nums1.size(), -1);
        stack<int> stack;
        unordered_map<int, int> map;

        for (int i = 0; i < nums1.size(); i++)
            map[nums1[i]] = i;

        for (int i = 0; i < nums2.size(); i++) {
            while (!stack.empty() && nums2[i] > nums2[stack.top()]) {
                if (map.count(nums2[stack.top()]) > 0) {
                    int index = map[nums2[stack.top()]];
                    ans[index] = nums2[i];
                }
                stack.pop();
            }
            stack.push(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}