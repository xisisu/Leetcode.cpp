//
// Created by Sisu on 11/22/2015.
//

/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more
 * than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) { // 28 ms
        std::unordered_map<int, int> map;
        for (const auto & item : nums) {
            if (++map[item] > nums.size() / 2) { return item; }
        }
        return 0;
    }

    int majorityElement_2(std::vector<int>& nums) { // 40 ms
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }

    // treat all other non majority numbers as the same, then count them
    int majorityElement_3(std::vector<int>& nums) { // 16 ms
        int res = 0, count = 0;
        for (const auto & item : nums) {
            if (count == 0) { res = item; }
            if (res == item) { ++count; }
            else { --count; }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {0,0,0,0,0,0,0,1};
    std::cout << sol.majorityElement(tests) << std::endl;
    return 0;
}