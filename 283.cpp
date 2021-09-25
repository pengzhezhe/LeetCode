//
// Created by pzz on 2021/9/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0)
                nums[slow++] = nums[fast];
        }
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    vector<int> nums{0, 1, 0, 3, 12};
    Solution solution;
    solution.moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }
}
