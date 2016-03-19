//
// Created by Sisu on 3/19/2016.
//

/*
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * For example,
 * Given n = 3,
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) { // 4 ms
        if (n <= 0) { return std::vector<std::vector<int>>(); }
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));

        auto limit = n%2 == 1 ? n/2+1 : n/2;
        auto count = 1;
        for (auto start = 0; start < limit; ++start) {
            auto i = start, j = start;
            while (j < n-start) {res[i][j] = count++; ++j; }
            --j; ++i;
            while (i < n-start) {res[i][j] = count++; ++i; }
            --i; --j;
            if (j < start) { break; } // single row/col, return here
            while (j >= start) {res[i][j] = count++; --j; }
            ++j; --i;
            while (i > start) {res[i][j] = count++; --i; }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::ostream_iterator<int> out(std::cout, ", ");
    for (int i = 0; i < 4; ++i) {
        auto res = sol.generateMatrix(i);
        std::cout << std::endl << "input: " << i << std::endl;
        for (auto const& val : res) {
            std::copy(val.begin(), val.end(), out);
            std::cout << std::endl;
        }
    }

}