//
// Created by Sisu on 11/22/2015.
//

/*
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * For example:
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * Hint:
 * A naive implementation of the above process is trivial. Could you come up with other methods?
 * What are all the possible results?
 * How do they occur, periodically or randomly?
 * You may find this Wikipedia article useful.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int addDigits(int num) { // 12 ms
        int res = 0;
        while (num != 0) {
            res += num % 10;
            num /= 10;
            if (res >= 10) {
                auto tmp = res % 10 + res / 10;
                res = tmp;
            }
        }
        return res;
    }

    int addDigit_2(int num) { // 12 ms
        // see https://en.wikipedia.org/wiki/Digital_root
        return num == 0 ? 0 : 1 + (num-1)%9;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {38};
    for (const auto &item: tests) {
        std::cout << item << ", " << sol.addDigits(item) << std::endl;
    }
    return 0;
}