//
// Created by pzz on 2022/5/6.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> queue;
public:
    RecentCounter() {}

    int ping(int t) {
        queue.push(t);
        while (queue.front() < t - 3000)
            queue.pop();

        return queue.size();
    }
};

int main() {
    return 0;
}