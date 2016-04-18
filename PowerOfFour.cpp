//
// Created by Sisu on 4/17/2016.
//

/*
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 *
 * Example:
 * Given num = 16, return true. Given num = 5, return false.
 *
 * Follow up: Could you solve it without loops/recursion?
 */

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
private:
    std::unordered_set<int> set;

private:
    void initSet() {
        long long i = 1;
        while (i < INT32_MAX) {
            set.insert(i);
            i <<= 1;
            i <<= 1;
        }
    }

public:
    bool isPowerOfFour(int num) { // 12 ms
        /*
         * 4^n = 2^2n, so count bit and only even bit can be 1
         */
        if (num <= 0) { return false; }
        if (set.empty()) { initSet(); }
        return set.count(num);
    }

public:
    bool isPowerOfFour2(int num) { // 8 ms
        return (num > 0)        &&           // positive number
                !(num & (num-1)) &&           // power of 2
                ((num & 0x55555555) == num);  // power of 4
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {
            0,1,2,5,4,16,17,32
    };

    for (auto const& test : tests) {
        std::cout << test << ", " << sol.isPowerOfFour2(test) << std::endl;
    }

    return 0;
}