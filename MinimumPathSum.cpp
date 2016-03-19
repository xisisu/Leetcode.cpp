//
// Created by Sisu on 3/19/2016.
//

/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the
 * sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>> const& grid) { // 28 ms
        /*
         * typical dp, dp[i][j] = min{dp[i-1][j], dp[i][j-1]} + grid[i][j]
         */
        if (grid.empty() || grid[0].empty()) { return 0; }
        auto m = grid.size(), n = grid[0].size();
        int dp[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) { dp[i][j] = grid[i][j]; }
                else if (i == 0) { dp[i][j] = dp[i][j-1] + grid[i][j]; }
                else if (j == 0) { dp[i][j] = dp[i-1][j] + grid[i][j]; }
                else { dp[i][j] = std::min(dp[i-1][j],dp[i][j-1]) + grid[i][j]; }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> tests = {
            { {1,2,3,3,2,1}, {3,2,1,1,2,3} }
    };

    std::ostream_iterator<int> out(std::cout, ", ");
    for (auto const& test : tests) {
        std::cout << "input: " << std::endl;
        for (auto const& row : test) {
            std::copy(row.begin(), row.end(), out);
            std::cout << std::endl;
        }
        std::cout << "res: " << sol.minPathSum(test) << std::endl << std::endl;
    }

    return 0;
}