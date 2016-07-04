//
// Created by xisisu on 7/4/16.
//

/*
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 * Example:
 * Given a = 1 and b = 2, return 3.
 */

#include <vector>
#include <iostream>


class Solution {
private:
    int countOnes(int a, int b, int c) {
        if (a) {
            if (b && c) { return 3; }
            else if (b || c) { return 2; }
            else { return 1; }
        } else {
            if (b && c) { return 2; }
            else if (b || c) { return 1; }
            else { return 0; }
        }
    }

public:
    int getSum(int a, int b) { // 0 ms
        int res = 0, carry = 0, pos = 0;
        while ((a || b || carry) && pos < 32) {
            auto curA = a & 0x01; a >>= 1;
            auto curB = b & 0x01; b >>= 1;
            int cur;
            switch (countOnes(carry, curA, curB)) {
                case 0: cur = 0; carry = 0; break;
                case 1: cur = 1; carry = 0; break;
                case 2: cur = 0; carry = 1; break;
                case 3: cur = 1; carry = 1; break;
            }
            cur <<= pos;
            ++pos;
            res |= cur;
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<int, int>> tests = {
            {0, 0}
            , {0, 1}
            , {100, 0}
            , {10, 20}
            , {999, 999}
            , {-1, -1}
    };

    for (auto const& test : tests) {
        std::cout << test.first << " + " << test.second << " = " << sol.getSum(test.first, test.second) << std::endl;
    }

    return 0;
}