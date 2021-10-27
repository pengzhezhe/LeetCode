//
// Created by pzz on 2021/10/27.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    MyStack() {

    }

    void push(int x) {
        queue1.push(x);
    }

    int pop() {
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int ans = queue1.front();
        queue1.pop();
        swap(queue1, queue2);
        return ans;
    }

    int top() {
        return queue1.back();
    }

    bool empty() {
        return queue1.empty();
    }
};


int main() {
    return 0;
}