//
// Created by pzz on 2022/5/8.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        vector<int> ans;

        for (int num: nums) {
            count[num]++;
        }

        for (int i = 1; i <= n; i++) {
            if (count[i] == 2)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}