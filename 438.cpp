//
// Created by pzz on 2021/10/20.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> record(26, 0), dictionary(26, 0);

        if (s.size() < p.size())
            return ans;

        for (char c: p)
            dictionary[c - 'a']++;

        for (int i = 0; i < p.size(); i++)
            record[s[i] - 'a']++;

        for (int i = 0; i + p.size() - 1 < s.size(); i++) {
            if (i != 0) {
                record[s[i - 1] - 'a']--;
                record[s[i + p.size() - 1] - 'a']++;
            }
            if (record == dictionary)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}