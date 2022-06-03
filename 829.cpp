//
// Created by pzz on 2022/6/3.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int k = 1; k * k < 2 * n; k++) {
            if (2 * n % k != 0)
                continue;
            if ((2 * n / k - k + 1) % 2 == 0)
                ans++;
        }
        return ans;
    }
};

int main() {
    return 0;
}