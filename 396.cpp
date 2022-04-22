//
// Created by pzz on 2022/4/22.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> &nums) {
        int n = nums.size();
        int numSum = 0, f = 0;

        for (int i = 0; i < n; i++) {
            numSum += nums[i];
            f += i * nums[i];
        }
        int res = f;
        for (int i = 1; i < n; i++) {
            f += numSum - n * nums[n - i];
            res = max(res, f);
        }

        return res;
    }
};

int main() {
    return 0;
}