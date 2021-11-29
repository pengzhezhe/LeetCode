//
// Created by pzz on 2021/11/29.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, string> dictionary = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
    };

    vector<string> result;
    string s;

    void backtracing(const string &digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }

        int digit = digits[index] - '0';

        for (int i = 0; i < dictionary[digit].size(); i++) {
            s.push_back(dictionary[digit][i]);
            backtracing(digits, index + 1);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        backtracing(digits, 0);
        return result;
    }
};

int main() {
    return 0;
}