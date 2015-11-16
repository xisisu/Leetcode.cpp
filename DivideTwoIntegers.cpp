//
// Created by Sisu on 11/15/2015.
//

/*
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 */

#include <iostream>
#include <vector>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Solution {
public:
    int divide(int dividend, int divisor) { // 8 ms
        // use long long to avoid overflow
        long long a = dividend, b = divisor; // dividend / divisor, aka, a / b

        // special cases
        if (b == 1) { return a; }
        else if (b == -1) { return a == std::numeric_limits<int>::min() ? std::numeric_limits<int>::max() : -a; }
        else if (abs(a) < abs(b)) { return 0; }
        else if (a == 0 || b == 0) { return 0; }

        // turn all of them to positive numbers
        int sign = 1;
        if (a < 0) { a = -a; sign += 1; }
        if (b  < 0) { b  = -b; sign += 1; }

        // construct a table with all b powers of 2
        long long table[32];
        memset(table, 0, 32);
        int idx = 0;
        while (b <= a) {
            table[idx++] = b;
            b <<= 1;
        }
        --idx;

        // now fit a into the table and calculate results
        int res = 0;
        while (idx >= 0) {
            if (a >= table[idx]) {
                a -= table[idx];
                auto tmp = 1 << idx;
                res += tmp;
            }
            --idx;
        }

        return sign & 0x01 ? res : -res;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {2, 2147483647, 1235, 187692435};
    for (const auto& item: tests) {
        std::cout << item << ", " << sol.divide(item, 2) << std::endl;
    }
    return 0;
}