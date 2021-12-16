//
// Created by pzz on 2021/12/16.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int cover = 0;
        if (nums.size() == 1)
            return true;

        for (int i = 0; i <= cover; i++) {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1)
                return true;
        }

        return false;
    }
};

int main() {
    return 0;
}