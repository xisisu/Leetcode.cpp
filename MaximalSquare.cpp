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
    int maximalSquare(std::vector<std::vector<char>> const& matrix) { // 12 ms
        if (matrix.empty() || matrix[0].empty()) { return 0; }

        auto M = matrix.size(), N = matrix[0].size();
        int res = 0;
        std::vector<std::vector<int>> dp(M, std::vector<int>(N, 0));
        for (int i = M-1; i >= 0; --i) {
            for (int j = N-1; j >= 0; --j) {
                if (matrix[i][j] == '0') { continue; }

                if (i == M-1 || j == N-1) { dp[i][j] = matrix[i][j] == '1' ? 1 : 0; }
                else { dp[i][j] = std::min(std::min(dp[i+1][j+1],dp[i][j+1]),dp[i+1][j]) + 1; }

                res = std::max(res, dp[i][j]);
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