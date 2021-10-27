//
// Created by pzz on 2021/10/27.
//

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;
    int size;

public:
    MyQueue() {
    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        int ans = outputStack.top();
        outputStack.pop();
        return ans;
    }

    int peek() {
        int ans = this->pop();
        outputStack.push(ans);
        return ans;
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    return 0;
}