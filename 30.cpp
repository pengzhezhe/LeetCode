//
// Created by pzz on 2022/6/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ans;
        int m = words.size(), n = words[0].size(), len = s.size();
        unordered_map<string, int> umap;

        for (auto word: words) {
            umap[word]++;
        }

        for (int i = 0; i + m * n <= len; i++) {
            unordered_map<string, int> count;
            for (int j = 0; j < m; j++) {
                string sub = s.substr(i + j * n, n);
                if (!umap.count(sub))
                    break;
                count[sub]++;
            }
            if (count == umap)
                ans.emplace_back(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}