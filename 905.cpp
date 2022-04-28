//
// Created by pzz on 2022/4/28.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int n = nums.size();
        for (int left = 0, right = n - 1; left < right; left++) {
            if (nums[left] % 2 == 1) {
                int temp = nums[right];
                nums[right--] = nums[left];
                nums[left--] = temp;
            }
        }
        return nums;
    }
};

int main() {
    return 0;
}