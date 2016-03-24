//
// Created by Sisu on 3/23/2016.
//

/*
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
 * A gray code sequence must begin with 0.
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

class Solution {
public:
    std::vector<int> grayCode(int n) { // 8 ms
        /*
         * there are 2^n combinations, start from 0, try flip 1 bit at a time. use set to record seen
         */
        auto max = std::pow(2, n);
        std::vector<int> res;
        std::unordered_set<int> seen;

        res.push_back(0);
        seen.insert(0);
        while (res.size() < max) {
            auto cur = res.back();
            for (int i = 0; i < n; ++i) { // there are n bits, try 1 by 1
                auto flip = 0x01;
                flip <<= i;
                auto now = cur ^ flip;
                if (seen.count(now)) { continue; }
                res.push_back(now);
                seen.insert(now);
                break;
            }
        }

        return res;
    }

public:
    std::vector<int> grayCode2(int n) { // 4 ms
        std::vector<int> res;
        for (int i = 0; i < std::pow(2, n); ++i) {
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};

int main() {
    Solution sol;
    for (auto const& n : std::vector<int>{0, 1, 2, 3, 4, 8}) {
        std::cout << n << ": ";
        for (auto const& val : sol.grayCode(n)) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;

        std::cout << n << ": ";
        for (auto const& val : sol.grayCode2(n)) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;

    }

    return 0;
}