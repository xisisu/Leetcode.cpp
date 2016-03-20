//
// Created by Sisu on 3/20/2016.
//

/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * For example,
 * If n = 4 and k = 2, a solution is:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Solution {
private:
    void helper(int n, int k, int val, std::vector<int> cur, std::vector<std::vector<int>>& res) {
        if (cur.size() == k) { res.push_back(cur); return; } // found one
        if (cur.size() > k || val > n) { return; } // invalid input
        helper(n, k, val+1, cur, res);
        cur.push_back(val);
        helper(n, k, val+1, cur, res);
    }

public:
    std::vector<std::vector<int>> combine(int n, int k) { // 24 ms
        if (k > n || k == 0) { return std::vector<std::vector<int>>(); }
        std::vector<std::vector<int>> res;
        helper(n, k, 1, std::vector<int>(), res);
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<int, int>> tests = {
            {0, 0}
            , {2, 1}
            , {10, 0}
            , {10, 1}
            , {0, 10}
            , {1, 10}
            , {4, 2}
    };

    std::ostream_iterator<int> out(std::cout, ", ");
    for (auto const& test : tests) {
        auto res = sol.combine(test.first, test.second);
        std::cout << "input: " << test.first << ", " << test.second << std::endl;
        for (auto& val : res) {
            std::copy(val.begin(), val.end(), out);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

