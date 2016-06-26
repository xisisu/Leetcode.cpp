//
// Created by xisisu on 6/26/16.
//

/*
 * There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb.
 * On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith
 * round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after
 * n rounds.
 *
 * Example:
 *
 * Given n = 3.
 *
 * At first, the three bulbs are [off, off, off].
 * After first round, the three bulbs are [on, on, on].
 * After second round, the three bulbs are [on, off, on].
 * After third round, the three bulbs are [on, off, off].
 *
 * So you should return 1, because there is only one bulb is on.
 */


#include <iostream>
#include <vector>

class Solution {
public:
    int bulbSwitch(int n) { // 0ms
        /*
         * take 6 for example, will switch on 1,2,3,6. so stay off
         * take 4 for example, will switch on 1,2,4, so stay on
         */
        if (0 == n) { return 0; }
        int res = 1;
        while (res * res <= n) { ++res; }
        --res;
        return res;
    }
};

int main() {
    Solution sol;
    for (int i = 0; i <= 10; ++i) {
        std::cout << i << ", " << sol.bulbSwitch(i) << std::endl;
    }
    return 0;
}