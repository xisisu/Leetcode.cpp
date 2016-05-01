//
// Created by Sisu on 5/1/2016.
//

/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water
 * and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid
 * are all surrounded by water.
 *
 * Example 1:
 * 11110
 * 11010
 * 11000
 * 00000
 * Answer: 1
 *
 * Example 2:
 * 11000
 * 11000
 * 00100
 * 00011
 * Answer: 3
 */

#include <iostream>
#include <vector>

class Solution {
private:
    void mark(std::vector<std::vector<char>>& data, int i, int j) {
        if (i < 0 || j < 0 || i >= data.size() || j >= data[0].size()) { return; }
        if (data[i][j] == '0') { return; }
        data[i][j] = '0';
        mark(data, i-1, j);
        mark(data, i+1, j);
        mark(data, i, j-1);
        mark(data, i, j+1);
    }

public:
    int numIslands(std::vector<std::vector<char>> const& grid) { // 8 ms
        if (grid.empty() || grid[0].empty()) { return 0; }

        auto data = grid;
        int res = 0;
        for (int i = 0; i < data.size(); ++i) {
            for (int j = 0; j < data[i].size(); ++j) {
                if (data[i][j] == '1') { mark(data, i, j); ++res; }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<char>> test = {
            {'1', '1', '0', '0', '0'}
            , {'1', '1', '0', '0', '0'}
            , {'0', '0', '1', '0', '0'}
            , {'0', '0', '0', '1', '1'}
    };

    std::cout << sol.numIslands(test) << std::endl;
    return 0;
}