//
// Created by pzz on 2022/6/5.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    double r, x, y;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint() {
        while (true) {
            double xRandom = rand() / double(RAND_MAX) * 2 * r - r;
            double yRandom = rand() / double(RAND_MAX) * 2 * r - r;

            if (xRandom * xRandom + yRandom * yRandom <= r * r) {
                return {x + xRandom, y + yRandom};
            }
        }
    }
};

int main() {
    return 0;
}