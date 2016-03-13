//
// Created by Sisu on 3/13/2016.
//

/*
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate
 * numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7,
 * A solution set is:
 * [7]
 * [2, 2, 3]
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) { // 68 ms
        /*
         * note all numbers are positive, so no 0
         * dp[i] = union_set { dp[i-c] + c }, where c belongs to candidates
         */
        std::map<int, std::vector<std::vector<int>>> res;
        std::sort(candidates.begin(), candidates.end());

        for (int i = 1; i <= target; ++i) {
            // candidates is already sorted
            for (auto const& c : candidates) {
                if (c > i) { break; }
                else if (c == i) { res[i].push_back(std::vector<int>(1, i)); }
                else {
                    for (auto const& val : res[i-c]) {
                        if (c < val.back()) { continue; } /* make sure the res is in order */
                        auto tmp = val;
                        tmp.push_back(c);
                        res[i].push_back(tmp);
                    }
                }
            }
        }

        return res[target];
    }
};

int main() {
    Solution sol;
    std::vector<int> candidates = {7, 3, 2, 6};
    std::vector<int> targets = {7, 10, 1, 2};

    std::cout << "candidates are: ";
    std::ostream_iterator<int> out_it(std::cout, ", ");
    std::copy(candidates.begin(), candidates.end(), out_it);
    std::cout << std::endl << std::endl;

    for (auto const& target : targets) {
        std::cout << "target: " << target << std::endl;
        auto res = sol.combinationSum(candidates, target);
        for (auto const& val : res) {
            std::cout << "  res: ";
            std::copy(val.begin(), val.end(), out_it);
            std::cout << std::endl;
        }
    }

    return 0;
}