//
// Created by Sisu on 3/17/2016.
//

/*
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) { // 4 ms
        if (matrix.empty()) { return; }
        auto N = matrix.size();
        for (int i = 0; i < N/2; ++i) {
            for (int j = i; j < N-1-i; ++j) {
                auto tmp = matrix[i][j];
                matrix[i][j]         = matrix[N-1-j][i];
                matrix[N-1-j][i]     = matrix[N-1-i][N-1-j];
                matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
                matrix[j][N-1-i]     = tmp;
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> tests = {
            { {} }
            , { {1} }
            , { {1,2}, {3,4}}
            , { {1,2,3}, {4,5,6}, {7,8,9} }
    };


    std::ostream_iterator<int> out_it(std::cout, ", ");

    for (auto& test: tests) {
        std::cout << std::endl << "before: " << std::endl;
        for (auto const& line : test) { std::copy(line.begin(), line.end(), out_it); std::cout << std::endl; }
        sol.rotate(test);
        std::cout << "after: " << std::endl;
        for (auto const& line : test) { std::copy(line.begin(), line.end(), out_it); std::cout << std::endl; }
    }
    return 0;
}
