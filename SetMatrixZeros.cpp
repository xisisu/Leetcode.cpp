//
// Created by Sisu on 3/19/2016.
//

/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * click to show follow up.
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) { // 84 ms
        if (matrix.empty() || matrix[0].empty()) { return; }

        int col = -1, row = -1;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (col == -1 || row == -1) { col = j; row = i; }
                    else { matrix[row][j] = 0; matrix[i][col] = 0; }
                }
            }
        }
        if (col == -1 && row == -1) { return; } // no zero elements

        for (int i = 0; i < matrix.size(); ++i) {
            if (i == row) { continue; }
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (j == col) { continue; }
                if (matrix[i][col] == 0 || matrix[row][j] == 0) { matrix[i][j] = 0; }
            }
        }

        for (int i = 0; i < matrix.size(); ++i) { matrix[i][col] = 0; }
        for (int j = 0; j < matrix[0].size(); ++j) { matrix[row][j] = 0; }
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> tests = {
            {
                    {1,2,3,4}
                    , {1,2,0,4}
                    , {1,2,3,4}
            }, {
                    {1,2,3,4,5,6,7}
                    , {1,2,3,4,0,6,7}
                    , {1,2,3,0,5,6,7}
                    , {1,2,3,4,5,6,7}
            }, {
                    {1,2,3,4,5,6,7}
                    , {1,2,3,4,5,6,7}
                    , {1,2,3,4,5,6,7}
                    , {1,2,3,4,5,6,7}
            }
    };

    std::ostream_iterator<int> out(std::cout, ",");
    for (auto& test : tests) {
        std::cout << "before: " << std::endl;
        for (auto& val : test) {
            std::copy(val.begin(), val.end(), out);
            std::cout << std::endl;
        }
        std::cout << "after: " << std::endl;
        sol.setZeroes(test);
        for (auto& val : test) {
            std::copy(val.begin(), val.end(), out);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}