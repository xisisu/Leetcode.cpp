//
// Created by Sisu on 11/23/2015.
//

/*
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has
 * (also known as the Hamming weight).
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011,
 * so the function should return 3.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int hammingWeight(uint32_t n) { // 4 ms
        int res = 0;
        while (n > 0) {
            if (n & 0x01) { ++res; }
            n >>= 1;
        }
        return res;
    }

    int hammingWeight_2(uint32_t n) { // 8 ms
        int res = 0;
        while (n > 0) {
            ++res;
            n &= (n-1); // clear least 1 bit
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {0, 1, 2, 3, 4, 5, 6, 7};
    for (const auto & item : tests) {
        std::cout << item << ", " << sol.hammingWeight(item) << std::endl;
    }
    return 0;
}