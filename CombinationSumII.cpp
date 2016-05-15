//
// Created by Sisu on 3/13/2016.
//

/*
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the
 * candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Solution {
private:
    struct helperVector {
        std::vector<int> array;
        int sum;   // represent current sum in the solution array
        helperVector() : array(std::vector<int>()), sum(0) {}
    };

    void helper(std::vector<int>& candidates
            , int target
            , int cur  // cur index at candidates
            , helperVector& solution // current solution
            , std::vector<std::vector<int>>& res)
    {
        if (solution.sum > target) { return; }
        if (solution.sum == target) { res.push_back(solution.array); return; } // find one!

        for (int i = cur; i < candidates.size(); ++i) {
            // we have two options, select i, or not select i
            solution.sum += candidates[i];
            solution.array.push_back(candidates[i]);

            helper(candidates, target, i+1, solution, res);

            solution.sum -= candidates[i];
            solution.array.pop_back();

            /*
             * note here the solution set will contain duplicate values if candidates[i] == candidates[i+1]
             * for example, if we have {1,1}, select first or second makes the same solution
             * so we skip all the same elements here
             */
            while (i < candidates.size()-1 && candidates[i] == candidates[i+1]) { ++i; }
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) { // 20 ms
        std::sort(candidates.begin(), candidates.end());

        helperVector solution;
        std::vector<std::vector<int>> res;
        helper(candidates, target, 0, solution, res);

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    std::vector<int> targets = {8, 7, 10, 1, 2};

    std::cout << "candidates are: ";
    std::ostream_iterator<int> out_it(std::cout, ", ");
    std::copy(candidates.begin(), candidates.end(), out_it);
    std::cout << std::endl << std::endl;

    for (auto const& target : targets) {
        std::cout << "target: " << target << std::endl;
        auto res = sol.combinationSum2(candidates, target);
        for (auto const& val : res) {
            std::cout << "  res: ";
            std::copy(val.begin(), val.end(), out_it);
            std::cout << std::endl;
        }
    }

    return 0;
}