//
// Created by pzz on 2021/12/12.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (index < g.size() && g[index] <= s[i]) {
                index++;
            }
        }
        return index;
    }
};

int main() {
    vector<int> g = {10, 9, 8, 7};
    vector<int> s = {5, 6, 7, 8};
    Solution solution;
    cout << solution.findContentChildren(g, s);
}