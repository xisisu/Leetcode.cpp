//
// Created by Sisu on 3/19/2016.
//

/*
 * Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 * Note: m and n will be at most 100.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> const& obstacleGrid) { // 4 ms
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) { return 0; }
        auto m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) { dp[i][j] = 0; }
                else if (i == 0 && j == 0) { dp[i][j] = 1; }
                else if (i == 0) { dp[i][j] = dp[i][j-1]; }
                else if (j == 0) { dp[i][j] = dp[i-1][j]; }
                else { dp[i][j] = dp[i-1][j] + dp[i][j-1]; }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> tests = {
            { {0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0} }
            , { {0, 0, 1, 0, 0, 0, 0, 0} }
    };

    for (auto const& test : tests) {
        std::cout << sol.uniquePathsWithObstacles(test) << std::endl;
    }

    return 0;
}