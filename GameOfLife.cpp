//
// Created by xisisu on 6/19/16.
//

/*
 * According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised
 * by the British mathematician John Horton Conway in 1970."
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its
 * eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia
 * article):
 *
 * Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 * Any live cell with two or three live neighbors lives on to the next generation.
 * Any live cell with more than three live neighbors dies, as if by over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 * Write a function to compute the next state (after one update) of the board given its current state.
 *
 * Follow up:
 * Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some
 * cells first and then use their updated values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause
 * problems when the active area encroaches the border of the array. How would you address these problems?
 */

#include <iostream>
#include <vector>

class Solution {
private:
    int getNeighbors(std::vector<std::vector<int>>& board, int i, int j) {
        int res = 0;
        for (int m = std::max(0, i-1); m <= std::min(i+1, int(board.size()-1)); ++m) {
            for (int n = std::max(0, j-1); n <= std::min(j+1, int(board[0].size()-1)); ++n) {
                if (m == i && n == j) { continue; }
                if (board[m][n] & 0x01) { ++res; } // both 1 & 3 are considered live
            }
        }
        return res;
    }

public:
    void gameOfLife(std::vector<std::vector<int>>& board) { // 0 ms
        /*
         * 0 --> 1 represented as 2
         * 1 --> 0 represented as 3
         */
        // mark 2 & 3
        if (board.empty() || board[0].empty()) { return; }
        int M = board.size(), N = board[0].size();

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                auto neighbors = getNeighbors(board, i, j);
                if (board[i][j] == 0) {
                    if (neighbors == 3) { board[i][j] = 2; } // dead to live, reproduction
                } else {
                    if (neighbors < 2) { board[i][j] = 3; } // live to dead, under population
                    if (neighbors > 3) { board[i][j] = 3; } // live to dead, over population
                }
            }
        }

        for (auto& row : board) {
            for (auto& val : row) {
                if (val == 2) { val = 1; }
                if (val == 3) { val = 0; }
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> board = {
            {0,0,0,0,0}
            , {0,0,1,0,0}
            , {0,0,1,0,0}
            , {0,0,1,0,0}
            , {0,0,0,0,0}
    };

    std::cout << "before: " << std::endl;
    for (auto const& row : board) {
        for (auto const& val : row) {
            std::cout << val;
        }
        std::cout << std::endl;
    }

    sol.gameOfLife(board);

    std::cout << std::endl << "after: " << std::endl;
    for (auto const& row : board) {
        for (auto const& val : row) {
            std::cout << val;
        }
        std::cout << std::endl;
    }

    return 0;
}