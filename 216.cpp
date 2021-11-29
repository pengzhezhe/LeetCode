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
    int sum;

    void backtracing(int k, int n, int start) {
        if (collection.size() == k) {
            if (sum == n) {
                result.push_back(collection);
            }
            return;
        }

        for (int i = start; i <= 9 - (k - collection.size()) + 1; i++) {
            collection.push_back(i);
            sum += i;
            backtracing(k, n, i + 1);
            sum -= i;
            collection.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracing(k, n, 1);
        return result;
    }
};

int main() {
    return 0;
}