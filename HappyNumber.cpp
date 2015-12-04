//
// Created by Sisu on 12/3/2015.
//

/*
 * Write an algorithm to determine if a number is "happy".
 * A happy number is a number defined by the following process: Starting with any positive integer,
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1
 * (where it will stay), or it loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy numbers.
 * Example: 19 is a happy number
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 */

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) { // 8 ms
        std::unordered_set<int> set;
        while (n != 1) {
            if (set.count(n)) { return false; }
            set.insert(n);
            int cur = 0;
            while (n != 0) {
                cur += (n%10) * (n%10);
                n /= 10;
            }
            n = cur;
        }
        return true;
    }

    // some tests shows n converges to 1 or 4, so no need for the set
    bool isHappy_1(int n) { // 4 ms
        while (n != 1 && n != 4) {
            int sum = 0;
            while (n != 0) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {2, 19, 20, 1432, 7856};
    for (const auto & val : tests) {
        std::cout << val << ", " << sol.isHappy(val) << std::endl;
    }
    return 0;
}