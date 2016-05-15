//
// Created by xisisu on 5/14/16.
//

/*
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be
 * used and each combination should be a unique set of numbers.
 * Ensure that numbers within the set are sorted in ascending order.
 *
 * Example 1:
 * Input: k = 3, n = 7
 * Output:
 * [[1,2,4]]
 *
 * Example 2:
 * Input: k = 3, n = 9
 * Output:
 * [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) { // 44 ms
        /*
         * since we can pick only from 1 to 9, any k larger than 9 or n larger than 45 is invalid
         */
        if (k <= 0 || k > 9 || n > 45 || n <= 0 || n < k) { return {}; }

        std::vector<std::vector<std::set<std::set<int>>>> dp(n+1, std::vector<std::set<std::set<int>>>(k+1, std::set<std::set<int>>()));
        // init 1-9 to the list
        for (int i = 1; i <= std::min(9, n); ++i) { dp[i][1].insert({{i}}); }

        // algorithm: dp[n][k][] = dp[n-val][k-1][] + val, given that val does not exist in the set
        for (int kVal = 2; kVal <= k; ++kVal) {
            for (int nVal = kVal; nVal <= n; ++nVal) {
                for (int i = 1; i <= 9; ++i) {
                    if (nVal <= i) { break; }
                    for (auto cur : dp[nVal-i][kVal-1]) {
                        if (cur.count(i)) { continue; }
                        cur.insert(i);
                        dp[nVal][kVal].insert(cur);
                    }
                }
            }
        }

        std::vector<std::vector<int>> result;
        for (auto const& cur : dp[n][k]) {
            std::vector<int> x;
            for (auto const& val : cur) {
                x.push_back(val);
            }
            result.push_back(x);
        }

        return result;
    }

private:
    void helper(int target, int k, int start, std::vector<int> x, std::vector<std::vector<int>>& result) {
        if (target == 0 && k == 0) { result.push_back(x); return; }
        if (target < 0 || k < 0 || start > 9 || target < start) { return; }
        for (int i = start; i <= 9; ++i) {
            x.push_back(i);
            helper(target-i, k-1, i+1, x, result);
            x.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum3_2(int k, int n) { // 0 ms
        if (k <= 0 || k > 9 || n > 45 || n <= 0 || n < k) { return {}; }

        std::vector<std::vector<int>> result;
        std::vector<int> temp;

        /*
         * pick k numbers from 1 to 9 to form a sum of n. Each number can be picked or not picked
         */
        helper(n, k, 1, temp, result);
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<int, int>> tests = {
//            {1, 9}
            {2, 7}
            , {3, 7}
            , {3, 9}
            , {2, 18}
    };

    for (auto const& test : tests) {
        std::cout << "input: " << test.first << ", " << test.second << std::endl;
        auto res = sol.combinationSum3_2(test.first, test.second);
        for (auto const& val : res) {
            std::cout << "\t";
            std::copy(val.begin(), val.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}