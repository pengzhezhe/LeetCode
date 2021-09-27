//
// Created by pzz on 2021/9/26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {

        int ans = INT_MAX, length = 0;
        int i = 0, sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                length = j - i + 1;
                ans = length < ans ? length : ans;
                sum -= nums[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    vector<int> n{2, 3, 1, 2, 4, 3};
    int target = 7;

    Solution solution;
    cout << solution.minSubArrayLen(target, n);
}