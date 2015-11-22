//
// Created by Sisu on 11/19/2015.
//

/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) { // 12 ms
        if (nums.empty() || nums.size() == 1) { return; }
        int i = nums.size()-2;
        while (i >= 0 && nums[i] >= nums[i+1]) { --i; }
        if (i < 0) { std::reverse(nums.begin(), nums.end()); return;}

        int j = nums.size()-1;
        while (j > i && nums[j] <= nums[i]) { --j; }

        std::swap(nums[i], nums[j]);
        std::reverse(nums.begin()+i+1, nums.end());
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {3,2,1,8,7,6}; // 321876 -> 326178
    sol.nextPermutation(tests);
    for (const auto & item: tests) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::vector<int> test2 = {1,5,8,7,6,4,3}; // 1587643 -> 1634578
    sol.nextPermutation(test2);
    for (const auto & item : test2) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}