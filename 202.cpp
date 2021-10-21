//
// Created by pzz on 2021/10/21.
//
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> record;
        int sum = n;

        while (sum != 1) {
            if (record.count(sum))
                return false;

            record.insert(sum);

            n = sum;
            sum = 0;
            while (n != 0) {
                int num = n % 10;
                n /= 10;
                sum += num * num;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    int n = 19;
    cout << solution.isHappy(n);
    return 0;
}