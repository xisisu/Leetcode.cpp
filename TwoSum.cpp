//
// Created by Sisu on 11/1/2015.
//

/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) { // 24 ms
        std::map<int, int> map; // construct a map of reverse mapping between val -> index
        std::vector<int> res(2);
        for (const auto& val: nums) {
            auto idx = &val - &nums[0];
            if (map.find(target - val) != map.end()) {
                res[0] = map[target-val] + 1;
                res[1] = idx+1;
                return res;
            }
            map[val] = idx;
        }
        return res;
    }

    std::vector<int> twoSum_2(std::vector<int>& nums, int target) { //  12 ms
        std::vector<int> input = nums;
        sort(input.begin(), input.end());
        std::vector<int> res(2);
        int i = 0, j = input.size() - 1;
        while (i < j) {
            if (input[i] + input[j] == target) {
                auto idx1 = find(nums.begin(), nums.end(), input[i]);
                auto idx2 = find(idx1+1, nums.end(), input[j]);
                if (idx2 == nums.end()) {
                    idx2 = find(nums.begin(), idx1 - 1, input[j]);
                }
                res[0] = idx1 - nums.begin() + 1;
                res[1] = idx2 - nums.begin() + 1;
                sort(res.begin(), res.end());
                return res;
            } else if (input[i] + input[j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> input = {3, 2, 4};
    auto res = sol.twoSum_2(input, 6);
    for (auto item : res) {
        std::cout << item << std::endl;
    }

    return 0;
}

