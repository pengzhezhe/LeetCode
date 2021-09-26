//
// Created by pzz on 2021/9/25.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, t1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#')
                s1.push_back(s[i]);
            else if (!s1.empty())
                s1.pop_back();
        }

        for (int i = 0; i < t.size(); i++) {
            if (t[i] != '#')
                t1.push_back(t[i]);
            else if (!t1.empty())
                t1.pop_back();
        }
        return s1 == t1;
    }
};

int main() {
    string s = "a#c";
    string t = "b";
    Solution solution;
    cout << solution.backspaceCompare(s, t);
}