//
// Created by Sisu on 3/19/2016.
//

/*
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 */

#include <iostream>
#include <vector>
#include <cmath>

class Solution {
private:
    int binary(int x, int low, int high) {
        if (low >= high) { return low; }
        int mid = low + (high-low)/2;

        if (std::pow(mid, 2) <= x && std::pow(mid+1, 2) > x) { return mid; }
        else if (std::pow(mid, 2) > x) { return binary(x, low, mid-1); }
        else { return binary(x, mid+1, high); }
    }

public:
    int mySqrt(int x) { // 12 ms
        /*
         * similar to binary search
         */
        if (x <= 0) { return 0; }

        int high = 2;
        while (pow(high, 2) <= x) { high <<= 1; }

        return binary(x, high/2, high);
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {
            0
            , -100
            , 100
            , 105
    };

    for (auto const & test : tests) {
        std::cout << test << ", " << sol.mySqrt(test) << std::endl;
    }
    return 0;
}

