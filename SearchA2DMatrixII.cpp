//
// Created by xisisu on 6/1/16.
//

/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 *
 * Given target = 20, return false.
 */

#include <iostream>
#include <vector>
#include <tuple>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>> const& matrix, int target) { // 240 ms
        /*
         * start from bottomLeft, using binary search
         * drawback: on 1-dimention array, fall back to liner scan search
         * Note: try different corners, different directions! one will finally work!
         */
        if (matrix.empty() || matrix[0].empty()) { return false; }

        int M = matrix.size(), N = matrix[0].size();
        int i = M-1, j = 0;
        while (i >= 0 && j < N) {
            if (target == matrix[i][j]) { return true; }
            else if (target < matrix[i][j]) { --i; }
            else { ++j; }
        }
        return false;
    }

private:
    bool binarySearch(std::vector<int> const& data, int target) {
        if (data.empty()) { return false; }
        int low = 0, high = data.size()-1;
        while (low <= high) {
            auto mid = low + (high-low)/2;
            if (target < data[mid]) { high = mid-1; }
            else if (target > data[mid]) { low = mid + 1; }
            else { return true; }
        }
        return false;
    }

public:
    bool searchMatrix2(std::vector<std::vector<int>>& matrix, int target) { // 620 ms
        /*
         * split into M binary searches, coptimized if M < N/2
         */
        if (matrix.empty() || matrix[0].empty()) { return false; }
        int M = matrix.size(), N = matrix[0].size(); // M * N  matrix
        if (M < N/2) { // arbitary condition to optimize, will change matrix content.
            std::vector<std::vector<int>> data;
            for (int j = 0; j < N; ++j) {
                std::vector<int> x;
                for (int i = 0; i < M; ++i) {
                    x.push_back(matrix[i][j]);
                }
                data.push_back(x);
            }
            matrix = data;
        }

        for (int i = 0; i < matrix.size(); ++i) {
            if (binarySearch(matrix[i], target)) { return true; }
        }
        return false;
    }


};

int main() {
    Solution sol;
    std::vector<std::vector<int>> data = {
              { 1,  4,  7, 11, 15}
            , { 2,  5,  8, 12, 19}
            , { 3,  6,  9, 16, 22}
            , {10, 13, 14, 17, 24}
            , {18, 21, 23, 26, 30}
    };

    std::vector<int> tests = {1, 30, 18, 15, 9, 19, 50, -1, 20};

    for (auto& test : tests) {
        std::cout << test << ", " << sol.searchMatrix(data, test) << ", " << sol.searchMatrix2(data, test) << std::endl;
    }

    return 0;
}