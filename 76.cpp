//
// Created by pzz on 2021/9/27.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> dictionary, origin;

    bool contentAll() {
        for (auto &kv: origin) {
            if (dictionary[kv.first] < kv.second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (char &c: t) {
            origin[c]++;
        }

        int slow = 0, fast = 0;
        int left = -1, len = INT_MAX;

        while (fast < s.size()) {
            if (origin.find(s[fast]) != origin.end()) {
                dictionary[s[fast]]++;
            }
            while (contentAll() && slow <= fast) {
                if (fast - slow + 1 < len) {
                    len = fast - slow + 1;
                    left = slow;
                }
                if (origin.find(s[slow]) != origin.end())
                    dictionary[s[slow]]--;
                slow++;
            }
            fast++;
        }

        return left == -1 ? string() : s.substr(left, len);
    }
};

int main() {
    Solution solution;

    string s = "a", t = "aa";
    cout << solution.minWindow(s, t);
    return 0;
}