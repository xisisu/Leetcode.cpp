//
// Created by xisisu on 5/14/16.
//

/*
 * Note: This is an extension of House Robber.
 * After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will
 * not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house
 * is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the
 * previous street.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount
 * of money you can rob tonight without alerting the police.
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

class Solution {
private:
    int hourseRobber(std::vector<int> const& nums) {
        int include = 0, exclude = 0;
        for (int i = 0; i < nums.size(); ++i) {
            auto temp = include;
            include = exclude + nums[i];
            exclude = std::max(temp, exclude);
        }
        return std::max(include, exclude);
    }

public:
    int rob(std::vector<int> const& nums) { // 4 ms
        /*
         * there are two conditions,
         * 1) if we take [0], we choose (val[0] + nums[2...n-2])
         * 2) if we do not take [0], we choose (nums[1...n-1])
         */
        // 0. special cases

        if (nums.empty()) { return 0; }
        if (1 == nums.size()) { return nums[0]; }
        if (2 == nums.size()) { return std::max(nums[0], nums[1]); }
        if (3 == nums.size()) { return std::max(nums[0], std::max(nums[1], nums[2])); }

        // 1. take [0]
        std::vector<int> take(nums.size()-3);
        std::copy(nums.begin()+2, nums.begin() + nums.size()-1, take.begin());
        auto valTake = nums[0] + hourseRobber(take);

        // 2. non take [0]
        std::vector<int> nonTake(nums.size()-1);
        std::copy(nums.begin()+1, nums.end(), nonTake.begin());
        auto valNotTake = hourseRobber(nonTake);

        return std::max(valTake, valNotTake);
    }

};

int main() {
    Solution sol;
    std::vector<int> tests = {2,1,1,2};
    std::cout << sol.rob(tests) << std::endl;
    return 0;
}