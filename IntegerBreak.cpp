//
// Created by xisisu on 6/26/16.
//

/*
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of
 * those integers. Return the maximum product you can get.
 *
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
 *
 * Note: you may assume that n is not less than 2.
 *
 * Hint:
 *
 * There is a simple O(n) solution to this problem.
 * You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

class Solution {
private:
    int helper(int n, std::unordered_map<int, int>& cache) {
        if (cache.count(n)) { return cache[n]; }
        int res = 1;

        for (int i = 1; i <= n/2; ++i) {
            auto j = n-i;
            int first = std::max(i, helper(i, cache));
            int second = std::max(j, helper(j, cache));
            res = std::max(res, std::max(i, first) * std::max(j, second));
        }

        cache[n] = res;
        return res;
    }

public:
    int integerBreak(int n) { // 8 ms
        std::unordered_map<int, int> cache;
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 1;
        return helper(n, cache);
    }

public:
    int integerBreak2(int n) { // 0 ms
        if (n < 2) { return 0; }
        if (n == 2) { return 1; }
        if (n == 3) { return 2; }
        if (n == 4) { return 4; }

        int countThree = (n - n % 3) / 3;
        if (n%3 == 1) { return std::pow(3, countThree-1) * 4; }
        if (n%3 == 2) { return std::pow(3, countThree) * 2; }
        return std::pow(3, countThree);
    }
};

int main() {
    Solution sol;
    for (int i = 2; i <= 10; ++i) {
        std::cout << i << ", " << sol.integerBreak(i) << std::endl;
    }
    return 0;
}