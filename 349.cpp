//
// Created by pzz on 2021/10/20.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> ans;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num: nums2) {
            if (nums_set.find(num) != nums_set.end())
                ans.insert(num);
        }

        return vector<int>(ans.begin(), ans.end());
    }
};

int main() {
    return 0;
}