//
// Created by Sisu on 3/19/2016.
//

/*
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * For example,
 * Given the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) { // 0 ms
        if (matrix.empty() || matrix[0].empty()) { return std::vector<int>(); }

        auto M = matrix.size(), N = matrix[0].size();
        std::vector<int> res;
        auto tmp = std::min(M, N);
        auto limit = tmp%2 == 1 ? tmp/2+1 : tmp/2;
        for (auto start = 0; start < limit; ++start) {
            auto i = start, j = start;
            while (j < N-start) { res.push_back(matrix[i][j]); ++j; }
            --j; ++i;
            if (i == M-start) { break; } // single row, return here
            while (i < M-start) { res.push_back(matrix[i][j]); ++i; }
            --i; --j;
            if (j < start) { break; } // single col, return here
            while (j >= start) { res.push_back(matrix[i][j]); --j; }
            ++j; --i;
            while (i > start) { res.push_back(matrix[i][j]); --i; }
        }
        return res;
    }

public:
    enum state {UP=0, DOWN, LEFT, RIGHT};
    std::vector<int> spiralOrder2(std::vector<std::vector<int>>& matrix) { // 0 ms
        state direction = RIGHT;
        std::vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) { return res; }
        int m = matrix.size(), n = matrix[0].size();

        int x = 0, y = 0, count = 0, layer = 0;
        while (count < m*n) {
            res.push_back(matrix[x][y]);
            ++count;

            switch (direction) {
                case RIGHT:
                    if (++y == n-layer) {
                        direction = DOWN;
                        y = n-1-layer; ++x;
                    }
                    break;
                case DOWN:
                    if (++x == m-layer) {
                        direction = LEFT;
                        x = m-1-layer; --y;
                    }
                    break;
                case LEFT:
                    if (--y < layer) {
                        direction = UP;
                        y = layer; --x;
                    }
                    break;
                case UP:
                    if (--x == layer) {
                        direction = RIGHT;
                        ++layer;
                        x = layer; ++y;
                    }
                    break;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> tests = {
            { {} }
            , { { {1} } }
            , { { {1,2,3}, {4,5,6}, {7,8,9} } }
            , { { {1,2,3,4,5,6}, {6,5,4,3,2,1} } }
            , { { {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9} } }
            , { { {1,2}, {3,4}, {5,6}, {7,8}, {8,7}, {6,5} } }
            , { { {1,2,3,4,5,6,7,8,9} } }
    };

    std::ostream_iterator<int> out(std::cout, ",");
    for (auto& test: tests) {
        std::cout << "input:" << std::endl;
        for (auto const& row : test) {
            std::copy(row.begin(), row.end(), out);
            std::cout << std::endl;
        }
        std::cout << "output: ";
        auto res = sol.spiralOrder(test);
        std::copy(res.begin(), res.end(), out);
        std::cout << std::endl << std::endl;
    }

    return 0;
}
