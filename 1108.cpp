//
// Created by pzz on 2022/6/21.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (char ch: address) {
            if (isdigit(ch))
                ans.push_back(ch);
            else
                ans.append("[.]");
        }
        return ans;
    }
};