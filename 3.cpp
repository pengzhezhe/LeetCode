#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        unordered_set<char> set;

        int max_length = 0, j = 0;

        for (int i = 0; i < s.size(); i++) {
            while (set.count(s[j]) == 0 && j < s.size()) {
                set.insert(s[j]);
                j++;
            }

            max_length = max(max_length, j - i);

            set.erase(s[i]);
        }
        return max_length;
    }
};