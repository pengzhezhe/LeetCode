//
// Created by pzz on 2021/10/9.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n, vector<int>(n, 0));

        int startX = 0, startY = 0;
        int loop = n / 2;
        int isSingle = n % 2;
        int num = 1;
        while (loop--) {
            // 1. Left to right
            for (int i = startY; i < n - startY - 1; i++) {
                res[startX][i] = num++;
            }

            //2. Top to bottom
            for (int i = startX; i < n - startX - 1; i++) {
                res[i][n - startY - 1] = num++;
            }

            //3. Right to left
            for (int i = n - startY - 1; i > startY; i--) {
                res[n - startX - 1][i] = num++;
            }

            //4. Bottom to top
            for (int i = n - startX - 1; i > startX; i--) {
                res[i][startY] = num++;
            }

            startX++;
            startY++;
        }
        if (isSingle) {
            res[startX][startY] = num;
        }
        return res;
    }
};

int main() {
    int n = 4;
    Solution solution;
    vector<vector<int>> res = solution.generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << res[i][j] << endl;
    }
    return 0;
}