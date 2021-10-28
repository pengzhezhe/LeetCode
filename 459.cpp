//
// Created by pzz on 2021/10/26.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//TODO REMEMBER
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();

        if (len == 0) {
            return false;
        }

        int next[len];
        generateNext(next, s);

        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) {
            return true;
        }
        return false;
    }

    void generateNext(int *next, string s) {
        int prefix = 0;
        next[0] = 0;

        for (int suffix = 1; suffix < s.size(); suffix++) {
            while (s[prefix] != s[suffix] && prefix > 0) {
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

    return 0;
}