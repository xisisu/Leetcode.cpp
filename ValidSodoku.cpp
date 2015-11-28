//
// Created by Sisu on 11/28/2015.
//

/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * A partially filled sudoku which is valid.
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) { // 12 ms
        // check size
        int N = board.size();
        if (N == 0 || N%3 != 0) { return false; }
        for (auto const& row : board) {
            if (row.size() != N) { return false; }
        }

        // check row, col, and block together, trade space for time
        bool row[N][N];
        memset(row, false, sizeof(row[0][0]) * N * N);
        bool col[N][N];
        memset(col, false, sizeof(col[0][0]) * N * N);
        bool block[N][N];
        memset(block, false, sizeof(block[0][0]) * N * N);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') { continue; }
                int val = board[i][j] - '1';
                if (val >= N) { return false; }

                // check row
                if (row[i][val]) { return false; }
                row[i][val] = true;

                // check col
                if (col[j][val]) { return false; }
                col[j][val] = true;

                // check block
                int idx = (i/3) * 3 + (j/3);
                if (block[idx][val]) { return false; }
                block[idx][val] = true;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<char>> tests = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
          , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
          , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
          , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
          , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
          , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
          , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
          , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
          , {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    for (const auto & row : tests) {
        for (const auto &val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << sol.isValidSudoku(tests) << std::endl;
    return 0;
}