//
// Created by pzz on 2021/10/25.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        removeExtreSpace(s);
        reverse(s.begin(), s.end());

        int left = 0, right = 0;
        for (; right < s.size(); right++) {
            if (s[right] == ' ') {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
        }
        reverse(s.begin() + left, s.end());

        return s;
    }

    void removeExtreSpace(string &s) {
        int slow = 0, fast = 0;
        while (fast < s.size() && s[fast] == ' ')
            fast++;
        for (; fast < s.size(); fast++) {
            if (s[fast] == ' ' && s[fast] == s[fast - 1] && fast - 1 > 0)
                continue;
            else
                s[slow++] = s[fast];
        }
        if (s[slow - 1] == ' ' && slow - 1 > 0)
            s.resize(slow - 1);
        else
            s.resize(slow);
    }
};

int main() {
    Solution solution;

    string s = "the sky is blue";

    cout << solution.reverseWords(s);
    return 0;
}