//
// Created by Sisu on 3/12/2016.
//

/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it
 * would be if it were inserted in order.
 * You may assume no duplicates in the array.
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) { // 8 ms
        int N = nums.size();
        if (nums.empty()) { return 0; }
        if (nums[0] > target) { return 0; }
        if (nums[N-1] < target) { return N; }

        int low = 0, high = nums.size() -1;
        while (low <= high) {
            if (low == high) { return low; }

            int mid = low + (high-low)/2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid;
            } else {
                return mid;
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,3,5,6};
    std::vector<int> targets = {5,2,7,0,3,8};

    for (auto const& target : targets) {
        std::cout << target << ", " << sol.searchInsert(nums, target) << std::endl;
    }

    return 0;
}