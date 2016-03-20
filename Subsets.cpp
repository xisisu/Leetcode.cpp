//
// Created by Sisu on 3/20/2016.
//

/*
 * Given a set of distinct integers, nums, return all possible subsets.
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,3], a solution is:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 *  ]
 */


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Solution {
private:
    void helper(std::vector<int> const& nums, int idx, std::vector<int> cur, std::vector<std::vector<int>>& res) {
        if (idx == nums.size()) { std::sort(cur.begin(), cur.end()); res.push_back(cur); return; }
        helper(nums, idx+1, cur, res);
        cur.push_back(nums[idx]);
        helper(nums, idx+1, cur, res);
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int> const& nums) { // 8 ms
        std::vector<std::vector<int>> res;
        helper(nums, 0, std::vector<int>(), res);
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1}
            , {1,2}
            , {1,2,3}
            , {4,1,0}
    };

    std::ostream_iterator<int> out(std::cout, ", ");
    for (auto& test : tests) {
        auto res = sol.subsets(test);
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), out);
        std::cout << std::endl;
        for (auto& val : res) {
            std::copy(val.begin(), val.end(), out);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}