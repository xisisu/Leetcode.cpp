//
// Created by xisisu on 6/25/16.
//

/*
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner
 * (row1, col1) and lower right corner (row2, col2).
 *
 * Range Sum Query 2D
 * The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which
 * contains sum = 8.
 *
 * Example:
 * Given matrix = [
 *   [3, 0, 1, 4, 2],
 *   [5, 6, 3, 2, 1],
 *   [1, 2, 0, 1, 5],
 *   [4, 1, 0, 1, 7],
 *   [1, 0, 3, 0, 5]
 * ]
 *
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * Note:
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 */

#include <iostream>
#include <vector>

class NumMatrix {
private:
    std::vector<std::vector<int>> _sum;

public:
    NumMatrix(std::vector<std::vector<int>>const& matrix) { // 24 ms
        /*
         * pre-calculate all the results for sumRegion(0,0,x,y)
         */
        if (matrix.empty() || matrix[0].empty()) { return; }
        _sum.clear();
        // upper size by 1 to deal with the edge problem
        _sum.resize(matrix.size()+1, std::vector<int>(matrix[0].size()+1, 0));

        for (int i = 0; i < matrix.size(); ++i) {
            int rowSum = 0;
            for (int j = 0; j < matrix[0].size(); ++j) {
                rowSum += matrix[i][j];
                _sum[i+1][j+1] = (i == 0) ? rowSum : rowSum + _sum[i][j+1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 >= _sum.size() || row2 >= _sum.size() || col1 >= _sum[0].size() || col2 >= _sum[0].size()) { return -1; }
        return _sum[row2+1][col2+1] - _sum[row2+1][col1] - _sum[row1][col2+1] + _sum[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main() {
    std::vector<std::vector<int>> data = {
            {3, 0, 1, 4, 2}
            , {5, 6, 3, 2, 1}
            , {1, 2, 0, 1, 5}
            , {4, 1, 0, 1, 7}
            , {1, 0, 3, 0, 5}
    };

    NumMatrix matrix(data);
    std::cout << matrix.sumRegion(0, 0, 0, 0) << std::endl;
    std::cout << matrix.sumRegion(2, 1, 4, 3) << std::endl;
    std::cout << matrix.sumRegion(1, 1, 2, 2) << std::endl;
    std::cout << matrix.sumRegion(1, 2, 2, 4) << std::endl;

    return 0;
}