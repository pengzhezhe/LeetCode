//
// Created by pzz on 2022/6/12.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> ans;

        for (string &word: words) {
            if (match(word, pattern))
                ans.push_back(word);
        }

        return ans;
    }

    bool match(string &word, string &pattern) {
        vector<int> map(26, -1), visited(26, 0);
        for (int i = 0; i < pattern.size(); i++) {
            if (map[word[i] - 'a'] == -1 && visited[pattern[i] - 'a'] == 0) {
                map[word[i] - 'a'] = pattern[i] - 'a';
                visited[pattern[i] - 'a'] = 1;
            } else if (map[word[i] - 'a'] != pattern[i] - 'a')
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}