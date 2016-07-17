//
// Created by xisisu on 7/17/16.
//

/*
 * Write a program to find the nth super ugly number.
 *
 * Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For
 * example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given
 * primes = [2, 7, 13, 19] of size 4.
 *
 * Note:
 * (1) 1 is a super ugly number for any given primes.
 * (2) The given numbers in primes are in ascending order.
 * (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) { // 120 ms
        if (primes.empty() || n <= 0) { return 0; }
        if (n == 1) { return 1; }

        std::vector<int> result = {0, 1};
        std::vector<int> pointer(primes.size(), 1);
        while (n > 1) {
            int curMin = INT32_MAX;
            for (int i = 0; i < pointer.size(); ++i) {
                curMin = std::min(curMin, result[pointer[i]] * primes[i]);
            }
            result.push_back(curMin);
            for (int i = 0; i < pointer.size(); ++i) {
                if (curMin == result[pointer[i]] * primes[i]) {
                    ++pointer[i];
                }
            }
            --n;
        }
        return result.back();
    }
};

int main() {
    Solution sol;
    std::vector<int> primes = {2,7,13,19};

    for (int i = 0; i < 13; ++i) {
        std::cout << i << ", " << sol.nthSuperUglyNumber(i, primes) << std::endl;
    }

    return 0;
}