//
// Created by Sisu on 3/15/2016.
//

/*
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Solution {
/* sol 1: see Permutations.cpp, very easy to change, but would timeout */

/* sol 2: timeout */
private:
    void helper(std::vector<int>& nums, std::vector<std::vector<int>>& res, int pos) {
        if (pos >= nums.size()) { res.push_back(nums); return; }
        for (int i = pos; i < nums.size(); ++i) {
            if (i > pos && nums[i] == nums[pos]) { continue; } // skip same elements
            std::swap(nums[pos], nums[i]);
            helper(nums, res, pos+1);
            std::swap(nums[pos], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> const& nums) { // timeout
        std::vector<std::vector<int>> res;
        std::vector<int> tmp = nums;
        helper(tmp, res, 0);
        return res;
    }

/* sol 3: 28 ms */
private:
    bool next(std::vector<int> &num) { // same as finding next permutaiton
        if (num.size() <= 1) { return false; }

        int i = num.size()-2;
        while (i >= 0 && num[i] >= num[i+1]) { --i; }
        if (i < 0) { return false; }

        int j = num.size()-1;
        while (j > i && num[j] <= num[i]) { --j; }

        std::swap(num[i], num[j]);
        reverse(num.begin()+i+1, num.end());

        return true;
    }

public:
    std::vector<std::vector<int> > permuteUnique2(std::vector<int> &num) { // 28 ms
        std::vector<std::vector<int> > res;
        if (num.size() == 0) { return res; }
        sort(num.begin(), num.end()); // first use smallest number

        res.push_back(num);
        while(next(num)) { res.push_back(num); }

        return res;
    }

};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
              {}
            , {1}
            , {1,1,1,1,1,1,1,1,1}
            , {1,2}
            , {1,1,2}
    };
    std::ostream_iterator<int> out_it(std::cout, ", ");

    for (auto const& test: tests) {
        std::cout << std::endl << "inputs:";
        std::copy(test.begin(), test.end(), out_it);
        std::cout << std::endl;

        auto res = sol.permuteUnique(test);
        std::cout << "result size: " << res.size() << std::endl;
        for (auto const& val : res) {
            std::cout << "  ";
            std::copy(val.begin(), val.end(), out_it);
            std::cout << std::endl;
        }
    }

    return 0;
}