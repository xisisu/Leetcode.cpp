//
// Created by Sisu on 11/29/2015.
//

/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) { // 0 ms
        std::vector<std::vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            if (0 == i) { res.push_back(std::vector<int>(1, 1)); continue; } // special case for first row
            auto pre = i-1;
            std::vector<int> cur;
            for (int j = 0; j < res[pre].size(); ++j) {
                if (0 == j) { cur.push_back(1); continue; } // first col
                cur.push_back(res[pre][j-1] + res[pre][j]);
            }
            cur.push_back(1);
            res.push_back(cur);
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto res = sol.generate(5);
    for (const auto &item : res) {
        for (const auto &val : item) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}