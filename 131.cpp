//
// Created by pzz on 2021/12/2.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> collection;

    void backtracing(string &s, int start) {
        if (start == s.size()) {
            result.push_back(collection);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i))
                collection.push_back(s.substr(start, i - start + 1));
            else
                continue;

            backtracing(s, i + 1);
            collection.pop_back();
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        backtracing(s, 0);
        return result;
    }
};

int main() {
    return 0;
}