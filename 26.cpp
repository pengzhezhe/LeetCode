//
// Created by pzz on 2021/9/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {

        if (nums.empty())
            return 0;

        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[slow] != nums[fast])
                nums[++slow] = nums[fast];
        }
        return slow + 1;
    }
};

int main() {
    vector<int> nums{};
    Solution s;
    int n = s.removeDuplicates(nums);
    cout << n << endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }
    return 0;
}