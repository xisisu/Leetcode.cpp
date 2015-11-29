//
// Created by Sisu on 11/29/2015.
//

/*
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,
 * Return [1,3,3,1].
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */

#include <iostream>
#include <vector>

class Solution {
public:
    /*
     * 1. claim an array of results size, init all elements to 1
     * 2. perform operations in the end to simulate the add operation
     * note here the row index starts with 0, see problem description
     */
    std::vector<int> getRow(int rowIndex) { // 0 ms
        std::vector<int> res(rowIndex+1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            for (int start = rowIndex-i+1; start < rowIndex; ++start) {
                res[start] += res[start+1];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    sol.getRow(3);

    for (int i = 0; i < 5; ++i) {
        auto res = sol.getRow(i);
        for (auto const &item : res) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}