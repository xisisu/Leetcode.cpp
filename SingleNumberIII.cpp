//
// Created by xisisu on 6/2/16.
//

/*
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear
 * exactly twice. Find the two elements that appear only once.
 *
 * For example:
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 * Note:
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) { // 48 ms, 32 ms if unordered_set
        if (nums.size() < 2) { return nums; }

        std::set<int> set;
        for (auto const& val : nums) {
            if (set.count(val)) { set.erase(val); }
            else { set.insert(val); }
        }

        return std::vector<int>(set.begin(), set.end());
    }

public:
    std::vector<int> singleNumber2(std::vector<int>& nums) { // 28 ms
        if (nums.size() < 2) { return nums; }

        std::sort(nums.begin(), nums.end());
        std::vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            auto val = nums[i];
            if (i == 0) {
                if (val != nums[1]) { res.push_back(val); }
            } else if (i == nums.size()-1) {
                if (val != nums[nums.size()-2]) { res.push_back(val); }
            } else {
                if (val != nums[i-1] && val != nums[i+1]) { res.push_back(val); }
            }
        }
        return res;
    }

public:
    std::vector<int> singleNumber3(std::vector<int>& nums) { // 20 ms
        /*
         * find a single bit to divide it into two groups, each group contains 1 unique number
         */
        if (nums.size() < 2) { return nums; }

        int divide = 0;
        for (auto const& val : nums) { divide ^= val; }

        int rightMostBit = (divide & ~(divide-1));
        std::vector<int> result(2, 0);
        for (auto const& val : nums) {
            if (rightMostBit & val) { result[0] ^= val; }
            else { result[1] ^= val; }
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> test = {1,2,1,3,2,5};
    auto res = sol.singleNumber(test);
    for (auto const& val : res) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;
    return 0;
}