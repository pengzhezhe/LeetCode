//
// Created by pzz on 2021/10/21.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int count = 0;
        unordered_map<int, int> record;
        for (int i: nums1) {
            for (int j: nums2)
                record[i + j]++;
        }

        for (int i: nums3) {
            for (int j: nums4) {
                if (record.find(0 - (i + j)) != record.end())
                    count += record[0 - (i + j)];
            }
        }

        return count;
    }
};

int main() {
    return 0;
}