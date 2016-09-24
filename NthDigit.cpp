//
// Created by xisisu on 9/22/16.
//

/*
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
 *
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n < 2^31).
 *
 * Example 1:
 *
 * Input:
 * 3
 *
 * Output:
 * 3
 * Example 2:
 *
 * Input:
 * 11
 *
 * Output:
 * 0
 *
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */

#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int findNthDigit(int n) { // 0 ms
        /*
         * 0-9, 9 * 1
         * 10 - 99, 90 * 2
         * 100 - 999, 900 * 3
         * ....
         */
        long long len = 1, count = 9;
        while (n > len * count) {
            n -= len * count;
            ++len;
            count *= 10;
        }

        long long realNumber = (n-1) / (len) + std::pow(10, len-1); // get real number
        long long index = (n-1) % (len);

        return (int)(realNumber / std::pow(10, len-index-1)) % 10;
    }
};

int main() {
    Solution sol;
    for (long long i = 1; i < 100; ++i) {
        std::cout << i << ": " << sol.findNthDigit(i) << std::endl;
    }
    return 0;
}