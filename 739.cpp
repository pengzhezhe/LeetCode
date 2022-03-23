//
// Created by pzz on 2022/3/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            for (int j = i + 1; j < temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> stack;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                ans[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}