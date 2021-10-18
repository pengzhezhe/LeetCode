//
// Created by pzz on 2021/10/18.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> record;

        for (string str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            record[key].push_back(str);
        }

        for (auto p: record) {
            result.push_back(p.second);
        }
        return result;
    }
};

int main() {

    return 0;
}