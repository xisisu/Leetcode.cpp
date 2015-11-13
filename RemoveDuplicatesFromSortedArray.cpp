//
// Created by Sisu on 11/12/2015.
//

/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and
 * return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example,
 * Given input array nums = [1,1,2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>.
#include <unordered_set>
#include <limits>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) { // 32 ms
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i ==0 || nums[i] != nums[i-1]) {
                nums[res++] = nums[i];
            }
        }
        return res;
    }

    int removeDuplicates_2(std::vector<int>& nums) { // 32 ms
        return std::unique(nums.begin(), nums.end()) - nums.begin();
    }
};

int main() {
    Solution sol;
    std::vector<int> a = {1, 1, 2};
    std::cout << sol.removeDuplicates_2(a) << std::endl;
    return 0;
}