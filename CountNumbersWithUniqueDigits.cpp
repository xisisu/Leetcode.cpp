//
// Created by xisisu on 6/27/16.
//

/*
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
 *
 * Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding
 * [11,22,33,44,55,66,77,88,99])
 *
 * Hint:
 *
 * A direct way is to use the backtracking approach.
 * Backtracking should contains three states which are (the current number, number of steps to get that number and a
 * bitmask which represent which number is marked as visited so far in the current number). Start with state (0,0,0)
 * and count all valid number till we reach number of steps equals to 10n.
 * This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
 * Let f(k) = count of numbers with unique digits with length equals k.
 * f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].
 */

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
private:
    std::vector<int> _cache;

public:
    int countNumbersWithUniqueDigits(int n) { // 0 ms
        /*
         * f(0) = 1
         * f(1) = 10
         * f(2) = 10 + 9*9
         * f(3) = 10 + 9*9 + 9*9*8
         * f(4) = 10 + 9*9 + 9*9*8 + 9*9*8*7
         * ...
         * f(10) = f(9) + 9*9*8*..*1
         * f(11) = f(10)
         */
        if (_cache.empty()) {
            _cache.push_back(1);
            _cache.push_back(10);
        }

        if (_cache.size() > n+1) { return _cache[n]; }
        int i = _cache.size();
        while (i <= std::min(10, n)) {
            int tmp = 9;
            for (int j = 0; j < i-1; ++j) { tmp *= (9-j); }
            _cache.push_back(_cache.back() + tmp);
            ++i;
        }
        return _cache[std::min(10,n)];
    }
};


int main() {
    Solution sol;
    for (int i = 0; i < 15; ++i) {
        std::cout << i << ", " << sol.countNumbersWithUniqueDigits(i) << std::endl;
    }
    return 0;
}
