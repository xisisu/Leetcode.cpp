//
// Created by Sisu on 3/19/2016.
//

/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right
 * corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) { // 0 ms
        /*
         * typical dp problem, dp[i][j] = dp[i-1][j] + dp[i][j-1]
         */
        if (m <= 0 || n <= 0) { return 0; }
        int dp[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) { dp[i][j] = 1; }
                else { dp[i][j] = dp[i-1][j] + dp[i][j-1]; }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<int, int>> tests = {
            { 0, 0 }
            , { 1, 1 }
            , { 2, 10 }
    };

    for (auto const& test : tests) {
        std::cout << "(" << test.first << "," << test.second << ") : " << sol.uniquePaths(test.first, test.second) << std::endl;
    }
    return 0;
}