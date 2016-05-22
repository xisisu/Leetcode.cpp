//
// Created by xisisu on 5/21/16.
//

/*
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to num2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into
 * the memory at once?
 */

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersect(std::vector<int> const& nums1, std::vector<int> const& nums2) { // 12 ms
        if (nums1.empty() || nums2.empty()) { return {}; }
        /*
         * sort the array, then advance them one by one
         * this will destroy the order in the result, assume it does not matter
         */
        auto val1 = nums1;
        auto val2 = nums2;
        sort(val1.begin(), val1.end());
        sort(val2.begin(), val2.end());

        std::vector<int> res;
        int idx1 = 0, idx2 = 0;
        while (idx1 < val1.size() && idx2 < val2.size()) {
            if (val1[idx1] == val2[idx2]) { res.push_back(val1[idx1]); ++idx1; ++idx2; }
            else if (val1[idx1] < val2[idx2]) { ++idx1; }
            else { ++idx2; }
        }

        return res;
    }

public:
    std::vector<int> intersect2(std::vector<int> const& nums1, std::vector<int> const& nums2) { // 16 ms
        if (nums1.empty() || nums2.empty()) { return {}; }
        if (nums1.size() > nums2.size()) { std::swap(nums1, nums2); } // always index on the smaller array
        std::map<int, int> val1;
        for (auto const& val : nums1) { ++val1[val]; }

        std::vector<int> res;
        for (auto const& val : nums2) {
            if (val1.count(val) && val1[val] > 0) {
                res.push_back(val);
                --val1[val];
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};

    auto res = sol.intersect(nums1, nums2);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    return 0;
}