//
// Created by pzz on 2021/10/20.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int num: nums1) {
            map[num]++;
        }
        for (int num: nums2) {
            if (map[num]-- > 0)
                ans.push_back(num);
        }

        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution solution;
    vector<int> ans = solution.intersect(nums1, nums2);
    for (int n: ans)
        cout << n << endl;
    return 0;
}