//
// Created by Sisu on 11/8/2015.
//

/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) { // 12 ms
        sort(nums.begin(), nums.end());
        int min_diff = std::numeric_limits<int>::max();
        int res = 0;
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (idx > 0 && nums[idx] == nums[idx-1]) { continue; } // skip same items
            int low = idx+1, high = nums.size()-1;
            while (low < high) {
                auto val = nums[idx] + nums[low] + nums[high];
                auto diff = std::abs(target - val);
                if (diff < min_diff) { min_diff = diff; res = val; }
                if (val < target) { ++low;}
                else if (val > target) { --high;}
                else { return target;}
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 1, -1, -1, 3};
    int target = -1;
    std::cout << sol.threeSumClosest(nums, target) << std::endl;
    return 0;
}