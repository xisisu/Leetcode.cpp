//
// Created by Sisu on 11/29/2015.
//

/*
 * Given an integer n, return the number of trailing zeroes in n!.
 * Note: Your solution should be in logarithmic time complexity.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int trailingZeroes(int n) { // 4 ms
        // only need to calculate how many 5s are there
        // note 25 would count as two 5s
        int res = 0;
        while (n > 0) {
            n /= 5;
            res += n;
        }
        return res;
    }
};

int main() {
    Solution sol;
    for (int i = 0; i < 60; ++i) {
        std::cout << i << ", " << sol.trailingZeroes(i) << std::endl;
    }
    return 0;
}