//
// Created by Sisu on 11/23/2015.
//

/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    int climbStairs(int n) { // 0 ms
        int table[n+1];
        memset(table, 0, sizeof(table));
        for (int i = 0; i <= n; ++i) {
            if (i == 0 || i == 1) { table[i] = 1; }
            else { table[i] = table[i-1] + table[i-2]; }
        }
        return table[n];
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {0,1,2,3,4,5,6,7};
    for (const auto & item : tests) {
        std::cout << item << ", " << sol.climbStairs(item) << std::endl;
    }
    return 0;
}
