//
// Created by Sisu on 3/2/2016.
//

/*
 * Given an integer, write a function to determine if it is a power of two.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    bool isPowerOfTwo(int n) { // 8 ms
        if (n <= 0) { return false; }
        while (n > 1) {
            if (n & 0x01) { return false; }
            n >>= 1;
        }
        return true;
    }

    bool isPowerOfTwo2(int n) { // 8 ms
        if (n <= 0) { return false; }
        return !(n & (n-1));
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {-1, 0, 1, 2, 3, 4};

    for (auto const& test : tests) {
        std::cout << "(" << test << ", " << sol.isPowerOfTwo(test) << ", " << sol.isPowerOfTwo2(test) << ")" << std::endl;
    }

    return 0;
}