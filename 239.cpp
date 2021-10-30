//
// Created by pzz on 2021/10/30.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;
        deque<int> deque;

        for (int i = 0; i < k; i++) {
            while (!deque.empty() && nums[i] > deque.back()) {
                deque.pop_back();
            }
            deque.push_back(nums[i]);
        }

        ans.push_back(deque.front());

        for (int i = k; i < nums.size(); i++) {
            //Remove the left bound
            if (!deque.empty() && deque.front() == nums[i - k])
                deque.pop_front();

            while (!deque.empty() && nums[i] > deque.back()) {
                deque.pop_back();
            }
            deque.push_back(nums[i]);

            ans.push_back(deque.front());
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution solution;
    vector<int> ans = solution.maxSlidingWindow(nums, k);
    for (int n: ans) {
        cout << n << endl;
    }
    return 0;
}