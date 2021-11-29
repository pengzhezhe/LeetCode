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
    vector<int> path;

    void backtracing(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracing(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracing(n, k, 1);
        return result;
    }
};

int main() {
    return 0;
}