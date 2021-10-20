//
// Created by pzz on 2021/10/20.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (char c: ransomNote)
            record[c - 'a']++;

        for (char c: magazine)
            record[c - 'a']--;

        for (int i: record) {
            if (i > 0)
                return false;
        }
        return true;
    }
};

int main() {
    string ransomNote = "a";
    string magazine = "ab";

    Solution solution;
    cout << solution.canConstruct(ransomNote, magazine);
    return 0;
}