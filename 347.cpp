//
// Created by pzz on 2021/10/30.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>> priorityQueue;
        vector<int> ans;
        for (int n: nums) {
            map[n]++;
        }

        auto iterator = map.begin();
        while (iterator != map.end()) {
            priorityQueue.emplace(iterator->second, iterator->first);
            iterator++;
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(priorityQueue.top().second);
            priorityQueue.pop();
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution solution;
    vector<int> ans = solution.topKFrequent(nums, k);

    for (int n: ans) {
        cout << n << endl;
    }
    return 0;
}