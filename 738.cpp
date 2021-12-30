//
// Created by pzz on 2021/12/30.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int flag = s.size();
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] < s[i - 1]) {
                flag = i;
                s[i - 1]--;
            }
        }

        for (int i = flag; i < s.size(); i++) {
            s[i] = '9';
        }

        return stoi(s);
    }
};

int main() {
    Solution solution;
    cout << solution.monotoneIncreasingDigits(658);
    return 0;
}