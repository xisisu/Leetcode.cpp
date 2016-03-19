//
// Created by Sisu on 3/19/2016.
//

/*
 * Implement pow(x, n).
 */

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <math.h>

class Solution {
public:
    double myPow(double x, int n) { // 4 ms
        if (x == 0.0) { return 0; } // it is ok to compare double with 0, since there is no drift
        if (n == 0) { return 1; }

        bool positive = true, reverse = false;
        if (x < 0) { x = -x; positive = (n%2 == 0); }
        if (n < 0)
        {
            if (n == std::numeric_limits<int>::min()) { return fabs(x-1.0) < 0.00001 ? 1 : 0; }
            n = -n; reverse = true;
        }

        double res = 1.0, tmp = x;
        while (n > 0) {
            if (n%2 == 1)
            {
                if (std::numeric_limits<double>::max() / tmp < res) { res = std::numeric_limits<double>::max(); break; }
                res *= tmp;
            }
            n >>= 1;
            tmp *= tmp;
        }

        if (reverse) { res = 1 / res; }
        return positive ? res : -res;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<double, int>> tests = {
            { 0.0, 0 }
            , { 2.0, -2147483648}
            , { 1.0, -2147483648}
            , { 0.0, 100 }
            , { 1.0, 0 }
            , { 1.0, 100 }
            , { 2, 10 }
            , { -2, 10 }
            , { -2, 9 }
            , { 0.1, 10 }
            , { 0.1, -10 }
    };

    for (auto const& test: tests) {
        std::cout << "(" << test.first << ", " << test.second << ", " << sol.myPow(test.first, test.second) << ")" << std::endl;
    }

    return 0;
}