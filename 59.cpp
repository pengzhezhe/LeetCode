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

        int row = 0, line = 0;
        int loop = n / 2;
        int isSingle = n % 2;
        int num = 1;
        while (loop--) {
            // 1. Left to right
            for (int i = row; i < n - line - 1; i++) {
                res[row][i] = num++;
            }

            //2. Top to bottom
            for (int j = line; j < n - row - 1; j++) {
                res[j][n - row - 1] = num++;
            }

            //3. Right to left
            for (int i = n - row - 1; i > row; i--) {
                res[n - row - 1][i] = num++;
            }

            //4. Bottom to top
            for (int j = n - line - 1; j > line; j--) {
                res[j][line] = num++;
            }

            row++;
            line++;
        }
        if (isSingle) {
            res[row][line] = num;
        }
        return res;
    }
};

int main() {
    int n = 1;
    Solution solution;
    vector<vector<int>> res = solution.generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << res[i][j] << endl;
    }
    return 0;
}