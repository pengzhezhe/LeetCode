//
// Created by pzz on 2021/12/17.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int currentSum = 0, totalSum = 0, start = 0;

        for (int i = 0; i < gas.size(); i++) {
            currentSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];

            if (currentSum < 0) {
                start = i + 1;
                currentSum = 0;
            }
        }
        if (totalSum < 0)
            return -1;
        return start;
    }
};

int main() {
    return 0;
}