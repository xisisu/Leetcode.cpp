//
// Created by Sisu on 3/27/2016.
//

/*
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) { // 24 ms
        /*
         * simple bit operation, there are 2^n combinations
         * use set to record seen subset
         */
        auto max = std::pow(2, nums.size());
        std::set<std::vector<int>> set;
        std::vector<std::vector<int>> res;
        std::vector<int> x;

        for (int i = 0; i < max; ++i) {
            // use the bit representation of cur to push items into res
            int cur = i, idx = 0;
            x.clear();
            while (cur > 0) {
                if (cur & 0x01) { x.push_back(nums[idx]); }
                ++idx; cur >>= 1;
            }
            std::sort(x.begin(), x.end());
            if (!set.count(x)) {
                res.push_back(x);
                set.insert(x);
            }
        }

        return res;
    }

private:
    void helper(std::vector<std::vector<int>>& res, std::vector<int>& cur, std::vector<int>& nums, int start) {
        std::sort(cur.begin(), cur.end());
        res.push_back(cur);
        if (start >= nums.size()) { return; }
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[i-1]) continue; // avoid duplicate items
            cur.push_back(nums[i]);
            helper(res, cur, nums, i+1);
            cur.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup2(std::vector<int>& nums) { // 8 ms
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::sort(nums.begin(), nums.end());
        helper(res, cur, nums, 0);
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
              {}
//            , {1}
//            , {1,2}
//            , {1,2,3}
            , {4,1,0}
            , {1,2,2}
    };

    std::ostream_iterator<int> out(std::cout, ", ");
    for (auto& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), out);
        std::cout << std::endl;

        auto res = sol.subsetsWithDup(test);
        for (auto& val : res) {
            std::copy(val.begin(), val.end(), out);
            std::cout << std::endl;
        }
        std::cout << std::endl;

        res = sol.subsetsWithDup2(test);
        for (auto& val : res) {
            std::copy(val.begin(), val.end(), out);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}