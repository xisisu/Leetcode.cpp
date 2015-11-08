//
// Created by Sisu on 11/8/2015.
//

/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets
 * in the array which gives the sum of zero.
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)\
 * The solution set must not contain duplicate triplets.
 *  For example, given array S = {-1 0 1 2 -1 -4},
 *  A solution set is:
 *  (-1, 0, 1)
 *  (-1, -1, 2)
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) { // 56 ms
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        for (auto idx = 0; idx < nums.size(); ++idx) {
            if (idx > 0 && nums[idx] == nums[idx-1]) { continue; } // repeated item, skip it
            auto low = idx+1;
            auto high = nums.size() - 1;
            while (low < high) {
                auto val = nums[idx] + nums[low] + nums[high];
                if (val < 0) { ++low; }
                else if (val > 0) { --high; }
                else {
                    std::vector<int> tmp = {nums[idx], nums[low], nums[high]};
                    res.push_back(tmp);
                    while (low < high && nums[low] == nums[low+1]) { ++low; } // skip same items
                    while (low < high && nums[high] == nums[high-1]) { --high; } // skip same items
                    ++low; --high;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {-1, 0, 1, 2, -1, -4};
    auto res = sol.threeSum(tests);
    for (auto item : res) {
        for (auto val : item) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}