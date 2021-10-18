//
// Created by pzz on 2021/10/18.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int dictionary[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            dictionary[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i) {
            dictionary[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (dictionary[i] != 0)
                return false;
        }
        return true;
    }
};

int main() {
    string s = "rat", t = "cat";
    Solution solution;
    cout << solution.isAnagram(s, t);

    return 0;
}