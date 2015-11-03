//
// Created by Sisu on 11/2/2015.
//

/*
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * Have you thought about this?
 * Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 * Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
 * then the reverse of 1000000003 overflows. How should you handle such cases?
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 * Update (2014-11-10):
 * Test cases had been added to test the overflow behavior.
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>

class Solution {
public:
    int reverse(int x) { // 8 ms
        int res = 0;
        bool negative = (x < 0);
        while (x != 0) {
            if ( (negative && (std::numeric_limits<int>::min() - x % 10) / 10 > res) ||
                 (!negative && (std::numeric_limits<int>::max() - x % 10) / 10 < res) ) {
                return 0;
            }
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {123, -123, 10, 100, 1000000003};
    for (auto item : tests) {
        std::cout << item << ", " << sol.reverse(item) << std::endl;
    }
    return 0;
}
