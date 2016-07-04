//
// Created by xisisu on 7/4/16.
//

/*
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 * Input: 16
 * Returns: True
 * Example 2:
 *
 * Input: 14
 * Returns: False
 */

/*
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 * Input: 16
 * Returns: True
 * Example 2:
 *
 * Input: 14
 * Returns: False
 */

#include <vector>
#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) { // 0 ms
        /*
         * binary search, 2^31 = 2147483648, so upper bound is 50000
         */
        int low = 1, high = 50000;
        while (low <= high) {
            int mid = (high+low) / 2;
            long cur = mid * mid;
            if (cur == num) { return true; }
            else if (cur < num) { low = mid+1; }
            else { high = mid-1; }
        }

        return false;
    }
};

int main() {
    Solution sol;
    for (int i = 0; i < 1100; i += 100) {
        std::cout << i << ", " << sol.isPerfectSquare(i) << std::endl;
    }
    return 0;
}