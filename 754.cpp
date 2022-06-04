//
// Created by pzz on 2022/6/4.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        for (int i = 1;; i++) {
            sum += i;
            if (sum == target)
                return i;
            if (sum > target && (sum - target) % 2 == 0)
                return i;
        }
        return 0;
    }
};

int main() {
    return 0;
}