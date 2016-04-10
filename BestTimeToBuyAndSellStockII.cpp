//
// Created by Sisu on 4/9/2016.
//

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and
 * sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time
 * (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    int maxProfit(std::vector<int> const& prices) { // 8 ms
        // greedy algorithm, reset minSoFar when buy/sell
        int minSoFar = INT32_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            minSoFar = std::min(minSoFar, prices[i]);
            if (prices[i] > minSoFar) {
                profit += prices[i] - minSoFar;
                minSoFar = prices[i]; // reset minSoFar
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
              {}
            , {1}
            , {1,2,3,4,5,6,7}
            , {7,6,5,4,3,2,1}
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
