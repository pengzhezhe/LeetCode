//
// Created by pzz on 2021/10/30.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (const string &s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                if (s == "+") {
                    stack.push(num2 + num1);
                }
                if (s == "-") {
                    stack.push(num2 - num1);
                }
                if (s == "*") {
                    stack.push(num2 * num1);
                }
                if (s == "/") {
                    stack.push(num2 / num1);
                }
            } else {
                stack.push(stoi(s));
            }
        }
        return stack.top();
    }
};

int main() {
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    Solution solution;
    cout << solution.evalRPN(tokens);
    return 0;
}