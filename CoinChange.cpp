//
// Created by xisisu on 7/4/16.
//

/*
 * You are given coins of different denominations and a total amount of money amount. Write a function to compute the
 * fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 *
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) { // 212 ms
        if (coins.empty()) { return 0; }
        std::sort(coins.begin(), coins.end());
        std::unordered_set<int> set(coins.begin(), coins.end());

        std::vector<int> dp(amount+1, 0);
        for (int i = 1; i <= amount; ++i) {
            if (set.count(i)) { dp[i] = 1; continue; }
            int res = INT32_MAX-1;
            for (int j = 0; j < coins.size(); ++j) {
                auto idx = i - coins[j];
                if (idx <= 0) { break; }
                res = std::min(res, dp[idx]);
            }
            dp[i] = res+1;
        }

        return dp[amount] == INT32_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    std::vector<int> coins = {1, 2, 5};
    std::vector<int> amount = {1,2,3,4,5,6,7,8,9,10};

    for (auto const & test : amount) {
        std::cout << test << ", " << sol.coinChange(coins, test) << std::endl;
    }

    return 0;
}