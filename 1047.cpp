//
// Created by pzz on 2021/10/28.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for (char c: s) {
            if (stack.empty() || c != stack.top())
                stack.push(c);
            else {
                stack.pop();
            }
        }
        string ans;
        while (!stack.empty()) {
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string s = "abbaca";
    Solution solution;
    cout << solution.removeDuplicates(s);
    return 0;
}