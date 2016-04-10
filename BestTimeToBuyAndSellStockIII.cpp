//
// Created by Sisu on 4/9/2016.
//

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int> const& prices) { // 12 ms
        int N = prices.size();
        if (N < 2) { return 0; }
        std::vector<int> left;   // first profit we can get if sell at i or before
        std::vector<int> right;  // second profit we can get if buy at i or after

        int minSoFar = INT32_MAX;
        int curMax   = INT32_MIN;
        for (auto const& val : prices) {
            minSoFar = std::min(minSoFar, val);
            curMax   = std::max(curMax, val - minSoFar);
            left.push_back(curMax);
        }

        int maxSoFar = INT32_MIN;
        curMax       = INT32_MIN;
        for (int i = prices.size()-1; i >= 0; --i) {
            maxSoFar = std::max(maxSoFar, prices[i]);
            curMax   = std::max(curMax, maxSoFar - prices[i]);
            right.push_back(curMax);
        }
        std::reverse(right.begin(), right.end());

        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int val;
            if (i == 0) { val = right[i]; }
            else if (i == prices.size()-1) { val = left[i]; }
            else { val = left[i] + right[i]; } // note here we can sell at i and then buy at i, still valid
            profit = std::max(profit, val);
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
