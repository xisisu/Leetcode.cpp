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
//private:
//    bool check(int i, int j, int len, std::vector<std::vector<int>> const& matrix) {
//        if (i+len >= matrix.size())
//
//
//    }
public:
    int maximalSquare(std::vector<std::vector<char>> const& matrix) {
        if (matrix.empty() || matrix[0].empty()) { return 0; }
        /*
         * row[i][j] means starting from i,j, count to right, number of successive 1s
         * col[i][j] means starting from i,j, count to down, number of successive 1s
         */

        auto M = matrix.size(), N = matrix[0].size();

        // count rows
        std::vector<std::vector<int>> row(M, std::vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
          }

        // count cols
        std::vector<std::vector<int>> col(M, std::vector<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            int counter = matrix[0][i] == '1' ? 1 : 0;
            for (int j = 1; j < M; ++j) {
                if (matrix[j][i] == '1') { ++counter; }

                if (matrix[j][i] == '0' || j == M-1) {
                    while (counter > 0) {
                        row[j-counter][i] = counter;
                        --counter;
                    }
                }
            }
        }

        std::cout << "haha";

        return 0;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<char>> test = {
            {'1', '1'}
            , {'1', '1'}
//
//
//            {'1', '0', '1', '0', '0'}
//            , {'1', '0', '1', '1', '1'}
//            , {'1', '1', '1', '1', '1'}
//            , {'1', '0', '0', '1', '0'}
    };

    std::cout << sol.maximalSquare(test) << std::endl;
    return 0;
}