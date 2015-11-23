//
// Created by Sisu on 11/22/2015.
//

/*
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any
 * value appears at least twice in the array, and it should return false if every element is distinct.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) { // 40 ms
        if (nums.empty()) { return false; }
        sort(nums.begin(), nums.end());
        return std::unique(nums.begin(), nums.end()) != nums.end();
    }

    bool containsDuplicate_2(std::vector<int>& nums) { // 48 ms
        if (nums.empty()) { return false; }
        std::unordered_set<int> set;
        for (const auto & item : nums) {
            if (set.find(item) != set.end()) { return true; }
            set.insert(item);
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> a = {1,2,3,4,5,6};
    std::vector<int> b = {1,2,1};

    std::cout << sol.containsDuplicate_2(a) << std::endl;
    std::cout << sol.containsDuplicate_2(b) << std::endl;

    return 0;
}