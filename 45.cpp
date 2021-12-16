//
// Created by pzz on 2021/12/16.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int result = 0, cover = nums[0], maxcover = nums[0];

        if (nums.size() == 1)
            return 0;

        for (int i = 0; i <= cover; i++) {
            if (cover >= nums.size() - 1)
                break;
            if (i + nums[i] > maxcover) {
                maxcover = i + nums[i];
            }
            if (i == cover) {
                cover = maxcover;
                result++;
            }

        }
        return ++result;
    }
};

int main() {
    return 0;
}