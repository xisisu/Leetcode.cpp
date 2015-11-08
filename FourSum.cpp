//
// Created by Sisu on 11/8/2015.
//

/*
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all
 * unique quadruplets in the array which gives the sum of target.
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * A solution set is:
 * (-1,  0, 0, 1)
 * (-2, -1, 1, 2)
 * (-2,  0, 0, 2)
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) { // 56 ms
        std::vector<std::vector<int>> res;
        if (nums.size() < 4) { return res; }

        sort(nums.begin(), nums.end());
        for (auto first = 0; first < nums.size(); ++first) {
            if (first > 0 && nums[first] == nums[first-1]) { continue; } // skip same items
            if (nums[first]+nums[first+1]+nums[first+2]+nums[first+3] > target) { break; }
            for (auto second = first+1; second < nums.size()-2; ++second) {
                if (second > first+1 && nums[second] == nums[second-1]) { continue; } // skip same items
                if (nums[first]+nums[second]+nums[second+1]+nums[second+2] > target) { break; } // no need to continue
                int low = second+1, high = nums.size()-1;
                while (low < high) {
                    auto val = nums[first] + nums[second] + nums[low] + nums[high];
                    if (val < target) { ++low; }
                    else if (val > target) { --high; }
                    else { // found one
                        std::vector<int> tmp = {nums[first], nums[second], nums[low], nums[high]};
                        res.push_back(tmp);
                        while (low < high && nums[low] == nums[low+1]) { ++low; }
                        while (low < high && nums[high] == nums[high-1]) { --high; }
                        ++low; --high;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    for (auto item: sol.fourSum(nums, target)) {
        for (auto val : item) {
            std::cout << val << ",";
        }
        std::cout << std::endl;
    }
    return 0;
}