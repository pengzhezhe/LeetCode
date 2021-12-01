//
// Created by pzz on 2021/11/29.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> collection;
    int sum = 0;

    void backtracing(const vector<int> &candidates, int target, int start) {
        if (sum == target) {
            result.push_back(collection);
            return;
        }

        for (int i = start; i < candidates.size() && sum < target; i++) {
            sum += candidates[i];
            collection.push_back(candidates[i]);
            backtracing(candidates, target, i);
            collection.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracing(candidates, target, 0);
        return result;
    }
};

int main() {
    return 0;
}