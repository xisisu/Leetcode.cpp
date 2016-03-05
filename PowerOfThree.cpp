//
// Created by Sisu on 3/5/2016.
//

/*
 * Given an integer, write a function to determine if it is a power of three.
 * Follow up:
 * Could you do it without using any loop / recursion?
 */

#include <iostream>
#include <vector>

class Solution {
public:
    bool isPowerOfThree(int n) { // 132 ms
        if (n == 0) { return false; }
        while (n != 1) {
            if (n % 3 != 0) { return false; }
            n /= 3;
        }
        return true;
    }
};

int main() {
    Solution sol;
    for (int i = 0; i < 82; ++i) {
        std::cout << i << ", " << sol.isPowerOfThree(i) << std::endl;
    }
    return 0;
}