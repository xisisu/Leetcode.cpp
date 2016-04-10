//
// Created by Sisu on 4/9/2016.
//

/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the
 * row below.
 *
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the
 * triangle.
 */

#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) { // 12 ms
        if (triangle.empty()) { return INT32_MAX; }
        std::vector<int> data[2];
        int cur = 0;
        data[cur] = triangle[0];

        for (int i = 1; i < triangle.size(); ++i) {
            auto nxt = (cur+1)%2;
            data[nxt].clear();
            auto row = triangle[i];
            for (int j = 0; j < row.size(); ++j) {
                if (j == 0) { data[nxt].push_back(data[cur][0] + row[0]); }
                else if (j == row.size()-1) { data[nxt].push_back(data[cur].back() + row.back()); }
                else { data[nxt].push_back(row[j] + std::min(data[cur][j-1], data[cur][j])); }
            }
            cur = nxt;
        }

        int res = INT32_MAX;
        for (auto const& val : data[cur]) { res = std::min(val, res); }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> input = {
            {2}
            , {3,4}
            , {6,5,7}
            , {4,1,8,3}
    };

    std::cout << "input: " << std::endl;
    for (auto const& row : input) {
        std::copy(row.begin(), row.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
    }

    std::cout << "result: " << sol.minimumTotal(input) << std::endl;

    return 0;
}