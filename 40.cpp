//
// Created by pzz on 2021/12/2.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> collection;
    vector<bool> used;
    int sum;

    void backtracing(vector<int> &candidates, int target, int start) {
        if (sum == target) {
            result.push_back(collection);
            return;
        }

        for (int i = start; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
                continue;

            collection.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracing(candidates, target, i + 1);
            used[i] = false;
            sum -= candidates[i];
            collection.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        used.insert(used.begin(), candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracing(candidates, target, 0);
        return result;
    }
};

int main() {
    return 0;
}