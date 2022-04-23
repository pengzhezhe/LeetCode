//
// Created by pzz on 2022/4/20.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int ans = 0;
        int pos = 0;
        vector<int> level(n + 1, 0);

        while (pos < n) {
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                depth++;
                pos++;
            }

            int len = 0;
            bool isFile = false;
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.')
                    isFile = true;
                len++;
                pos++;
            }

            pos++;

            if (depth > 1) {
                len += level[depth - 1] + 1;
            }
            if (isFile) {
                ans = max(ans, len);
            } else {
                level[depth] = len;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}