//
// Created by Sisu on 5/1/2016.
//

/*
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 * For example, given the range [5, 7], you should return 4.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) { // timeout
        auto res = m;
        for (int i = m; i <= n; ++i) {
            res &= i;
        }
        return res;
    }

private:
    int highestOneBit(int n) {
        if (n == 0) { return 0; }
        int res = 1;
        n >>= 1;
        while (n) {
            res <<= 1;
            n >>= 1;
        }
        return res;
    }

public:
    int rangeBitwiseAnd2(int m, int n) { // 68 ms
        auto x = highestOneBit(m), y = highestOneBit(n);
        if (x != y || x == 0) { return 0; }
        return x + rangeBitwiseAnd(m-x, n-x);
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<int, int>> tests = {
        {0, 0}
        , {0, 1}
        , {5, 7}
    };

    for (auto const& test : tests) {
        std::cout << test.first << " - " << test.second << ", " << sol.rangeBitwiseAnd(test.first,test.second) << std::endl;
        std::cout << test.first << " - " << test.second << ", " << sol.rangeBitwiseAnd2(test.first,test.second) << std::endl << std::endl;
    }

    return 0;
}
