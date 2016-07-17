//
// Created by xisisu on 6/25/16.
//

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one
 * and sell one share of the stock multiple times) with the following restrictions:
 *
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * Example:
 *
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
 */

#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int> const& prices) { // 8 ms
        auto n = prices.size();
        if (n < 2) { return 0; }
        /*
         * ------                ------
         * | s0 |  <-- rest ---  | s2 |
         * ------                ------
         *    \                  |
         *     buy             sell
         *        \            |
         *           ------
         *           | s1 |
         *           ------
         * s0: can buy more stock
         * s1: hold the stock
         * s2: cool down period
         */
        std::vector<int> s0(n, 0);
        std::vector<int> s1(n, 0);
        std::vector<int> s2(n, 0);
        s0[0] = 0;
        s1[0] = -prices[0];
        s2[0] = INT32_MIN;

        for (int i = 1; i < prices.size(); ++i) {
            s0[i] = std::max(s0[i-1], s2[i-1]);
            s1[i] = std::max(s1[i-1], s0[i-1] - prices[i]);
            s2[i] = s1[i-1] + prices[i]; /* no max here, only 1 way to s1 */
        }

        return std::max(s0[n-1], s2[n-1]);
    }

    int maxProfit2(std::vector<int> const& prices) { // 8 ms
        auto n = prices.size();
        if (n < 2) { return 0; }
        /*
         * only four different states:
         * 1. have 1 stock and sell it
         * 2. have 1 stock and sold it
         * 3. have 0 stock and buy stock
         * 4. have 0 stock and do nothing
         *
         * some constraints about the state transition
         */
        int has1_doNothing = -prices[0];
        int has1_sell = 0;
        int has0_doNothing = 0;
        int has0_buy = -prices[0];
        for (int i = 1; i < n; ++i) {
            has1_doNothing = std::max(has1_doNothing, has0_buy);
            has0_buy       = -prices[i] + has0_doNothing;
            has0_doNothing = std::max(has0_doNothing, has1_sell);
            has1_sell      = prices[i] + has1_doNothing;
        }
        return std::max(has1_sell, has0_doNothing);
    }

    int maxProfit3(std::vector<int> const& prices) { // 8 ms
        auto n = prices.size();
        if (n < 2) { return 0; }
        int buy = INT32_MIN, sell = 0, prev_sell = 0, prev_buy;

        for (int price : prices) {
            prev_buy = buy;
            buy = std::max(prev_sell - price, buy);
            prev_sell = sell;
            sell = std::max(prev_buy + price, sell);
        }
        return sell;
    }

};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1,2,3,0,2}
            , {1}
            , {1,2,3,4,5,6,7}
            , {7,6,5,4,3,2,1}
            , {1,1,1,1,1,9,9,9,9,9}
            , {1,1,1,1,1,9,9,9,1,9}
            , {1,5,3,23,6,98,3,2,54,6,98,1,5,3}
    };

    for (auto const& test: tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        std::cout << "result: " << sol.maxProfit(test) << std::endl << std::endl;
    }
    return 0;
}
