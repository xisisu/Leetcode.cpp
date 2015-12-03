//
// Created by Sisu on 12/2/2015.
//

/*
 * Reverse bits of a given 32 bits unsigned integer.
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192
 * (represented in binary as 00111001011110000010100101000000).
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * Related problem: Reverse Integer
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class Solution {
public:
    Solution() {
        std::memset(table, 0, sizeof(table)); // init to 0
        uint32_t cur = 1;
        for (int i = 0; i < 32; ++i) { // init the table
            table[i] = cur;
            cur <<= 1;
        }
    }
    uint32_t table[32];

    uint32_t reverseBits(uint32_t n) { // 4 ms
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n == 0) { return res; }
            if (n & 0x01) {
                res |= table[31-i];
            }
            n >>= 1;
        }

        return res;
    }

    uint32_t reverseBits_2(uint32_t n) { // 4 ms
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res <<= 1;
            res += n & 0x01;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<uint32_t> tests;
    for (int i = 0; i < 100; ++i) { tests.push_back(i); }
    for (const auto &item : tests) {
        std::cout << item << ", " << sol.reverseBits(item) << std::endl;
    }
    return 0;
}