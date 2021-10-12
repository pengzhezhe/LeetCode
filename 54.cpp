//
// Created by pzz on 2021/10/11.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n, 0);
        int startX = 0, startY = 0;
        int count = 0;
        int loop = min(m, n) / 2;
        int existMiddle = min(m, n) % 2;
        while (loop--) {
            for (int i = startY; i < n - startY - 1; i++)
                res[count++] = matrix[startX][i];

            for (int i = startX; i < m - startX - 1; i++)
                res[count++] = matrix[i][n - startY - 1];

            for (int i = n - startY - 1; i > startY; i--)
                res[count++] = matrix[m - startX - 1][i];

            for (int i = m - startX - 1; i > startX; i--)
                res[count++] = matrix[i][startY];

            startX++;
            startY++;
        }
        if (existMiddle) {
            if (m == n)
                res[count] = matrix[startX][startY];
            else if (m < n)
                for (int i = startY; i < n - startY; i++)
                    res[count++] = matrix[startX][i];
            else
                for (int i = startX; i < m - startX; i++)
                    res[count++] = matrix[i][startY];
        }

        return res;
    }
};

int main() {
    Solution solution;
//    vector<vector<int>> matrix{{1, 2,  3,  4},
//                               {5, 6,  7,  8},
//                               {9, 10, 11, 12}};

//    vector<vector<int>> matrix{{6, 9, 7}};
    vector<vector<int>> matrix{{3},{2}};

//    vector<vector<int>> matrix{{1, 2, 3},
//                               {4, 5, 6},
//                               {7, 8, 9}};
    vector<int> res = solution.spiralOrder(matrix);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}