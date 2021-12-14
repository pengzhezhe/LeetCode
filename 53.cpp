//
// Created by pzz on 2021/12/14.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result)
                result = count;
            if (count < 0) {
                count = 0;
                continue;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}