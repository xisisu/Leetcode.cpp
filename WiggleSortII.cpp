//
// Created by xisisu on 7/17/16.
//

/*
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 *
 * Example:
 * (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
 * (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
 *
 * Note:
 * You may assume all input has valid answer.
 *
 * Follow Up:
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    void wiggleSort(std::vector<int>& nums) { // 128 ms
        std::vector<int> sorted(nums);
        std::sort(sorted.begin(), sorted.end());
        int n = nums.size();
        int small = n&1 ? n/2 : n/2-1;
        int large = n-1;
        for (int i = 0; i < n; ++i) {
            nums[i] = sorted[i&1 ? large-- : small--];
        }
    }

    void wiggleSort2(std::vector<int>& nums) { // 116 ms
        /*
         * use nth_element to partial sort the nums, then find it
         */
        std::vector<int> partialSorted(nums);
        std::nth_element(partialSorted.begin(), partialSorted.begin() + partialSorted.size()/2, partialSorted.end());

        /*
         * note value equal to the median can be anywhere, so:
         * 1,3,2,2,3,1 can be 2,1,1,2,3,3. which is hard to do. the following process ensures
         * value equal to median are all in middle
         */
        int n = nums.size();
        int midVal = partialSorted[n/2];
        int left = n/2-1, right = n/2+1;
        while (partialSorted[left] == midVal) { --left; }
        while (partialSorted[right] == midVal) { ++right; }
        for (int i = 0; i < n; ++i) {
            if (partialSorted[i] != midVal || (i > left && i < right)) { continue; }
            if (i < n/2) { std::swap(partialSorted[i], partialSorted[left--]); }
            else         { std::swap(partialSorted[i], partialSorted[right++]); }
        }

        /*
         * then we can safely repeat the process before
         */
        int small = n&1 ? n/2 : n/2-1;
        int large = n-1;
        for (int i = 0; i < n; ++i) {
            nums[i] = partialSorted[i&1 ? large-- : small--];
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> number= {4,5,5,5,5,6,6,6};

    sol.wiggleSort2(number);
    for (auto const& val : number) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    return 0;
}