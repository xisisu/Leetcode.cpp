//
// Created by Sisu on 11/22/2015.
//

/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the
 * relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */

#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) { // 20 ms
        int start = 0;
        for (int cur = 0; cur < nums.size(); ++cur) {
            if (nums[cur] != 0) {
                nums[start++] = nums[cur];
            }
        }
        for (int cur = start; cur < nums.size(); ++cur) {
            nums[cur] = 0;
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {0, 1, 0, 3, 12};
    sol.moveZeroes(tests);
    for (const auto & item: tests) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
    return 0;
}