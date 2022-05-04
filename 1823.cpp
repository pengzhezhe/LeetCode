//
// Created by pzz on 2022/5/4.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> friends(n + 1, false);
        int count = 0, cur = 0;
        while (count != n - 1) {
            for (int i = 1; i < k; i++) {
                cur++;
                while (friends[cur % n]) cur++;
            }

            friends[cur % n] = true;
            count++;

            cur++;
            while (friends[cur % n]) cur++;
        }
        return (cur % n) + 1;
    }
};

class Solution2 {
public:
    int findTheWinner(int n, int k) {
        queue<int> queue;
        for (int i = 1; i <= n; i++) {
            queue.push(i);
        }

        while (queue.size() > 1) {
            for (int i = 1; i < k; i++) {
                queue.push(queue.front());
                queue.pop();
            }
            queue.pop();
        }

        return queue.front();
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.findTheWinner(6, 5);
    return 0;
}