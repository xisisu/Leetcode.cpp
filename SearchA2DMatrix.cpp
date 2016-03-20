//
// Created by Sisu on 3/19/2016.
//

/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 * Consider the following matrix:
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>> const& matrix, int target) { // 12 ms
        /*
         * binary search
         */
        if (matrix.empty() || matrix[0].empty()) { return false; }
        auto M = matrix.size(), N = matrix[0].size();
        long long low = 0, high = M*N;
        while (low <= high) {
            auto mid = low + (high-low)/2;
            int i = mid/N, j = mid%N;
            if (i >= M) { return false; }
            if (matrix[i][j] < target) { low = mid+1; }
            else if (matrix[i][j] > target) { high = mid-1; }
            else { return true; }
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> data = {
            {1,3,5,7}
            , {10,11,16,20}
            , {23,30,34,50}
    };

    std::vector<int> targets = {0,1,2,3,11,50,100};
    for (auto const& t : targets) {
        std::cout << t << ", " << sol.searchMatrix(data, t) << std::endl;
    }

    return 0;
}

