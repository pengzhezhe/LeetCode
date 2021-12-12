//
// Created by pzz on 2021/12/12.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool backtracing(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.')
                    continue;

                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(board, i, j, k)) {
                        board[i][j] = k;
                        if (backtracing(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, int num) {
        //Check the same row
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == num)
                return false;
        }

        //Check the same col;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == num)
                return false;
        }

        //Check the small grid
        int gridCol = (col / 3) * 3, gridRow = (row / 3) * 3;
        for (int i = gridRow; i < gridRow + 3; i++) {
            for (int j = gridCol; j < gridCol + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board) {
        backtracing(board);
    }
};

int main() {
    return 0;
}