//
// Created by pzz on 2021/10/26.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }

        int next[needle.size()];
        genarateNext(next, needle);

        for (int i = 0, j = 0; i < haystack.size(); i++) {
            while (haystack[i] != needle[j] && j > 0) {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j]) {
                j++;
            }

            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }

        return -1;
    }

    void genarateNext(int *next, string s) {
        int prefix = 0;
        next[0] = 0;
        for (int suffix = 1; suffix < s.size(); suffix++) {
            while (prefix > 0 && s[prefix] != s[suffix]) {
                prefix = next[prefix - 1];
            }
            if (s[prefix] == s[suffix]) {
                prefix++;
            }
            next[suffix] = prefix;
        }
    }
};

int main() {
    Solution solution;
    string haystack = "", needle = "1";
    cout << solution.strStr(haystack, needle);
    return 0;
}