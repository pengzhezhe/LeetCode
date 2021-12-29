//
// Created by pzz on 2021/12/29.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int lastPos[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            lastPos[s[i] - 'a'] = i;
        }

        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, lastPos[s[i] - 'a']);

            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }

        return result;
    }
};

int main() {
    return 0;
}