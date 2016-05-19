//
// Created by xisisu on 5/15/16.
//

/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 4.
 */

#include <iostream>
#include <vector>

class Solution {

public:
    int maximalSquare(std::vector<std::vector<char>> const& matrix) { // 20 ms
        if (matrix.empty() || matrix[0].empty()) { return 0; }
        /*
         * row[i][j] means starting from i,j, count to right, number of successive 1s
         * col[i][j] means starting from i,j, count to down, number of successive 1s
         */

        auto M = matrix.size(), N = matrix[0].size();
        bool existOnes = false;

        // count rows, also check whether there are '1' in the matrix
        std::vector<std::vector<int>> row(M, std::vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
            int counter = matrix[i][0] == '1' ? 1 : 0;
            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == '1') { ++counter; }
                else {
                    while (counter > 0) {
                        row[i][j-counter] = counter;
                        --counter;
                    }
                    existOnes = true;
                }
            }
            while (counter > 0) {
                row[i][N-counter] = counter;
                --counter;
                existOnes = true;
            }
        }

        if (!existOnes) { return 0; }

        // count cols
        std::vector<std::vector<int>> col(M, std::vector<int>(N, 0));
        for (int j = 0; j < N; ++j) {
            int counter = matrix[0][j] == '1' ? 1 : 0;
            for (int i = 1; i < M; ++i) {
                if (matrix[i][j] == '1') { ++counter; }
                else {
                    while (counter > 0) {
                        col[i-counter][j] = counter;
                        --counter;
                    }
                }
            }
            while (counter > 0) {
                col[M-counter][j] = counter;
                --counter;
            }
        }

        // now try to find the maximum length, typical dp problem
        std::vector<std::vector<int>> dp(M, std::vector<int>(N, 0));
        for (int i = M-1; i >= 0; --i) {
            for (int j = N-1; j >= 0; --j) {
                auto val = std::min(row[i][j], col[i][j]);

                if (i == M-1 || j == N-1) { dp[i][j] = (val == 0) ? 0 : 1; } // at edges, at most can have square 1
                else if (val == 0) { dp[i][j] = 0; }
                else { dp[i][j] = std::min(val, dp[i+1][j+1]+1); }
            }
        }

        int res = 0;
        for (auto const& row : dp) {
            for (auto const& val : row) {
                res = std::max(res, val);
            }
        }

        return res * res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<char>> test = {
            {'1', '0', '1', '0', '0'}
            , {'1', '0', '1', '1', '1'}
            , {'1', '1', '1', '1', '1'}
            , {'1', '0', '0', '1', '0'}
    };

    std::cout << sol.maximalSquare(test) << std::endl;
    return 0;
}