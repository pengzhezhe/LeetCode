//
// Created by pzz on 2021/12/14.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1)
            return nums.size();

        int result = 1;
        int preDiff = 0, curDiff = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}