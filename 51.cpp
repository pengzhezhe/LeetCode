//
// Created by pzz on 2021/12/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> chessBoard;

    void backtracing(int n, int row) {
        if (row == n) {
            result.push_back(chessBoard);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isValid(row, i, n)) {
                chessBoard[row][i] = 'Q';
                backtracing(n, row + 1);
                chessBoard[row][i] = '.';
            }
        }
    }

    bool isValid(int row, int col, int n) {
        //Check col
        for (int i = 0; i < n; i++) {
            if (chessBoard[i][col] == 'Q') {
                return false;
            }
        }
        //Check 45
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }

        //Check 135
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }


public:
    vector<vector<string>> solveNQueens(int n) {
        chessBoard.insert(chessBoard.begin(), n, string(n, '.'));
        backtracing(n, 0);
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(4);
    for (const auto &vec: result) {
        for (const auto &s: vec) {
            cout << s << endl;
        }
    }
    return 0;
}