//
// Created by pzz on 2021/12/21.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0, ten = 0, twenty = 0;

        for (int bill: bills) {
            if (bill == 5)
                five++;
            else if (bill == 10) {
                if (five <= 0)
                    return false;
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    twenty++;
                    five--;
                    ten--;
                } else if (five >= 3) {
                    twenty++;
                    five -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}