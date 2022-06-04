//
// Created by pzz on 2022/6/4.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> uset;
        for (string &email: emails) {
            string localName;
            for (char &c: email) {
                if (c == '+' || c == '@') {
                    break;
                }
                if (c != '.') {
                    localName.push_back(c);
                }
            }
            string domain = email.substr(email.find('@'));
            uset.emplace(localName + '@' + domain);
        }
        return uset.size();
    }
};

int main() {
    return 0;
}