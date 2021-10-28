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
    bool isValid(string s) {
        stack<char> stack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push(')');
            } else if (s[i] == '[') {
                stack.push(']');
            } else if (s[i] == '{') {
                stack.push('}');
            } else if (stack.empty() || stack.top() != s[i]) {
                return false;
            } else
                stack.pop();

        }
        return stack.empty();
    }
};

int main() {

}