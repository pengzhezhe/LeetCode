//
// Created by pzz on 2021/12/2.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> result;
    vector<string> address;

    void backtracing(const string &s, int start) {
        if (start == s.size() && address.size() == 4) {
            string addressStr = address[0] + '.' + address[1] + '.' + address[2] + '.' + address[3];
            result.push_back(addressStr);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isValid(s.substr(start, i - start + 1))) {
                address.push_back(s.substr(start, i - start + 1));
            } else
                continue;
            backtracing(s, i + 1);
            address.pop_back();
        }
    }

    bool isValid(string digital) {
        if (digital.size() > 3 || digital.size() == 0)
            return false;

        if (digital.size() > 1 && digital[0] == '0')
            return false;

        if (stoi(digital) > 255)
            return false;
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        backtracing(s, 0);
        return result;
    }
};

int main() {
    string s = "101023";
    Solution solution;

    vector<string> result = solution.restoreIpAddresses(s);

    for (auto s: result)
        cout << s << endl;
    return 0;
}