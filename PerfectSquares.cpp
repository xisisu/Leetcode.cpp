//
// Created by xisisu on 6/19/16.
//

/*
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...)
 * which sum to n.
 *
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

class Solution {
private:
    std::unordered_set<long> _squares;
    std::unordered_map<int, int> _cache;

public:
    Solution() { _squares.insert(1); _cache[1] = 1; }

private:
    void fillSquares(int n) {
        int i = _squares.size();
        while (i*i <= n) {
            _squares.insert(i*i);
            ++i;
        }
    }

public:
    int numSquares(int n) { // time exceed on 345
        if (_cache.count(n)) { return _cache[n]; }

        if (n <= 0) { _cache[n] = 0; return 0; }
        fillSquares(n);
        if (_squares.count(n)) { _cache[n] = 1; return 1; }

        int res = INT32_MAX;
        for (int i = 1; i <= n/2; ++i) {
            res = std::min(res, numSquares(i) + numSquares(n-i));
        }
        _cache[n] = res;
        return res;
    }

public:
    int numSquares2(int n) { // lagrange's four-square theorem, 8 ms
        if (n <= 0) { return 0; }
        while (n%4 == 0) { n /= 4; }
        if (n%8 == 7) { return 4; }
        for (int i = 0; i*i <= n; ++i) {
            int j = (int)std::sqrt(n-i*i);
            if (i*i + j*j == n) {
                if (i == 0 || j == 0) { return 1; }
                else { return 2; }
            }
        }
        return 3;
    }

public:
    int numSquares3(int n) { // 468 ms
        std::vector<int> dp(n+1, INT16_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 0; i <= std::sqrt(n); ++i) {
            for (int j = i*i; j <= n ; ++j) {
                dp[j] = std::min(dp[j], dp[j-(i*i)]+1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,3,4,5,6,7,8,9,10,11,12,13,28, 345};
    for (auto const& test : tests) {
        std::cout << test << ", " << sol.numSquares3(test) << std::endl;
    }
    return 0;
}