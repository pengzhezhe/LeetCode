//
// Created by pzz on 2022/5/3.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(string &log1, string &log2) {
        int index1 = log1.find(' ');
        int index2 = log2.find(' ');

        if (log1.substr(index1 + 1) != log2.substr(index2 + 1)) {
            return log1.substr(index1 + 1) < log2.substr(index2 + 1);
        }

        return log1 < log2;
    }

public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        vector<string> ans, nums;
        for (string log: logs) {
            int index = log.find(' ');
            if (isdigit(log[index + 1]))
                nums.push_back(log);
            else
                ans.push_back(log);
        }
        sort(ans.begin(), ans.end(), cmp);
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};

int main() {
    return 0;
}