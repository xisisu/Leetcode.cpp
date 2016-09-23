//
// Created by xisisu on 9/22/16.
//

/*
 * Given a positive integer n and you can do operations as follow:
 *
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * What is the minimum number of replacements needed for n to become 1?
 *
 * Example 1:
 *
 * Input:
 * 8
 *
 * Output:
 * 3
 *
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 * Example 2:
 *
 * Input:
 * 7
 *
 * Output:
 * 4
 *
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int integerReplacement(int n) { // 3 ms
        /*
         * if lowest bit is 0, perform /2
         * if lowest two bits are 11, perform +1 to make it 100 (3 is exception)
         * if lowest two bits are 01, perform -1 to make it 00
         */
        int res = 0;
        long long number = n;
        while (number > 1) {
            if (!(number & 1)) { number >>= 1; }
            else if (number == 3) { --number; }
            else if ((number >> 1) & 1) { ++number; }
            else { --number; }
            ++res;
        }
        return res;
    }
};

int main() {
    Solution sol;
    for (int i = 65535; i <= 65535; ++i) {
        std::cout << i << ", " << sol.integerReplacement(i) << std::endl;
    }
    return 0;
}

