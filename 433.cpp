//
// Created by pzz on 2022/5/7.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int ans;
    int count;
    unordered_set<string> uset;

    void backtrace(vector<string> &bank, string start, string end) {
        if (start == end) {
            ans = min(ans, count);
        }

        for (int i = 0; i < bank.size(); i++) {
            if (isValid(start, bank[i]) && !uset.count(bank[i])) {
                uset.insert(bank[i]);
                count++;
                backtrace(bank, bank[i], end);
                count--;
                uset.erase(bank[i]);
            }
        }
    }

    bool isValid(string start, string end) {
        int num = 0;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] != end[i])
                num++;
        }
        return num == 1;
    }

public:
    int minMutation(string start, string end, vector<string> &bank) {
        ans = INT_MAX;
        backtrace(bank, start, end);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    return 0;
}